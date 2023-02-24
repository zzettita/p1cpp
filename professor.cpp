#include "professor.h"

Professor::Professor(string DNI, string name, string surname) : Person(DNI, name, surname) {
}

void Professor::addStudent(string DNI, string name, string surname) {
    Student stu = Student(DNI, name, surname);
    this->list.push_back(stu);
}

Student& Professor::searchStudent(string DNI) {
    for(auto& stu : list) {
        if(stu.getDNI() == DNI) {
            return stu;
        }
    }
    throw exception();
}

int Professor::setGrade(string DNI, float grade1) {
    try {
        Student& stu = Professor::searchStudent(DNI);
        if(stu.grades.size()>2) {
             return -1;
        }
        stu.grades.push_back(grade1);
    } catch (exception) {
        return -1;
    }
    return 0;

}

int Professor::setGrade(string DNI, float grade1, float grade2) {
    try {
        Student& stu = Professor::searchStudent(DNI);
        if(stu.grades.size()>1) {
             return -1;
        }
        stu.grades.push_back(grade1);
        stu.grades.push_back(grade2);
    } catch (exception) {
        return -1;
    }
    return 0;
}

int Professor::setGrade(string DNI, float grade1, float grade2, float grade3) {
    try {
        Student& stu = Professor::searchStudent(DNI);
        if(stu.grades.size()!=0) {
             return -1;
        }
        stu.grades.push_back(grade1);
        stu.grades.push_back(grade2);
        stu.grades.push_back(grade3);

        // for(int j=0; j<stu.grades.size(); j++) {
        //     std::cout << stu.grades[j] << "\t";
        // }
    } catch (exception) {
        return -1;
    }
    return 0;
}

float Professor::getAverageGrade(string DNI) {
    try {
        Student stu = Professor::searchStudent(DNI);
        return stu.getAverageGrade();
    } catch (exception) {
        return -1;
    }
}

Student& Professor::getBestStudent() { //throws exception when there are no students with 3 grades
    int posBest = -1;
    float bestGrade = 0;
    for(int i=0; i<this->list.size(); i++) {
        Student aux = list[i];
        if(aux.getNumGrades()==3) {
            float actAverage = aux.getAverageGrade();
            if(actAverage>bestGrade) {
                posBest = i;
                bestGrade = actAverage;
            }
        }
    }
    if(posBest==-1) throw exception();
    return list[posBest];
}

void Professor::printStudents() {

    std::cout << "PROFESOR:\n";
    std::cout << this->getName() << " " << this->getSurname() << " DNI: " << this->getDNI();
    std::cout << "\n----------------------------------------\n";

    for(int i=0; i<this->list.size(); i++) {
        std::cout << list[i].getName() << " " << list[i].getSurname() << " DNI: " << list[i].getDNI();
        vector<float> grades = list[i].getGrades();
        std::cout << "\nNotas: ";
        for(int j=0; j<grades.size(); j++) {
            std::cout << grades[j] << "\t";
        }
        std::cout << "\nNota media: ";
        std::cout << list[i].getAverageGrade();
        std::cout << "\n----------------------------------------\n";
    }

}

void Professor::printBestStudent() {
    Student& stu = this->getBestStudent();
    std::cout << "\n----------------------------------------\nMejor alumno:\n";
    std::cout << stu.getName() << " " << stu.getSurname() << " DNI: " << stu.getDNI();
    vector<float> grades = stu.getGrades();
    std::cout << "\nNotas: ";
    for(int j=0; j<grades.size(); j++) {
        std::cout << grades[j] << "\t";
    }
    std::cout << "\nNota media: ";
    std::cout << stu.getAverageGrade();
    std::cout << "\n----------------------------------------\n\n";

}













