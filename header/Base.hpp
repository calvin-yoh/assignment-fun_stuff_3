#ifndef BASE_H
#define BASE_H

using namespace std;

class Base{
	public:
	Base(){};
 	
	Base* left;
	Base* right;
	vector<Base*> baseVect;
	virtual void execute() = 0;
};



#endif
