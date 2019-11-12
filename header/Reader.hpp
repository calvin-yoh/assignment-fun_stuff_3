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
		void checkPrio(const char check, int& returnValue);
		void splitString(const string input, vector<string>& output);
		
	public:
		void readInput(string input);
};

#endif

