# 8051 Microcontroller Examples

A collection of example applications for the **8051 microcontroller** built with the **SDCC (Small Device C Compiler)** toolchain and managed using **CMake**.

The repository demonstrates common embedded programming concepts on the **AT89S52** microcontroller. Each application is self-contained and includes its own README with implementation details and usage notes.

---

## Features

* SDCC-based toolchain
* Modern CMake build system
* Build all applications or individual applications
* Automatic flash targets for every application
* Portable build workflow using standard CMake commands

---

## Repository Structure

```text
.
├── apps/
│   ├── blink/
│   ├── led-pattern/
│   ├── pwm-fade/
│   └── uart-hello/
├── config/
│   ├── avrdude.conf
│   ├── common.cmake
│   └── sdcc-toolchain.cmake
├── CMakeLists.txt
└── README.md
```

Each application resides inside the `apps/` directory and contains its own source code, headers, CMake configuration, and documentation.

---

## Requirements

The following tools must be installed before building the project:

* CMake (3.20 or newer recommended)
* SDCC (Small Device C Compiler)
* A CMake-supported build tool (Ninja, GNU Make, etc.)
* AVRDUDE

---

## Building All Applications

Configure the project:

```bash
cmake -B build
```

Build all applications:

```bash
cmake --build build
```

Generated HEX files are placed in:

```text
build/out/
```

Example output:

```text
build/out/blink.hex
build/out/led-pattern.hex
build/out/pwm-fade.hex
build/out/uart-hello.hex
```

---

## Building a Single Application

Individual applications can be built from the root build directory.

Examples:

```bash
cmake --build build --target blink
```

```bash
cmake --build build --target uart-hello
```

---

## Building from an Application Directory

Each application can also be configured and built independently.

Example:

```bash
cd apps/blink

cmake -B build
cmake --build build
```

This builds only the selected application.

---

## Flashing Firmware

A flash target is automatically generated for every application.

Examples:

```bash
cmake --build build --target flash-blink
```

```bash
cmake --build build --target flash-led-pattern
```

```bash
cmake --build build --target flash-pwm-fade
```

```bash
cmake --build build --target flash-uart-hello
```

When a new application is added under `apps/`, the corresponding flash target is generated automatically.

---

## Cleaning

Remove generated build artifacts:

```bash
cmake --build build --target clean
```

To completely regenerate the build system, remove the build directory and configure again:

```bash
rm -rf build
cmake -B build
```

---

## Hardware

Target MCU:

* **Atmel AT89S52**

Programming is performed using **AVRDUDE** and the configuration provided in:

```text
config/avrdude.conf
```

---

## Applications

Each application contains its own README with detailed information about:

* Hardware connections
* Example behavior
* Configuration options
* Implementation details
* Usage instructions

Refer to the documentation within the corresponding application directory for additional information.
