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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
#PLATFORM = 

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds

# Specifies the target ARM Cortex Architecture
CPU = cortex-m0plus

# Specifies the instructions set architecture. For ARM processor, there are two main instructions sets - ARM and Thumb
ARCH = thumb

# Specifies the specs file to give to the linker. "nosys.specs" means that the standard I/O syscalls are not provided by the system.
SPECS = nosys.specs 

# Compiler Flags and Defines
# CC - Compiler that will perform the build (Native or Cross)
CC = arm-none-eabi-gcc

# LD - Specifies the linker to be used 
LD = arm-none-eabi-ld

# TARGET - Specifies the target name for the final executable
TARGET = c1m2

# LDFLAGS - Linker Flags
# Map file generation: -Wl,-Map=$(TARGET).map 
# Linker file: -T $(LINKER_FILE)
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)

# CFLAGS - C-programming flags for gcc
# Specifies compilation flags, including the CPU and ARCH settings, specs file, and enabling all compiler warnings with -Wall
CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall

# CPPFLAGS - C-Preprocessor Flags
# For now, they won't be declared 
CPPFLAGs = 

# Defines a list of object files based on source files. It uses substitution to replace .c with .o in source file names.
OBJS = $(SOURCES:.c=.o)

# Pattern rule that specifies how to compile C source files into object files. It uses the CC variable, along with CFLAGS.
%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@


# Phony targets are used to define tasks that need to be performed but don't result in the creation of a corresponding output file.
# Phony target that calls the "all" target
.PHONY: build
build: all

# Phony target that depends on the $(TARGET).out target
.PHONY: all
all: $(TARGET).out

# The final executable target depends on object files. Links the object files using the CC compiler and includes necessary flags (CFLAGS and LDFLAGS).
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

# Phony target to remove generated files (*.o, $(TARGET).out, $(TARGET).map).
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map