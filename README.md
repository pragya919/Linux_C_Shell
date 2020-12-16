# Linux_C_Shell : My Shell
Welcome to my Linux C-Shell. Hope you like it :)

## Introduction
This is the implementation of the basic version of the Linux Shell. It is completely written in C language. It supports most of the basic linux commands including semicolon separated commands. Extra tabs and spaces are taken care of. Error handling is done in all appropriate cases.

## How to run the shell
Fork the repository on to your local machine and run the following commands - 
```
make main
./a.out
```
## Features
The commands supported are as follows - 
* pwd - prints the current working directory
  * Code : pwd.c 
  
* echo - prints the message on the terminal
  ```
  echo <text>
  ```
  * Code : echo.c

* cd - changes the directory based on the flags given -
   
  ```
  cd
  cd .
  cd ..
  cd ~
  cd -
  cd <directory>
  ```
  * Error Handling : Displays an error if the directory is not present
  * Code : cd.c

* ls - lists the contents of a particular directory based on the flags given - 
  ```
  ls
  ls -a
  ls -l
  ls -al
  ls -la
  ls <directory>
  ```
  * Error Handling : Displays an error if the directory is not present 
  * Code : ls.c

* pinfo - prints the details of the process whose pid is specified. If not mentioned, prints the details for the current process
  ```
  pinfo
  pinfo <pid>
  ```
  * Error Handiling : Displays an error if pid is not present
  * Code : pinfo.c
  
* setenv - sets the environment variable to a specified value (creates a new environment variable if not already present). If no value is specified then it sets the variable to an empty value
  ```
  setenv [var] <value>
  ```
  * Error Handling : Displays an error in case of too few or too much arguments
  * Code : setenvv() in envs.c
  
* unsetenv - unsets the environment variable 
  ```
  unsetenv [var] 
  ```
  * Error Handling : Displays an error in case of too few or too much arguments
  * Code : unsetenvv() in envs.c

* Other commands : implementing some other commands using execvp
  ```
  command <space>
  command <file>
  ```
  * Error Handling : Displays an error if the command doesn't exist
  * Code : others.c
 
## To Quit the shell
Run the following command -
```
quit
```

## Other Files
* header.h and takeinput.h - for header files and declarations
* main.c - the main file with init_shell() function displays message upon initialisation and quit_shell() function displays message upon exiting the shell
* takeinput.c - the input file
* prompt.c - for displaying prompt
