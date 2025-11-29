# common.mk - Shared Makefile logic for 8051 examples

# --- Prerequisite Check ---
ifeq ($(shell which sdcc),)
$(error "sdcc compiler not found in PATH. Please install it. For Debian/Ubuntu: sudo apt-get install sdcc")
endif

# --- Default Configuration ---
TARGET      ?= main
BUILD_DIR   ?= obj
SOURCES     ?= $(wildcard *.c)
OBJECTS     = $(patsubst %.c,$(BUILD_DIR)/%.rel,$(SOURCES))

# --- Compiler and Flags ---
CC     = sdcc
MCU    = mcs51
CFLAGS = -m$(MCU) --out-fmt-ihx 

# --- avrdude Configuration ---
# Assumes avrdude.conf is in the project root, one level up.
AVRDUDE_CONF ?= ../avrdude.conf
PROGRAMMER   ?= usbasp
AVRDUDE_MCU  ?= at89s52
AVRDUDE      ?= avrdude
AVRDUDE_FLAGS= -c $(PROGRAMMER) -p $(AVRDUDE_MCU) -C $(AVRDUDE_CONF)

# --- Core Rules ---

# Default target: compile the source code
all: $(BUILD_DIR)/$(TARGET).hex

# Link object files into a hex file
$(BUILD_DIR)/$(TARGET).hex: $(OBJECTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Compile a .c file into a .rel file
$(BUILD_DIR)/%.rel: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the build directory
$(BUILD_DIR):
	mkdir -p $@

# --- User Commands (for individual examples) ---

flash: all
	@echo "Flashing '$(TARGET)' with configuration: $(AVRDUDE_CONF)"
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$(BUILD_DIR)/$(TARGET).hex

build-flash: flash

size: all
	@echo "--- Memory Usage for '$(TARGET)' ---"
	@grep "Program Size" $(BUILD_DIR)/$(TARGET).map || echo "Map file not found. Build the project first."
	@echo "---------------------------------"

clean:
	@echo "Cleaning build files for '$(TARGET)'..."
	rm -rf $(BUILD_DIR)

erase:
	@echo "Erasing chip..."
	$(AVRDUDE) $(AVRDUDE_FLAGS) -e

read:
	@echo "Reading flash to $(BUILD_DIR)/readback.hex..."
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:r:$(BUILD_DIR)/readback.hex:i

# Phony targets
.PHONY: all flash build-flash clean size erase read
