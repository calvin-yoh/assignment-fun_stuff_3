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
		void execute(char* input[], int& status);
		bool working = true;
		
	public:
		void readInput(string input);
		bool doInput(string input);
};

#endif

