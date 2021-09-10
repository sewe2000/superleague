#include "../include/footballer.hpp"

Footballer::Footballer(const char* n, const char* ln,const char* nat,short a) :Person(n,ln,nat,a)
{
        value = 0.0f;
        overall = 0;
        shooting = 0;
        dribbling = 0;
        defending = 0;
        pace = 0;
        goalkeeping = 0;
}

void Footballer::print_info()
{

}
