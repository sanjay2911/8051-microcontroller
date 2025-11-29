# Root Makefile for 8051 multi-example project

# Find all subdirectories that contain a Makefile; these are considered our examples.
# The 'wildcard' finds the Makefiles, and 'dir' extracts the directory part.
EXAMPLES := $(dir $(wildcard */Makefile))

# --- Primary Targets ---

# Default target: build all examples
all:
	@echo "Building all examples..."
	@$(foreach example,$(EXAMPLES), $(MAKE) -C $(example) all;)
	@echo "All examples built."

# Clean all example build directories
clean:
	@echo "Cleaning all example build directories..."
	@$(foreach example,$(EXAMPLES), $(MAKE) -C $(example) clean;)
	@echo "All examples cleaned."

# --- Convenience Targets ---
# These allow running commands for a specific example from the root.
# Usage: make flash EXAMPLE=blink

# List of targets that require the EXAMPLE variable
EXAMPLE_TARGETS = flash build-flash erase read lock

# A generic rule to handle these targets
$(EXAMPLE_TARGETS):
ifndef EXAMPLE
	$(error "Usage: make $@ EXAMPLE=<example_name>")
endif
	@$(MAKE) -C $(EXAMPLE) $@

# Phony targets
.PHONY: all clean $(EXAMPLE_TARGETS)
