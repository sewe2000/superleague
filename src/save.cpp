#include "../include/save.hpp"
#include <filesystem>
#include <ncurses.h>

Save::Save(const char *p) 
{
        if(std::filesystem::exists(p))
        {
        }
}
