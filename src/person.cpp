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
        std::cout << "Imię i nazwisko: " << name << last_name << std::endl; 
        if (!nickname.empty()) {
                std::cout << "Znany jako: " << nickname << std::endl;
        }
        std::cout << "Klub: " << club_name << std::endl;
        std::cout << "Narodowość: " << nationality << std::endl;
        std::cout << "Wiek: " << age << std::endl;
        std::cout << "Koniec kontraktu: " << end_of_contract << std::endl;
}
