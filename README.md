# 42sh

Welcome to 42sh - a Unix shell implemented in C, designed to mimic the functionality of the tcsh shell. This project is part of the B2 level of the Unix System and Programming course at PSU.

## Project Details
- Project Name: 42sh
- Binary Name: 42sh
- Language: C
- Compilation: Via Makefile, including re, clean, and fclean rules

## Builtins
- cd [directory]
- echo [str...]
- exit [n]
- env
- setenv [name] [value]
- unsetenv
- unset [-fv] name...
- history
- ![n | str]

## Features
- Execution of commands with their parameters and PATH management.
- Management of errors and the return value of commands.
- The following redirects: ">", "<<", ">>", "<".
- Pipes “|”.
- The logical operators "&&" and "||".
- The ";" separator.
- ctrl+D
- ctrl+C

## Bonuses
- The "<<" heredoc.
- Colours.
- Variables.
- Aliases.
- History.

## Usage
The program must be compiled with the provided Makefile or use CMake. Make sure to include all necessary source files, excluding unnecessary files like binaries, temporary files, or object files. After compiling the program can be executed using `./42sh` with no extra arguments.
