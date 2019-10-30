# CS 100 Programming Project
* Spring Quarter, 2019
* Calvin Yoh, 862088713
* Alex Kevakian, 861302910



# Introduction
Our program is called R'Shell and it will be able to take in a list of commands and execute them.
The commands will be executed using 3 syscalls: _fork_, _execvp_, and _waitpid_
We will most likely be using a composite design pattern, with the inputs being read into a file.
The input will then be separated into classes and structures shown in the diagram below.



# Diagram
https://github.com/cs100/assignment-fun_stuff/blob/master/images/Assignment%201.png?raw=true



# Classes
First, referring to the diagram : R'Shell reads in from the input/instruction file. However there are many classes that build into the input class and we will discuss that in the following list.
1. Special Characters
	1. '#' (comment)
		* This will make anything that appears after this symbol a comment and it will not execute.
	1. $ (command prompt) 
		* Prints everytime to make sure that our commands can be recognized
1. Connector
	1. ;
		* Terminating connector
	1. &&
		* If a command is followed by this symbol, the next command is executed only if the current command succeeds
	1. ||
		* If a command is followed by this symbol, the next command is executed only if the current one fails
1. Commands
	1. 'Exit'
		* Special built in command that will exit the program
	1. ArgumentList
		* Holds all the arguments the user wants to pass
	1. Executable
		* Are commands the user wants to pass
	1. SysCalls
		1. Fork
			* A call used when you want to create a new process that will run concurrently with the parent process
		1. Execvp
			* A call that replaces the current running process with a new process. This particular command will allow the new process to not run the same program the parent process did
		1. Waitpid
			* A call that will suspend more calling processes until a child process ends or is stopped
	


# Prototypes/Research
Will use prototypes as a base to create more complicated function



# Development and Testing Roadmap

