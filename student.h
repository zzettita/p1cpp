#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include <vector>

using namespace std;

class Student : public Person {
    public:
        vector<float> grades;

        Student(string DNI, string name, string surname);
        float getGrade(int pos); // either 0, 1 or 2
        vector<float> getGrades();
        int getNumGrades();
        float getAverageGrade();
};

#endif // STUDENT_H
