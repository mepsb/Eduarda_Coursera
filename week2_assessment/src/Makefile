#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for the cortex-M4 build system
#
# Use: make [TARGET] [OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Overrides:
#      CPU - ARM Cortex Architecture (cortex-m4)
#      ARCH - ARM Architecture (thumb)
#      SPECS - Specs file to give the linker (nosys.specs)
#
#
#------------------------------------------------------------------------------

include sources.mk

# Include directories
INCLUDES = -I../include/msp432 -I../include/CMSIS -I../include/common

# General Flags
GENERAL_FLAGS = -Wall -Werror -g -O0 -std=c99

# Platform Specific Flags
ifeq ($(PLATFORM),MSP432)
    CC = arm-none-eabi-gcc
    PLATFORM_FLAGS = -DMSP432
    LINKER_FILE = ../msp432p401r.lds
    LDFLAGS += -T $(LINKER_FILE)
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs 
    ARCH_FLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS)
else ifeq ($(PLATFORM),HOST)
    CC = gcc
    PLATFORM_FLAGS = -DHOST
    ARCH_FLAGS =
endif

# TARGET - Specifies the target name for the final executable
TARGET = c1m2

# Combine all flags
CFLAGS += $(INCLUDES) $(GENERAL_FLAGS) $(ARCH_FLAGS)
CFLAGS += $(PLATFORM_FLAGS)

# Object files
OBJS = $(SOURCES:.c=.o)

# Phony targets are used to define tasks that need to be performed but don't result in the creation of a corresponding output file.
# Phony target that calls the "all" target
.PHONY: build
build: all

# Phony target that depends on the $(TARGET).out target
.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)


%.o : %.c
	$(CC) -c $< $(CFLAGS) -MMD -MP -I../include/ -o $@

# Generate the preprocessed output of all c-program implementation files
%.i : %.c
	$(CC) -E $< $(CFLAGS) -MMD -MP -I../include/ -o $@

# Generate assembly output of c-program implementation files and the final output executable
%.asm : %.c $(TARGET).out
	$(CC) -S $< $(CFLAGS) -MMD -MP -I../include/ -o $@
	objdump -d $(TARGET).out >> $@

# Generate the object file for all c-source files (but do not link)
%.o : %.c
	$(CC) -c $< $(CFLAGS) -MMD -MP -I../include/ -o $@
	
# Compile all object files, but DO NOT link
.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(OBJS:.o=.d) *.i *.asm

.PHONY: run
run: $(TARGET).out
	./$(TARGET).out
