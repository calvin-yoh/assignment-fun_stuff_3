#include <iostream>
#include <sys/types.h> 
#include <unistd.h>


using namespace std; 
int main() 
{ 
    fork(); 
    cout << "Hello world!" << endl; 
    return 0; 
}
                      
