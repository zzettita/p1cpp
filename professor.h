#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"
#include "student.h"
#include <iostream>
#include <vector>


using namespace std;

class Professor : public Person {

    private:

        vector<Student> list;

    public:

        Professor(string DNI, string name, string surname);

        void addStudent(string DNI, string name, string surname);

        int setGrade(string DNI, float grade1);
        int setGrade(string DNI, float grade1, float grade2);
        int setGrade(string DNI, float grade1, float grade2, float grade3);

        float getAverageGrade(string DNI);
        Student& getBestStudent();
        void printStudents();
        void printBestStudent();        
        Student& searchStudent(string DNI);

};

#endif // TEACHER_H
