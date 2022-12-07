
# holbertonschool-simple_shell

### A brief description of our SHELL functions

- **AUTHORS** : to find the Github and the Email of all contributors.
- **main.h** : the lists of all Macros, librairies and prototypes.
- **shell.c** The main fonction, to recieve input from CLI parse and execute it.
- **environ.c** : There are functions **1)** to change directory, **2)** to change or add environment variables, **3)** to delete an environment variable, **4)** to print our environment and a function to exit built in.
- **executor.c** : There is a function **1)** to fork process and replace the child with a new program, and a function **2)** to choose from an array of builtin functions.
- **func_help.c** : There is functions created and used to help us. There are functions **1)** to concatenate two strings and **2)** to reallocate a memory block.
- **tokenizer.c** : We find functions to manage tokens. There are funtions **1)** to split the input string into a array of arguments (tokens), **2)** to split the environment variable PATH into an array of tokens, **3)** to validate if PATH exists and to validate spaces, tabs and line breaks.

### What does our SHELL function do ?

**First**, the parent process is created when the user runs the program. Then the isatty() function uses the open file descriptor referring to a terminal. If isatty() returns, the command prompt is displayed using write() with STDOUT_FILENO and waits for a user command line as input. When the user types a command, the getline() function reads an entire line from the stream and the strtok() function breaks the command into a non-empty token input.
**Then** it created a separate child process using fork() that executes the entered command. Unless otherwise specified, the parent process waits for the child process to finish before continuing. After the command is marked, the excve() function brings it in and executes it, then frees all the memory allocated with free(). Finally, the program returns to the main process: it prints the prompt, and waits for another input from the user.
**To further explain**, the tokenizer() function works in the same way as strtok(). It creates an array of pointers to store the arguments.
**Finally**, this implementation of tokens is essential for our command prompt to continue to display after a successful execution or an error.

### How to use shell ?

you can refer to the *manual*.


## Authors

The AUTHORS file lists all contributors to this SHELL project.
We have collaborated in a benevolent way, according to the skills and availability of each one.
We thank each other for the trust we have placed in each other :)

------------------------------------------------------
Thanks to:

- Dan <scorpion00100> <5625@holbertonstudents.com>
- Valentin <VAAL34> <5619@holbertonstudents.com>
- Amandine <Amandine4731> <5618@holbertonstudents.com>
------------------------------------------------------


## Flowtcharts

https://app.diagrams.net/#G1ibYsZk57Dvmuh0u8tQnacWPHFS2wsW3Z

![Shell Flowtcharts Dan Valentin Amandine-Page-2 drawio (1)](https://user-images.githubusercontent.com/113857342/206181585-3055b556-6098-4580-b2ec-261d38fd1549.png)

