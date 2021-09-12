#include "../include/person.hpp"
#include <iostream>

Person::Person(const char* n, const char* ln,const char* nat,short a): nickname{""}
{
       name = n; 
       last_name = ln;
       nationality = nat;
       birthday = "";
       age = a;
       height = 0.0f;
       if (!end_of_contract.empty()) {
                have_a_job = true;         
       }
       else have_a_job = false;
}
void Person::print_info()
{
        std::cout << "Name: " << name << last_name << std::endl; 
        if (!nickname.empty()) {
                std::cout << "Known as: " << nickname << std::endl;
        }
        std::cout << "Club: " << club_name << std::endl;
        std::cout << "Nationality: " << nationality << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "End of contract: " << end_of_contract << std::endl;
}
