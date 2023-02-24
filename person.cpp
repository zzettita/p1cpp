#include "person.h"


Person::Person(string DNI,string name, string surname) {
    this->DNI = DNI;
    this->name = name;
    this->surname = surname;
}

string Person::getDNI()  {
    return this->DNI;
}

string Person::getName() {
    return this->name;
}

string Person::getSurname() {
    return this-> surname;
}
