#include "../header/Reader.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;

void Reader::checkPrio(const char check, int& returnValue)
{
	if(check == '"')
	{
		returnValue++;
	}else if(check == '#')
	{
		returnValue += 4;
	}else if(check == ';')
	{
		returnValue += 2;
	}else if(check == ' ')
	{	
		returnValue += 3;
	}
	
}


void Reader::splitString(const string vect, vector<string>& output)
{
	string word = "";
	int prioCheck = 0;
	for(int i = 0; i < vect.size(); i++)
	{	
		prioCheck = 0;
		checkPrio(vect.at(i), prioCheck);
		switch(prioCheck)
		{
			case 1: 
				i++;
                        	while(vect.at(i) != '"')
                        	{
                                	word = word + vect.at(i);
                                	i++;
                        	}
                        	output.push_back(word);
				word = "";
				break;
		

			case 2:
				if(word == " ")
				{
					word = vect.at(i);
					output.push_back(word);
					word = "";
				}
				else
				{
					output.push_back(word);
					word = vect.at(i);
					output.push_back(word);
					word = "";
				}	
				break;
			case 3:
				if(word != "")
				{ 
					output.push_back(word);
				}		
				word = "";
				break;
			case 4: 
				if(i != vect.size() -1)
				{
					if(vect.at(i+1) == ' ')
					{
						i+= 2;	
						word = '#';				
					}
				}
				while(i != vect.size() && vect.at(i) != ' ')
				{
					word = word + vect.at(i);
					i++;
				}
				output.push_back(word);
				word = "";
				break;
			default:
				word = word + vect.at(i);
				if(i == vect.size() - 1)
				{
					output.push_back(word);
					word = "";	
				} 					
		};	
	}
	
}

void Reader::execute(char* input[])
{	
		pid_t pid = fork();
		if(pid == -1)
		{
			perror("fork");
		}
		else if(pid == 0)
		{
			if(execvp(input[0], input) == -1)
			{
				perror("exec");
			}	
		}		
		else if(pid > 0)
		{
			if(wait(0) == -1)
			{	
				perror("wait failed");
			}
		}
}



void Reader::readInput(string input)
{
	int status = 0;
	vector<string> argv;
	splitString(input, argv);
	int countArgs = 0;
	char* argsOne[2];
	char* argsTwo[3];
	argsOne[1] = NULL;
	argsTwo[2] = NULL;
	for(int i = 0; i < argv.size(); i++)
	{
		countArgs = 0;
		while(countArgs + i != argv.size() && (argv.at(countArgs + i) != ";" && argv.at(countArgs + i) != "&&" && argv.at(countArgs + i) != "||" && argv.at(countArgs + i).at(0)  != '#'))
                        {
                                countArgs++;
                        }
		if(countArgs == 1)
                        {
                                argsOne[0] = (char*)argv.at(i).c_str();
                       		
                        }else if(countArgs == 2)
                        {
                                argsTwo[0] = (char*)argv.at(i).c_str();
                                argsTwo[1] = (char*)argv.at(i+1).c_str();
			}
		if(countArgs == 1)
                {
                        execute(argsOne);
			cout << "called  countArgsOne" << endl;
                }else if(countArgs == 2)
                {
                        execute(argsTwo);
			cout << "called countArgsTwo" << endl;
                }

		i += countArgs;
		
	}
}

