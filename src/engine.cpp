#include "../include/engine.hpp"
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "../include/menu.hpp"
#include <stack>


void Engine::about_game()
{
        addstr("The game 'Superleague' is in progress.\n");
        addstr("Superleague is written in C++ using GNU ncurses library and it's hosted on github: https://github.com/serweryn7D6/superleague\n");
        addstr("The game has been tested only on some UNIX-like operating systems like GNU/Linux and MacOS so far. The Windows version probably won't come out soon.\n");

}
WINDOW* Engine::create_window(short height, short width, short y, short x)
{
        WINDOW *local_win;
        local_win = newwin(height,width,y,x);
        wborder(local_win, ACS_VLINE, ACS_VLINE, ACS_HLINE,
        ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
        box(local_win,0,0);
        wrefresh(local_win);
        return local_win;
}
void Engine::press_enter_to_continue()
{
        addstr("Press ENTER, to continue...\n");
        while (getch() != '\n')
                continue;
}
void Engine::manager_creator()
{
        clear();
        WINDOW *creator = create_window(10,10,  0, 0);
        getch();
}


void Engine::init()
{
        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        curs_set(0);
}
void Engine::stop()
{
        endwin();
        exit(0);
}

void Engine::new_game()
{
        // print_game_intro();
        press_enter_to_continue();
        clear();
}

void Engine::menu()
{
        int ch;
        Menu menu_play = {
        MenuItem("New Game",&Engine::new_game),
        MenuItem("Continue")
        };
        Menu menu_settings = {
                MenuItem("Database editor"),
        };
        Menu start_menu = {
        MenuItem("Play",nullptr,&menu_play),
        MenuItem("Settings", nullptr, &menu_settings),
        MenuItem("About the game", &Engine::about_game),
        MenuItem("Exit", &Engine::stop)
        }; 
        std::stack<Menu*> menus;
        menus.push(&start_menu);
        Menu* current_menu = menus.top();
        current_menu->print();
        ch = getch();
        while (ch != 'q') {
                switch (ch) {
                        case KEY_UP:
                                  if(current_menu->highlight == 1)
                                          current_menu->highlight = current_menu->n_options;
                                  else current_menu->highlight--;
                                  current_menu->print();
                                  break;
                        case KEY_DOWN:
                                  if(current_menu->highlight == current_menu->n_options)
                                          current_menu->highlight = 1;
                                  else current_menu->highlight++;
                                  current_menu->print();
                                  break;
                        case KEY_RIGHT:
                        case 10:

                                if(current_menu->get_submenu() != nullptr)
                                {
                                        menus.push(current_menu->get_submenu());
                                        current_menu = menus.top();
                                        clear();
                                        current_menu->print();
                                }
                                else {
                                        clear();
                                        current_menu->call();
                                        menus.push(nullptr);
                                }
                                break;
                        case KEY_LEFT:
                        case KEY_BACKSPACE:
                                menus.pop();
                                current_menu = menus.top();
                                clear();
                                current_menu->print();
                                break;


                }
                ch = getch();
        }
}
