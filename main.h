#ifndef MAIN_H
#define MAIN_H

#include "person.h"
#include "student.h"
#include "professor.h"
#include <stdio.h>
#include <iostream>

void Calificando();
vector<Professor>& enterData();
void printStudent(Student stu);

#include "person.cpp"
#include "student.cpp"
#include "professor.cpp"

#endif // MAIN_H
