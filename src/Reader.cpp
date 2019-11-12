#include "../header/Reader.hpp"
#include <vector>
#include <string>
#include <iostream>


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
				output.push_back(word);
				word = "";
				break;
			case 4: 
				if(vect.at(i+1) == ' ');
				{
					i++;					
				}
				while(vect.at(i) != ' ' || i != vect.size() - 2)
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


void Reader::readInput(string input)
{

	vector<string> argv;
	splitString(input, argv);

	vector<char> comment;
	for(int i = 0; i < argv.size(); i++)
	{
		cout << argv.at(i) << " ";
	}
}

