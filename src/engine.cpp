#include "../include/engine.hpp"
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include "../include/menu.hpp"
#include <stack>


void Engine::about_game()
{
        addstr("Gra Superliga jest w trakcie produkcji. Jej autorem jest Seweryn P.\n");
        addstr("Jest ona napisana w języku C++ przy użyciu biblioteki standardowej tegoż języka oraz GNU ncurses\n");
        addstr("Gra testowana była na platformie GNU/Linux oraz macOS Big Sur 11.3.1 (M1), wersja Windowsowa najprawdopodobniej prędko się nie pojawi jeśli w ogóle.\n");
        addstr("Moje narzędzia pracy: edytor kodu - Neovim, kompilator - g++ , system budowania - GNU Make, debugger - GNU Debugger (gdb)\n");

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
        addstr("Wciśnij ENTER, aby kontynuować...\n");
        while (getch() != '\n')
                continue;
}
void Engine::manager_creator()
{
        clear();
        WINDOW *creator = create_window(10,10,  0, 0);
        getch();
}
void Engine::print_game_intro()
{
        clear();
        addstr("W kwietniu 2021 r. europejskim piłkarskim światem wstrząsneła wiadomość o koncepcie superligi.\n");
        addstr("Podczas pandemii COVID-19 kluby piłkarskie zaczęły ponosić straty na które lekarstwem miała być superliga.\n");
        addstr("W superlidze występować miało tylko 20 elitarnych klubów europejskich bez udziału UEFA.                   \n");
        addstr("Miało to zapewnić wyższą oglądalność, a tym samym większe pieniądze.                                      \n");
        addstr("Ostatecznie pod naciskiem UEFA projekt upadł. Czy zastanawiałeś/aś się jednak co by się stało gdyby superliga pozostała przy życiu?\n");
        addstr("W grze Superliga 2021, wcielisz się w wykreowanego przez ciebie managera dowolnego z klubów Superligi.\n");
        addstr("Poprowadź swój klub do wielkiej chwały i pieniędzy oraz daj powód do radości kibicom, przy okazji pokazując kto rządzi w Europie.\n");
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
        print_game_intro();
        press_enter_to_continue();
        clear();
}

void Engine::menu()
{
        int ch;
        Menu menu_play = {
        MenuItem("Nowa Gra",&Engine::new_game),
        MenuItem("Kontynnuj")
        };
        Menu menu_settings = {
                MenuItem("Włącz drużyny niewystępujące w superlidze (np. Bayern, PSG)"),
                MenuItem("Edytor bazy danych"),
        };
        Menu start_menu = {
        MenuItem("Graj",nullptr,&menu_play),
        MenuItem("Ustawienia", nullptr, &menu_settings),
        MenuItem("O grze", &Engine::about_game),
        MenuItem("Wyjdź", &Engine::stop)
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
