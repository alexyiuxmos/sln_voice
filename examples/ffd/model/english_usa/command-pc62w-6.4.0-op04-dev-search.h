/* Speech Recognition Grammar Vocabulary Description file
 * Copyright (C) 2003-2024 Sensory, Inc. All Rights Reserved.
 * 
 *
 *            source: ./tmp/5kk61wPgPfXamsIkZ4PSOrnLT4K3/2913380371/trecs-en_US_12-13-6-0_57e63b3091a233f736c61f9b06633bbc57a254f6.snsr
 *           created: Sun Nov 24 15:14:18 2024
 *   min lib version: 6.4.0
 *   operating point: 4
 *  production ready: NO - development only
 *       license key: yes
 * recognition limit: 107
 *    duration limit: 11.43 hours
 *
 * Created by VoiceHub 2.11.3
 * Project: OSD_command
 *
 * This model will stop working after a preset number of recognition events
 * and/or a after a preset number of audio "bricks" have been processed.
 *
 * ------------------------- DO NOT USE IN A PRODUCT -------------------------
 */

extern const unsigned short gs_command_grammarLabel[];
#ifndef NETLABEL
#define NETLABEL
extern const unsigned short dnn_command_netLabel[];
#endif

/* The following phrases (Hex format) correspond to the word IDs emitted by the recognizer. */
#define COMMAND_PHRASE_COUNT 18
#define COMMAND_PHRASE_0 "SILENCE"	/* Legacy system phrase */
#define COMMAND_PHRASE_1 "\x69\x6E\x63\x72\x65\x61\x73\x65\x5F\x62\x72\x69\x67\x68\x74\x6E\x65\x73\x73"	/* Phrase: increase_brightness */
#define COMMAND_PHRASE_2 "\x64\x65\x63\x72\x65\x61\x73\x65\x5F\x62\x72\x69\x67\x68\x74\x6E\x65\x73\x73"	/* Phrase: decrease_brightness */
#define COMMAND_PHRASE_3 "\x69\x6E\x63\x72\x65\x61\x73\x65\x5F\x63\x6F\x6E\x74\x72\x61\x73\x74"	/* Phrase: increase_contrast */
#define COMMAND_PHRASE_4 "\x64\x65\x63\x72\x65\x61\x73\x65\x5F\x63\x6F\x6E\x74\x72\x61\x73\x74"	/* Phrase: decrease_contrast */
#define COMMAND_PHRASE_5 "\x70\x72\x65\x73\x65\x74\x5F\x72\x65\x61\x64\x69\x6E\x67"	/* Phrase: preset_reading */
#define COMMAND_PHRASE_6 "\x70\x72\x65\x73\x65\x74\x5F\x67\x61\x6D\x69\x6E\x67"	/* Phrase: preset_gaming */
#define COMMAND_PHRASE_7 "\x70\x72\x65\x73\x65\x74\x5F\x63\x69\x6E\x65\x6D\x61"	/* Phrase: preset_cinema */
#define COMMAND_PHRASE_8 "\x70\x72\x65\x73\x65\x74\x5F\x64\x65\x66\x61\x75\x6C\x74"	/* Phrase: preset_default */
#define COMMAND_PHRASE_9 "\x63\x79\x63\x6C\x65\x5F\x63\x6F\x6C\x6F\x72\x5F\x70\x72\x6F\x66\x69\x6C\x65"	/* Phrase: cycle_color_profile */
#define COMMAND_PHRASE_10 "\x63\x79\x63\x6C\x65\x5F\x69\x6E\x70\x75\x74\x5F\x73\x6F\x75\x72\x63\x65"	/* Phrase: cycle_input_source */
#define COMMAND_PHRASE_11 "\x73\x6E\x6F\x6F\x7A\x65"	/* Phrase: snooze */
#define COMMAND_PHRASE_12 "\x69\x6E\x63\x72\x65\x61\x73\x65\x5F\x6F\x6E\x5F\x74\x69\x6D\x65"	/* Phrase: increase_on_time */
#define COMMAND_PHRASE_13 "\x64\x65\x63\x72\x65\x61\x73\x65\x5F\x6F\x6E\x5F\x74\x69\x6D\x65"	/* Phrase: decrease_on_time */
#define COMMAND_PHRASE_14 "\x70\x6F\x77\x65\x72\x5F\x6F\x6E"	/* Phrase: power_on */
#define COMMAND_PHRASE_15 "\x70\x6F\x77\x65\x72\x5F\x6F\x66\x66"	/* Phrase: power_off */
#define COMMAND_PHRASE_16 "\x68\x65\x79\x5F\x63\x6F\x6D\x70\x75\x74\x65\x72"	/* Phrase: hey_computer */
#define COMMAND_PHRASE_17 "nota"	/* Legacy system phrase */
