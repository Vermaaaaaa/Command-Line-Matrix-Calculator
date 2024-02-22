# Command Line Matrix Calculator

This project is a command line-based matrix calculator implemented in C++. It allows users to define matrices, perform basic matrix operations such as addition, subtraction, multiplication, and calculate the determinant of a square matrix. The project is split into three separate files, each contributed by different collaborators:

- `matrix.h` and `matrix.cpp`: Contains the implementation of the `Matrix` class, which represents a mathematical matrix. This class includes functionalities for matrix creation, element access, size retrieval, display, and various matrix operations.

- `back.h` and `back.cpp`: Implements additional functionalities for parsing user input, checking the validity of numbers, parsing matrices from user input, managing a collection of matrices using a hash map, and displaying matrices.

- `main.cpp`: Contains the main menu interface and logic for interacting with users, including options to define matrices, display existing matrices, and perform matrix operations.

## Usage

To use the matrix calculator, compile the source files and run the executable. Upon running the program, you will be presented with a main menu with the following options:

1. **Define Matrix**: Allows you to define a new matrix by specifying its dimensions and entering its elements.

2. **Display Matrices**: Displays all matrices currently stored in the calculator.

3. **Add Matrices**: Performs addition operation on two matrices selected from the stored matrices.

4. **Subtract Matrices**: Performs subtraction operation on two matrices selected from the stored matrices.

5. **Multiply Matrices**: Performs multiplication operation on two matrices selected from the stored matrices.

6. **Calculate Determinant**: Calculates the determinant of a square matrix selected from the stored matrices.

7. **Exit**: Exits the program.

## Collaborators

- Will: Implemented matrix multiplication functionality.
- Angus: Contributed addition and subtraction functionalities.
- [Your Name]: Developed the main menu interface, matrix definition, and other functionalities.

## Dependencies

- C++11 or later
- Standard Template Library (STL)

## How to Build

Compile the source files using a C++ compiler. For example:

```bash
g++ main.cpp matrix.cpp back.cpp -o matrix_calculator
