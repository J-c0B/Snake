#include "GameLogic.hpp"
#include "../I-O/input.cpp"
#include <random>



#define BLANK 0
#define SNAKE 1
#define APPLE 2
#define BORDER 3

struct snake_body
{
    int * position;
    int direction;
    int * next_position;

};



class rules: public input
{   
    public :
int win = 0;
static const int brd_x = 20,brd_y = 20; 
int obj_map [brd_y-1][brd_x-1];
int score;
int * apple;
snake_body bbdy[(brd_y-1)*(brd_x-1)];
bool main_loop = true;
int snake_x,snake_y;
int snake_count = 0;
int move = 1;
char prev_dir = '\0';

void Keychck()
{

switch (tolower(Listener()))
{
   
case 'w':
if(prev_dir != 's')
{
    prev_dir = 'w';
    bbdy[0].position -= brd_x-move;
    snake_y++; 
   
}
else
{
    bbdy[0].position += brd_x-move;
    snake_y--; 
}
 Collision();
break;
case 'a':
if(prev_dir != 'd')
{
    prev_dir = 'a';
    bbdy[0].position -= move;
    snake_x--;

}
else
{
    bbdy[0].position += move;
    snake_x++;
}
 Collision();
break;
case 's':
if(prev_dir != 'w')
{
    prev_dir = 's';
    bbdy[0].position += brd_x-move;
    snake_y--;
   
}
else
{
      bbdy[0].position -= brd_x-move;
    snake_y++;
}
  Collision();
break;
case 'd':
if(prev_dir != 'a')
{
    prev_dir = 'd';
    bbdy[0].position += move;
    snake_x++;
  
}
else
{
 bbdy[0].position -= move;
    snake_x--;

}
  Collision();
break;
case 27:
    main_loop = false;
break;

}

}

void Mv()
{

for(int k = 1 ; k<=snake_count;k++)
{
    bbdy[k].position = bbdy[k].next_position;
    bbdy[k].next_position = bbdy[k-1].position;

}

}

void Collision()
{
    if(bbdy[0].position == apple)
    {
        snake_count++;
        score++;
      bbdy[snake_count].next_position = bbdy[snake_count-1].position;
      AppleGen();
    }
    else if (*bbdy[0].position == BORDER || snake_y>brd_y || snake_y < 0 || snake_x>brd_x || snake_x <0 )
    {
         Gamestate(false);
    }
    for(int k = 1 ; k<=snake_count;k++)
    {
         if ( bbdy[0].position == bbdy[k].position)   
                   Gamestate(false);
            
    }


}

void AppleGen()
{
int x,y;
y = Randomize(brd_y-2);
x = Randomize(brd_x-2);
apple = &obj_map[y][x];

   for(int k = 0 ; k<snake_count;k++)
    {
         if ( apple != bbdy[k].position)   
             continue;
                    AppleGen();
            
    }

}


int Randomize(int max)
{
std::random_device seed;
std::default_random_engine gen(seed());
std::uniform_int_distribution<int> randomized(1, max);
return randomized(gen);
}

void Gamestate(bool state)
{
        if(state)
        {
            win = 2;
        }
        else
        {
                win = 1;

        }
          main_loop = false;
}



};