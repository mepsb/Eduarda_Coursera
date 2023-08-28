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

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out

.PHONY: run
run: $(TARGET).out
	./$(TARGET).out
