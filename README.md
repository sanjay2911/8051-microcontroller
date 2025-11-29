# 8051 Microcontroller Examples

This project contains a collection of code examples for the 8051 microcontroller, compiled with the SDCC compiler.

## Project Structure

The project is organized into individual example directories, each containing its own source code and a README file with specific details.

- `blink/`: A simple example to blink a single LED.
- `led-pattern/`: A more advanced example demonstrating several patterns on 8 LEDs.

## Development Environment

This project is developed and tested on a **Linux-based operating system**. The `Makefile` and shell commands are tailored for a Unix-like environment.

**Required Tools:**
- `make`
- `sdcc` (Small Device C Compiler)
- `avrdude`

The build system includes a check for `sdcc` and provides installation instructions for Debian/Ubuntu-based distributions.

## Build System

This project uses a hierarchical build system powered by `make`. You can either build all examples at once from the root directory, or manage each example individually from its own subdirectory.

### How to Use

#### From the Root Directory

-   **Build All Examples:**
    ```sh
    make all
    ```
-   **Clean All Examples:**
    ```sh
    make clean
    ```
-   **Flash a Specific Example:** You must provide the `EXAMPLE` variable.
    ```sh
    make flash EXAMPLE=blink
    make flash EXAMPLE=led-pattern
    ```

#### From an Example Directory

You can also `cd` into an example's directory and run commands that apply only to that example.

```sh
cd blink
make all          # Build just the blink example
make flash        # Flash just the blink example
make clean        # Clean just the blink example
```

## Hardware

All examples are configured to use **Port 2 (P2)** of the 8051 microcontroller for output.
