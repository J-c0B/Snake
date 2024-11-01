#include "output.hpp"
#include "../game-logic/rules.cpp"
#include <time.h>
#include <chrono>
#include <thread>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#include <cstdio>
#include <stdlib.h>
#ifndef CLEAR
//#define CLEAR "cls"
#endif
#elif __unix__
#ifndef CLEAR
//#define CLEAR "\x1b[2J"
#endif
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <chrono>
#include <thread>
#endif
#define cu_r "*"
#define cu_l "*"
#define cd_r "*"
#define cd_l "*"
#define b_rl "|"
#define b_ud "-"
#define body "#"
#define apl "@"
#define CLEAR "\x1b[2J"

using namespace std;

class output : public rules
{
public:
    int color;
    bool cmd = false;
    bool first_start = true;
    long sleep;
    void game(int fps)
    {
           
#ifdef __unix__
        sleep = 1000000 / fps;

#elif _WIN32
        sleep = 1000 / fps;
#endif
#ifdef _WIN32
        if (cmd)
        {
            system(CLEAR);
        }
        else
        {
            cout << CLEAR;
        }
#elif __unix__
        printf(CLEAR);
#endif

        cout << "\x1b[H";       // cursor to home position
        cout << "\x1b[?25l";    // hiding cursor
        cout << "\x1b[38;5;2m"; // green color

        while (main_loop)
        {
            if (first_start)
                initialization();
#define CLOCKS_PER_MILSEC (CLOCKS_PER_SEC / 1000)

            update();
            graphics();

            cout <<"\x1b[H"; // cursor to home position

#ifdef __unix
            usleep(sleep);
#elif _WIN32
            Sleep(sleep);
#endif
        }
        #ifdef _WIN32
        if (cmd)
        {
            system(CLEAR);
        }
        else
        {
            cout << CLEAR;
        }
    #elif __unix__
        cout << CLEAR;
    #endif
          if(win == 2)
            {        
                          cout << "\n" <<" ! Y O U  W O N  ! " << endl;  
                           cout << "\n" <<"  S C O R E :  " << score <<endl <<endl;  
                           
            }
                   else if (win == 1)
            {
                        cout << "\n" <<" ! Y O U  L O S T  ! " << endl;  
                         cout << "\n" <<" S C O R E :  " << score << endl<<endl;  
                        
            }

       
        cout <<"\x1b[?25h"; // cursor visible again         
        cout << "\x1b[0m";  // resets styles and colors
      
    }

protected:
    void graphics()
    {

#ifdef _WIN32 // clearing the screen
        if (cmd)
        {
            system(CLEAR);
        }
        else
        {
            cout << CLEAR;
        }
#elif __unix__
        cout << CLEAR;
#endif
        int brdt_x = 0, brdt_y = 0;
        cout << endl;
#ifdef __unix
        for (brdt_y = 0; brdt_y <= brd_y; brdt_y++)
#elif _WIN32
        for (brdt_y = 0; brdt_y < brd_y; brdt_y++)
#endif
        {
            
            cout <<endl;
            for (brdt_x = 0; brdt_x < brd_x; brdt_x++)
            {

                switch (brdt_y)
                {
                case 0:

                    if (brdt_x == 0)
                    {
                       
                        cout << cu_l;
                    }
                    else if (brdt_x == brd_x - 1)
                    {
                       
                        cout << cu_r;
                    }
                    else
                    {
                       
                        cout << b_ud;
                    }
                    break;

                case brd_y - 1:

                    if (brdt_x == 0)
                    {
                      
                        cout << cd_l;
                    }
                    else if (brdt_x == brd_x - 1)
                    {
                      
                        cout << cd_r;
                    }
                    else
                    {
                       
                        cout << b_ud;
                    }

                    break;

                default:

                        if(!main_loop)
                                break;

                        bool check = false;
                        int * cc = &obj_map[brdt_y][brdt_x];
                    for(int k = 0 ; k<=snake_count;k++)
                    {
                       if ( cc == bbdy[k].position)
                       {
                       
                        cout << body;
                        check = true;
                       }
                    }
                        if (cc == apple)
                    {

                       
                        cout << apl;
                         check = true;
                    }
                    if(!check)
                    {
                    if (brdt_x == 0 || brdt_x == brd_x - 1)
                    {
                        
                        cout << b_rl;
                    }
                    else if (obj_map[brdt_y][brdt_x] == BLANK)
                    {

                       cout << " ";
                    }
                    }
                }
                if(brdt_x == (brd_x-1) && brdt_y == (brd_y-1))
                {
                  
                  cout << "\n" <<"S C O R E : " << score;  
                 
                
                }
            }
        }
    }

    void update()
    {
        Keychck();
        Mv();
      
    }

    void initialization()
    {

       for (int y = 0; y < brd_y; y++)                                    // setting obj_map
        {
            for (int x = 0; x < brd_x; x++)                                             
            {
                if (y == 0 || y == brd_y - 1 || x == 0 || x == brd_x - 1)
                {
                    obj_map[y][x] = BORDER;
                }
                else
                {
                    obj_map[y][x] = BLANK;
                }
            }
        }
       
        obj_map[brd_y][1] = BORDER;         // fix for bottom-left borders not showing up correctly somehow?
        obj_map[brd_y][2] = BORDER;         
         bbdy[snake_count].position = &obj_map[(brd_y - 1) / 2][(brd_x - 1) / 2];   // head start position
         snake_x = (brd_x - 1) / 2;
         snake_y = (brd_y - 1) / 2;
       AppleGen();
       score = 0;
        first_start = false;        
    }
};