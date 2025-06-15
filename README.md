<!-- Project Title and Description -->
<h1 align="center">42 - Minishell ⌨️</h1>

<p align="center">
This project aims to build a basic command-line shell. The shell processes user input, executes commands, handles file redirection, and manages pipes. Minishell is a great tool for understanding how a shell works by implementing core shell functionalities.
</p>

<!-- Project Logo or Image -->
<p align="center">
  <a target="blank"><img src="https://github.com/deryaxacar/42-Minishell/blob/main/minishell.png" height="150" width="150" /></a>
</p>

## Project Goal 🎯

The goal of the Minishell project is to create a simple UNIX-like shell. It involves handling user input, parsing and executing commands, implementing file redirection and pipe operations. This project provides in-depth knowledge on system calls, memory management, and string manipulation in the C programming language.

## Usage Scenarios 🖥️

Minishell operates similarly to a standard shell and supports various functionalities. Here are some usage examples:

- **Command Execution**: Type simple commands and press Enter.
  - Example: `ls -l`
- **File Redirection**: Use '>' or '>>' to redirect output to a file, and '<' to read input from a file.
  - Example: `echo "Hello World" > output.txt`
- **Pipe Operations**: Use '|' to pass the output of one command as input to another.
  - Example: `ls -l | grep minishell`
- **Check Command Result**: `$?` returns the exit status of the last executed command.
  - Example: `ls -l; echo $?` (Checks if the last command succeeded.)
- **Background Processes**: Use '&' to run a command in the background.
  - Example: `./script.sh &`

## Requirements 📋

To build and run the Minishell project, the following requirements must be met:

- **A Unix-based operating system** (Linux, macOS) or a terminal emulator.
- **GCC compiler**: The project should be compiled with the GNU C Compiler.
- **Bash or a similar shell**: For testing and executing commands.
- **C libraries**: Access to standard C libraries and system calls is required.
- **Make utility**: A Makefile is used to build and manage the project.

## Project Structure 📁

In addition to the main shell functionality, the project includes various helper functions and structures. Key components include:

- **Makefile**: Used to compile and build the project.
- **minishell.h**: Header file containing structure definitions and function prototypes.
- **minishell.c**: Contains the core shell logic.
- **executor.c**: Handles command execution and redirection operations.
- **parser.c**: Parses user input and processes commands.
- **signals.c**: Manages signal handling and control logic.
- **utils.c**: Includes helper functions for string manipulation and memory management.

## Contributing and Feedback 🤝

If you'd like to contribute or provide feedback:

1. Fork the repository.
2. Make your changes and submit a pull request.
3. Open an issue on GitHub or join the discussion for suggestions and improvements.

## License 📜

This project is licensed under the MIT License. You are free to use, modify, and distribute the code. For detailed license terms, please refer to the `LICENSE` file.

---

<p align="center">2025 This project was created by Derya ACAR.</p>

