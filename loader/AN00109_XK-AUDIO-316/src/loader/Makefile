TARGET = xk-audio-316-mc.xn
SOURCE  = loader.xc
OBJS    = loader.o
OUT     = 
CC      = xcc
CFLAGS  = -c -Wall -march=xs3a
LFLAGS  = -lflash 

all: $(OBJS)

loader.o: loader.xc
	$(CC) $(TARGET) $(FLAGS) loader.xc -o $(OBJS)
	
$(OUT):loader.o
	$(CC) loader.o $(TARGET) $(LFLAGS) -o $(OUT) 
	
clean:
	rm -f $(OBJS) $(OUT)
	
XMOS_MAKE_PATH ?= ../..
ifneq ($(wildcard $(XMOS_MAKE_PATH)/xcommon/module_xcommon/build/Makefile.common),)
include $(XMOS_MAKE_PATH)/xcommon/module_xcommon/build/Makefile.common
else
include ../module_xcommon/build/Makefile.common
endif


	
