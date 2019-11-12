#ifndef READER_H
#define READER_H


#include <string>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

class Reader
{
	private: 
		void splitString(const vect<char>input, vect<char> output);
		
	public:
		void readInput(string input);
};

#endif

