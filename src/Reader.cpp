#include "../header/Reader.hpp"
#include <vector>
#include <string>
#include <iostream>


using namespace std;

void Reader::readInput(string input)
{
	vector<char> vect(input.begin(), input.end());
	vector<char> comment;
	for(int i = 0; i < vect.size(); i++)
	{
		if(vect.at(i) == '"')
		{	
			i++;
			while(vect.at(i) != '"')
			{
				comment.push_back(vect.at(i));
				i++;
			}
		}	
	}	
	for(int i = 0; i < comment.size(); i++)
	{
		cout << comment.at(i);
	}

}

