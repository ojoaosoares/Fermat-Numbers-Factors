# Fermat-Numbers-Factors

## Introduction

This project performs primality tests on Fermat numbers, defined as:

$$
F_n = 2^{(2^n)} - 1
$$

The program offers two modes of operation. The first one provides a primality test. In case the Fermat number is composite, the smallest prime factor is printed. In the second mode, we look for Fermat numbers that are divisible by $\textit{q}$, given integers $\textit{k}$ and $\textit{l}$:

$$
q = k \cdot 2^l + 1
$$

## Features

- **Euler Method**: Efficiently finds the smallest prime factor of Fermat numbers. This method is used in the primality test.
- **Finding Fermat Numbers**: Since <em>k · 2<sup>l</sup> + 1</em> can be a divisor of any Fermat number <em>F<sub>n</sub></em> with n < l, we search for all Fermat numbers that could potentially be divisible by it.
- **Optional Output**: Supports a flag to print the corresponding Fermat number and Fermat factor.

## Prerequisites

### Compiler
- **C++ Compiler** (e.g., `g++`)

### Dependencies
- **GMP Library** (GNU Multiple Precision Arithmetic Library)
- **Installation Script** Run install.sh to install dependencies automatically

## How to Compile and Run

### Using Makefile

The project includes a `Makefile` to simplify the compilation process. Below are the available commands:

1. **Compile the Program**:  
To compile the program, run:
```bash
make
```

This will generate the executable in the ./bin/ folder.

2. **Clean Build Files**:
To remove all compiled object files and the executable, run:

```bash
make clean
```

### Execution

After compiling, run the program using:
```bash
./bin/fermat_pf_test -m [MODE] -i [FERMAT INDEX] -k [k] -l [l] -n
```

where

- **-m [Mode]**: Mode to use the program:
  - `p` for primality test.
  - `f` for looking for Fermat Numbers with a specific factor.
  (Primality method is the default).
- **-i [FERMAT INDEX]**: Index of the Fermat number to be tested.
- **-k [k]**: the k on the specific factor \( k \cdot 2^l + 1 \).
- **-l [l]**: the l on the specific factor \( k \cdot 2^l + 1 \).
- **-n**: Optional flag to print the corresponding Mersenne number.

## Program Output

- If the primality mode is selected, it will run the Euler method to find the smallest prime factor and output whether <em>F<sub>n</sub></em>​ is prime.
- If the find fermat numbers with a specific factor mode is selected, it will run and output all Fermat numbers that has a factor \( k \cdot 2^l + 1 \). 
