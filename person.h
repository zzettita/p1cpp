#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {

    public:
        Person(string DNI,string name, string surname); //constructor
        //getters
        string getDNI();
        string getName();
        string getSurname();

    private:
        string DNI;
        string name;
        string surname;

};

#endif // PERSON_H
