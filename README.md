# WajaPhysics

A physics exercise solver written in **C**, designed to calculate and solve basic kinematics problems.

This is a personal programming project created to put physics knowledge into practice while learning C programming.

## Features

### MRU (Uniform Rectilinear Motion)
- Position calculations.
- Motion-related exercise solving.

### MRUA (Uniformly Accelerated Rectilinear Motion)
- Position calculations.
- Motion-related exercise solving.

### Mixed MRU + MRUA
- Solving encounter problems between two objects.
- Calculating the time at which two objects meet.
- Calculating the position where two objects meet.
- Handling quadratic equations through their discriminant:
  - Two real solutions.
  - One real solution (double root).
  - No real solutions.
- Handling special cases where acceleration is zero.

## Technologies

- **Language:** C
- **Compiler:** GCC
- **Libraries:** `stdio.h`, `stdlib.h`, `math.h`, `windows.h`

## Running the project

The project is currently designed for Windows.

Compile using GCC:

```bash
gcc main.c -o WajaPhysics.exe -lm
```

Then run:

```bash
WajaPhysics.exe
```

## Project status

<ins>Currently in development.</ins>

The main calculation systems are implemented and are being tested and improved.

## About

WajaPhysics is a learning project focused on understanding how mathematical and physical equations can be translated into programming logic.

The goal is not just to obtain the correct result, but to understand how the program reaches it.

**Made by Wajatone.**
