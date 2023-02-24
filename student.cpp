#include "student.h"

Student::Student(string DNI, string name, string surname) : Person(DNI, name, surname) {
}

float Student::getGrade(int pos) {
    if(pos>=0 && pos<=2) {
        if(pos<grades.size()) {
            return grades[pos];
        }
    }
    return -1;
}

vector<float> Student::getGrades() {
    return this->grades;
}

int Student::getNumGrades() {
    return this->grades.size();
}

float Student::getAverageGrade() {
    int counter=0;
    float sum=0;

    for(counter; counter<this->grades.size(); counter++) {
        sum += this->grades[counter];
    }

    return sum / float(counter);
}
