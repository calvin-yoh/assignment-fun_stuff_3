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




# Classes
First, referring to the diagram : R'Shell reads in from the input/instruction file. However there are many classes that build into the input class and we will discuss that in the following list.
1. Special Characters
	1. '#' (comment)
	1. $ (command prompt)
1. Connector
	1. ;
	1. &&
	1. ||
1. Commands
	1. 'Exit'
	1. ArgumentList
	1. Executable
	1. SysCalls
		1. Fork
		1. Execvp
		1. Waitpid
	


# Prototypes/Research
Will use prototypes as a base to create more complicated function



# Development and Testing Roadmap

