# 8051 Microcontroller Examples

A modern collection of practical **8051 microcontroller examples** built with **SDCC (Small Device C Compiler)** and **CMake**.

This repository provides well-documented firmware examples for the **AT89S52** microcontroller and serves as a learning resource for students, hobbyists, and embedded engineers interested in classic 8051 development using a modern build system.

---

## Features

* SDCC-based toolchain
* Modern CMake build system
* Build all applications or individual examples
* Automatic flash targets
* Modular project structure
* Beginner-friendly examples
* Bare-metal embedded development
* Portable build workflow
* Open-source and community-driven

---

## Why This Repository?

Most 8051 tutorials are outdated and rely on IDE-specific workflows.

This project demonstrates how to develop 8051 firmware using:

* SDCC
* CMake
* Command-line workflows
* Version control best practices
* Reusable project structure

making it easier to integrate 8051 development into modern software engineering practices.

---

## Supported MCU

* Atmel AT89S52

Additional 8051-compatible devices may be supported in the future.

---

## Available Examples

| Example           | Description                                       |
| ----------------- | ------------------------------------------------- |
| blink             | Basic GPIO LED blinking                           |
| button            | Digital input and button handling                 |
| ext-int           | External interrupt handling                       |
| frequency-counter | Frequency measurement using timers and interrupts |
| led-pattern       | LED sequencing and pattern generation             |
| pwm-fade          | Software PWM LED brightness control               |
| timer-delay       | Delay generation using hardware timers            |
| timer-interrupt   | Timer interrupt usage                             |
| uart-echo         | UART receive and echo example                     |
| uart-hello        | UART transmission example                         |

Each example is self-contained and includes its own source code, CMake configuration, and documentation.

---

## Repository Structure

```text
.
├── apps/
│   ├── blink/
│   ├── button/
│   ├── ext-int/
│   ├── frequency-counter/
│   ├── led-pattern/
│   ├── pwm-fade/
│   ├── timer-delay/
│   ├── timer-interrupt/
│   ├── uart-echo/
│   └── uart-hello/
│
├── config/
│   ├── avrdude.conf
│   ├── common.cmake
│   └── sdcc-toolchain.cmake
│
├── CMakeLists.txt
└── README.md
```

---

## Learning Path

If you're new to embedded systems, follow this order:

1. blink
2. button
3. led-pattern
4. timer-delay
5. timer-interrupt
6. ext-int
7. uart-hello
8. uart-echo
9. pwm-fade
10. frequency-counter

---

## Requirements

Install the following tools before building:

* CMake (3.20 or newer recommended)
* SDCC (Small Device C Compiler)
* Ninja or GNU Make
* AVRDUDE

Verify installation:

```bash
cmake --version
sdcc --version
avrdude -?
```

---

## Building All Applications

Configure:

```bash
cmake -B build
```

Build:

```bash
cmake --build build
```

Generated HEX files are placed in:

```text
build/out/
```

Example:

```text
build/out/blink.hex
build/out/button.hex
build/out/ext-int.hex
build/out/frequency-counter.hex
build/out/led-pattern.hex
build/out/pwm-fade.hex
build/out/timer-delay.hex
build/out/timer-interrupt.hex
build/out/uart-echo.hex
build/out/uart-hello.hex
```

---

## Building Individual Applications

Examples:

```bash
cmake --build build --target blink
```

```bash
cmake --build build --target uart-hello
```

```bash
cmake --build build --target timer-interrupt
```

---

## Building from an Application Directory

Example:

```bash
cd apps/blink

cmake -B build
cmake --build build
```

This builds only the selected application.

---

## Flashing Firmware

Flash targets are automatically generated.

Examples:

```bash
cmake --build build --target flash-blink
```

```bash
cmake --build build --target flash-button
```

```bash
cmake --build build --target flash-uart-hello
```

```bash
cmake --build build --target flash-frequency-counter
```

When a new application is added under `apps/`, the corresponding flash target is created automatically.

---

## Cleaning

Remove generated artifacts:

```bash
cmake --build build --target clean
```

Full cleanup:

```bash
rm -rf build
cmake -B build
```

---

## Hardware

Target MCU:

**AT89S52**

Programming configuration:

```text
config/avrdude.conf
```

Programmer support depends on the programmer configuration specified in AVRDUDE.

---

## Roadmap

* [x] GPIO Examples
* [x] UART Examples
* [x] Interrupt Examples
* [x] Timer Examples
* [x] PWM Examples
* [x] Frequency Counter

Planned:

* [ ] LCD 16x2
* [ ] Keypad Interface
* [ ] EEPROM Interface
* [ ] RTC Interface
* [ ] I2C Driver
* [ ] SPI Driver
* [ ] 7-Segment Display
* [ ] Software Bootloader
* [ ] Embedded CLI Shell
* [ ] Sensor Examples

---

## Contributing

Contributions are welcome.

Ways to contribute:

* Add new examples
* Improve documentation
* Report bugs
* Improve build scripts
* Add support for additional 8051 variants

For major changes, please open an issue first to discuss the proposed modifications.

---

## Reporting Issues

Found a bug?

Please create an issue and include:

* MCU variant
* SDCC version
* Host operating system
* Build output
* Steps to reproduce

Issue reports help improve the project for everyone.

---

## Professional Support

Need assistance with:

* 8051 firmware development
* Embedded systems consulting
* SDCC-based projects
* Custom board bring-up
* Driver development
* Build system integration
* Embedded Linux and MCU integration

Feel free to reach out for consulting and custom development opportunities.

---

## Contact

**Name:** Rechard

**Email:** [sdjinjala@gmail.com](mailto:sdjinjala@gmail.com)

**LinkedIn:** https://www.linkedin.com/in/sanjayjinjala

**GitHub:** https://github.com/sanjay2911

---

## License

This project is released under the MIT License.

See the LICENSE file for details.

---

## Keywords

8051, AT89S52, SDCC, Embedded Systems, Firmware Development, Microcontroller Programming, Bare Metal C, Embedded C, AVRDUDE, CMake, Embedded Examples, 8051 Tutorials, 8051 Examples, Electronics, MCU Development
