#include "input.hpp"
#include <cstdio>
#include <unistd.h>
#include <string.h>
#ifdef __unix
#include <termios.h>
#include <sys/ioctl.h>
#elif _WIN32
#include <conio.h>  
#endif


class input
{
    
public :
char KeyPressed;
char prev_key ;
#ifdef __unix
struct termios previous_terminal_config;
struct termios terminal_config;
#endif

input()
{


#ifdef __unix
tcgetattr(TCSANOW,&previous_terminal_config);
terminal_config = previous_terminal_config;
terminal_config.c_lflag &= ~ICANON;
terminal_config.c_lflag &= ~ECHO;
tcsetattr(0,TCSANOW,&terminal_config);
#endif
    
}

~input()
{
    #ifdef __unix
tcsetattr(0,TCSANOW,&previous_terminal_config);
    #endif

}


char Listener()
{
#ifdef __unix
int pressed;
ioctl(0, FIONREAD,&pressed);
    if(pressed)
read(0, &KeyPressed, 1);

#elif _WIN32
if (kbhit() != 0)
    KeyPressed =(char)getch();
#endif

return KeyPressed;

}


};

