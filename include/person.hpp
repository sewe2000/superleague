#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>


class Person
{
public:
        Person(const char* n, const char* ln,const char* nat,short a);
        const char* name;
        const char* last_name;
        const char* birthday;
        const char* nationality;
        virtual void print_info();

protected:
        std::string end_of_contract;
        std::string club_name;
        std::string nickname;
        short age;
        bool have_a_job;
        float height;
private:
};
#endif
