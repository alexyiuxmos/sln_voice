// Copyright (c) 2022 XMOS LIMITED. This Software is subject to the terms of the
// XMOS Public License: Version 1

/* STD headers */
#include <platform.h>
#include <xs1.h>

/* FreeRTOS headers */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* App headers */
#include "app_conf.h"
#include "platform/driver_instances.h"
#include "intent_handler/intent_handler.h"
#include "audio_response.h"
#include "fs_support.h"
#include "ff.h"
#include "dr_wav_freertos_port.h"

static const char *audio_files_en[] = {
    "50.wav",   /* sleep */
    "100.wav",  /* wakeup */
    "200.wav",  /* tv_on */
    "210.wav",  /* tv_off */
    "220.wav",  /* ch_up */
    "230.wav",  /* ch_down */
    "240.wav",  /* vol_up */
    "250.wav",  /* vol_down */
    "300.wav",  /* lights_on */
    "310.wav",  /* lights_off */
    "320.wav",  /* lights_up*/
    "330.wav",  /* lights_down */
    "400.wav",  /* fan_on */
    "410.wav",  /* fan_off */
    "420.wav",  /* fan_up */
    "430.wav",  /* fan_down */
    "440.wav",  /* temp_up */
    "450.wav",  /* temp_down */
};

#define NUM_FILES (sizeof(audio_files_en) / sizeof(audio_files_en[0]))

static int32_t file_audio[appconfAUDIO_PIPELINE_FRAME_ADVANCE * sizeof(int32_t)];
static int32_t i2s_audio[2*(appconfAUDIO_PIPELINE_FRAME_ADVANCE * sizeof(int32_t))];
static drwav *wav_files = NULL;

int32_t audio_response_init(void) {
    FRESULT result = 0;
    FIL *files = pvPortMalloc(NUM_FILES * sizeof(FIL));
    wav_files = pvPortMalloc(NUM_FILES * sizeof(drwav));

    configASSERT(files);
    configASSERT(wav_files);
    configASSERT(file_audio);
    configASSERT(i2s_audio);

    for (int i=0; i<NUM_FILES; i++) {
        result = f_open(&files[i], audio_files_en[i], FA_READ);
        if (result == FR_OK) {
            drwav_init(
                    &wav_files[i],
                    drwav_read_proc_port,
                    drwav_seek_proc_port,
                    &files[i],
                    &drwav_memory_cbs);
        } else {
            configASSERT(0);
        }
    }
    return 0;
}

void audio_response_play(int32_t id) {
    drwav tmp;
    size_t framesRead = 0;

    if (wav_files != NULL) {
        switch(id) {
            case 50: /* sleep */
                tmp = wav_files[0];
                break;
            case 100: /* wakeup */
            case 110: /* wakeup */
                tmp = wav_files[1];
                break;
            case 200: /* tv_on */
                tmp = wav_files[2];
                break;
            case 210: /* tv_off */
                tmp = wav_files[3];
                break;
            case 220: /* ch_up */
                tmp = wav_files[4];
                break;
            case 230: /* ch_down */
                tmp = wav_files[5];
                break;
            case 240: /* vol_up */
                tmp = wav_files[6];
                break;
            case 250: /* vol_down */
                tmp = wav_files[7];
                break;
            case 300: /* lights_on */
                tmp = wav_files[8];
                break;
            case 310: /* lights_off */
                tmp = wav_files[9];
                break;
            case 320: /* lights_up */
                tmp = wav_files[10];
                break;
            case 330: /* lights_down */
                tmp = wav_files[11];
                break;
            case 400: /* fan_on */
                tmp = wav_files[12];
                break;
            case 410: /* fan_off */
                tmp = wav_files[13];
                break;
            case 420: /* fan_up */
                tmp = wav_files[14];
                break;
            case 430: /* fan_down */
                tmp = wav_files[15];
                break;
            case 440: /* temp_up */
                tmp = wav_files[16];
                break;
            case 450: /* temp_down */
                tmp = wav_files[17];
                break;
            default:
                rtos_printf("No audio response for id %d\n", id);
                break;
        }

        while(1) {
            memset(file_audio, 0x00, sizeof(file_audio));
            framesRead = drwav_read_pcm_frames(&tmp, appconfAUDIO_PIPELINE_FRAME_ADVANCE, file_audio);
            memset(i2s_audio, 0x00, sizeof(i2s_audio));
            for (int i=0; i<framesRead; i++) {
                i2s_audio[(2*i)+0] = file_audio[i];
                i2s_audio[(2*i)+1] = file_audio[i];
            }

            rtos_i2s_tx(i2s_ctx,
                        (int32_t*) i2s_audio,
                        appconfAUDIO_PIPELINE_FRAME_ADVANCE,
                        portMAX_DELAY);

            if (framesRead != appconfAUDIO_PIPELINE_FRAME_ADVANCE) {
                drwav_seek_to_pcm_frame(&tmp, 0);
                break;
            }
        }
    } else {
        rtos_printf("wav files not initialized\n");
    }
}
