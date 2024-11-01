#include "GameLogic.hpp"
#include <fstream>
#include <iostream>
using namespace std;

class Data
{
private :
fstream file;



public :

void Local_Data()
{



}


void Installation()
{
#ifdef __unix__
system("ln -s $(pwd)/snake /usr/bin/snake");
#endif
}


};







