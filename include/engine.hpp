#pragma once 
#include <clocale>
#include <iostream>
#include <string>
#include <ncurses.h>
#include <list>

namespace Engine
{

void about_game();
void manager_creator();
inline void press_enter_to_continue();
void stop(); 
void init();
void new_game();
void print_game_intro();
void menu();
WINDOW* create_window(short height, short width, short y, short x);
constexpr int center_coordinate(int width_or_height, int cols_or_lines)
{
                return  (cols_or_lines - width_or_height) / 2;
}


}
