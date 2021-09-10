#include "../include/engine.hpp"
int main()
{
        setlocale(LC_ALL, "pl_PL.UTF-8");
        Engine::init();
        Engine::menu();
        Engine::stop(); 
        return 0;
}

