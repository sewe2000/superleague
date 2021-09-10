 /* Menu Handling classes */        
#pragma once
#include <vector>
#include <initializer_list>
#include <string>
#include "../include/engine.hpp"
#include <menu.h>

class Menu;
struct MenuItem
{
        MenuItem(const char* name, void(*func_ptr)() = nullptr, Menu* m = nullptr): label{name},function{func_ptr},next_menu{m} {}                                                
        MenuItem(MenuItem&& obj) = default;
        MenuItem(const MenuItem& obj) = default;
        MenuItem()
        {
                item = nullptr;
                label = "";
                function = nullptr;
                next_menu = nullptr;
        }
        std::string getLabel() {return label;}
        Menu* get_next() {return next_menu;}
        void call()
        {
                if(function != nullptr)
                        (*function)();          
        }
private:
        ITEM *item;
        std::string label;
        void (*function)();
        Menu *next_menu;

};
class Menu
{
public:
        friend void Engine::menu();
        Menu(std::initializer_list<MenuItem> it): items{it}
        {
                
                if(items[0].getLabel() == "Graj")
                        isStartMenu = true;
                else isStartMenu = false;
                n_options = items.size();
        }
        void print();
        void call()
        {
                items[highlight-1].call();
        }
        Menu* get_submenu() {return items[highlight-1].get_next();}
private:
        static constexpr int LOGO_WIDTH = 54;
        static constexpr int LOGO_HEIGHT = 11;
        std::vector<MenuItem> items;
        short highlight = 1;
        short n_options;
        MENU *m;
        bool isStartMenu;
        static constexpr char logo[]=       
        " ____  _   _ ____  _____ ____  _     ___ ____    _\n" 
        "/ ___|| | | |  _ \\| ____|  _ \\| |   |_ _/ ___|  / \\\n"
        "\\___ \\| | | | |_) |  _| | |_) | |    | | |  _  / _ \\\n"
        " ___) | |_| |  __/| |___|  _ <| |___ | | |_| |/ ___ \\ \n"
        "|____/ \\___/|_|   |_____|_| \\_\\_____|___\\____/_/   \\_\\\n"
        " ____   ___ ____  _    ______   ___ ____   ____ \n"
        "|___ \\ / _ \\___ \\/ |  / /___ \\ / _ \\___ \\ |___ \\ \n"
        "  __) | | | |__) | | / /  __) | | | |__) | __) |   \n"
        " / __/| |_| / __/| |/ /  / __/| |_| / __/ / __/    \n"
        "|_____|\\___/_____|_/_/  |_____|\\___/_____|_____| \n";
        
};

