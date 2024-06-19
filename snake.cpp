#include "snake.hpp"
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <ncurses.h>

#define cu_r "┐"
#define cu_l "┌"
#define cd_r "┘"
#define cd_l "└"
#define b_rl "│"
#define b_ud "─"
#define body "█"
#define apl "■"
using namespace std;
class snake::game
{
public:
int pressed;
static const int brd_x = 45,brd_y = 20; 
int brdt_x = 0,brdt_y = 0;
int snkp[brd_y-1][brd_x-1];

mutable std::chrono::milliseconds sleep;
game(int fps)
    {
        //this->brd_x = brd_x;
        //this->brd_y = brd_y;
        sleep = std::chrono::milliseconds(1000/fps);

    board();

    }

protected:
void board()
    {
         printf("\x1b[2J"); /// <- clearing the screen 
         printf("\x1b[H"); /// <- cursor to home position
        printf("\x1b[?25l"); /// <- hiding cursor
         printf("\x1b[38;5;2m"); /// <- green color
   
while(true)
{
printf("\x1b[2J");

//////////////////////// 

/*if(getch() == 'w')
{
printf("GEJ !!!\n");
}*/


for(brdt_y =0; brdt_y<=brd_y;brdt_y++)
{
    printf("\n");
    for(brdt_x = 0; brdt_x < brd_x;brdt_x++)
        {
          
            switch (brdt_y) 
            {
                case 0:

                    if(brdt_x == 0)
                    {
                        printf(cu_l);

                    }
                    else if (brdt_x == brd_x-1) 
                    {
                     printf(cu_r);
                    }
                    else 
                    {
                      printf(b_ud);
                    }
                break;

                case brd_y-1:
                    
                    if(brdt_x == 0)
                    {
                    printf(cd_l);

                    }
                    else if (brdt_x == brd_x-1) 
                    {   
                        printf(cd_r);
                    }
                    else 
                    {
                         printf(b_ud);
                    }


                break;

                default:

                if (brdt_x == 0 || brdt_x == brd_x-1) 
                {
                    printf(b_rl);
                }
                else
                {
                        switch (snkp[brdt_y][brdt_x])
                        {
                            case 's':
                                     printf(body);
                            break;

                            case 'a' :
                                      printf(apl);
                            break;

                            default:
                                    printf(" ");

                        }
                }

            }
        }    
     

}
   
  //pressed = getch();
 printf("\x1b[H"); /// <- restores cursor 
std::this_thread::sleep_for(sleep);
}
//////////////////////// 

   printf("\x1b[?25h"); /// <- cursor visible again
}

void snake()
{
      //  *brd_p = brd[brd_y/2][brd_x/2]; /// <- starting position of the snake
       // *brd_p = 's'; 


}
void apple()
{ 



 }



};

////////////////////////  ////////////////////////  









