# CS 100 Programming Project
* Fall Quarter, 2019
* Calvin Yoh, 862088713
* Alex Kevakian, 861302910




# Introduction
Our program is called R'Shell and it will be able to take in a list of commands and execute them.
The commands will be executed using 3 syscalls: _fork_, _execvp_, and _waitpid_
We will most likely be using a composite design pattern, with the inputs being read into a file.
The input will then be separated into classes and structures shown in the diagram below.



# Diagram
![Diagram](https://github.com/cs100/assignment-fun_stuff/blob/master/images/Assignment%201-2.png?raw=true)



# Classes
First, referring to the diagram : R'Shell reads in from the input/instruction file. However there are many classes that build into the input class and we will discuss that in the following list.
1. Special Characters
	1. '#' (comment)
		* This will make anything that appears after this symbol a comment and it will not execute.
	1. $ (command prompt) 
		* Prints everytime to make sure that our commands can be recognized
	1. " (quotes)
		* anything between these special characters will be treated as one whole class object 
	1. (
		* Can be used to prioritze certain calls and change the order that the shell will execute the commands
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
		1. Stat
			* A call used to check to see if a path is exists. Can be used with IS_REG or IS_DIR to complete this task with more detail
	


# Prototypes/Research
Will use prototypes as a base to create more complicated function
Build off waitpid, execvp, and fork functions




# Development and Testing Roadmap
1. Command Prompt Symbol
	 https://github.com/cs100/assignment-fun_stuff/issues/2
1. Argument List
	https://github.com/cs100/assignment-fun_stuff/issues/7
1. Executable
	https://github.com/cs100/assignment-fun_stuff/issues/5 
1. Connectors
	https://github.com/cs100/assignment-fun_stuff/issues/1
1. SysCalls
	https://github.com/cs100/assignment-fun_stuff/issues/3
1. Exit Call
	https://github.com/cs100/assignment-fun_stuff/issues/4
1. Comment Symbol
	https://github.com/cs100/assignment-fun_stuff/issues/6
