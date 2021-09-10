#pragma once 
#include "../include/person.hpp"
#include <vector>

class Footballer : public Person
{
public:
        Footballer(const char* n, const char* ln,const char* nat,short a);
        virtual void print_info() override;
        
private:
        std::vector<const char*> positions;
        float value;
        int overall;
        int shooting;
        int dribbling;
        int defending;
        int pace;
        int goalkeeping;
        std::vector<const char*> traits;
        

};
