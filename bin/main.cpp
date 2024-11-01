#include "I-O/output.cpp"
#include "game-logic/data.cpp"
#include "main.hpp"
#include <string.h>

using namespace std;

bool start = true;
bool cmd_local = false;
Data data_class;
int main(int argc, char *argv[])
{
    output Scr;
   
    options(argc,argv);
    Scr.cmd = cmd_local;
    if(start)
    {
        
input();    
Scr.game(5);

    }
    return 0;
}

void options(int argc, char* argv[])
{
if(argv[1])
    if(strcmp(argv[1],"--help") == 0 || strcmp(argv[1],"-help")== 0)
    {
    cout << endl <<"--help or -help => Prints all available options\n--cmd or -cmd => unique screen refreshing for cmd \n--install or -install => (Does not work on windows)  makes snake available  as command , requires highier permissions ! \nBoard Size : \nFor now the only available size is the default 20x20 \n"
    << endl << " Key Settings : " << endl << " W = > move up " << endl << " A = > move left " << endl << " S = > move down " << endl << " D = > move right "
    << endl << " Escape = > immediate game exit ";
    start =false;
    }
    else if(strcmp(argv[1],"--cmd")== 0 || strcmp(argv[1],"-cmd")== 0)
    {
        cmd_local = true;
    }
    else if(strcmp(argv[1],"--install")== 0 || strcmp(argv[1],"-install")== 0)
    {
        data_class.Installation();
         start =false;
    }

}
