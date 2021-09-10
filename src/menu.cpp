/* Menu functions implementation */
#include "../include/menu.hpp"
#include <ncurses.h>

/* MenuItem::MenuItem(MenuItem&& obj)
{
        label = obj.label;
        function = obj.function;
        next_menu = obj.next_menu;
        
        obj.label = "";
        obj.function = nullptr;
        obj.next_menu = nullptr;
} */




void Menu::print()
{

        int x = 0, y = 0, ii = 0;
        if(isStartMenu)
        {
              mvprintw(y,x,"%s",logo);
              addch('\n');
              y += LOGO_HEIGHT;
        }
        for (auto& i: items) {   
             if(ii + 1 == highlight)
             {
                attron(A_REVERSE);
                mvprintw(y,x,"%s\n",i.getLabel().c_str());
                attroff(A_REVERSE);
             }
             else mvprintw(y,x,"%s\n", i.getLabel().c_str());
             y++;
             ii++;
        }
        refresh();
        

}
