#include "main.h"

int main() {

    Calificando();

    return 0;

}

void Calificando() {
    
    vector<Professor>& professors = enterData();

    while(true) {
        std::cout << "Por favor, introduzca un DNI (número de 8 cifras) sin letra:\n";
        std::cout << "Si desea salir de la aplicación introduzca un 0\n";
        std::string enteredDNI;
        std::cin >> enteredDNI;

        if(enteredDNI == "0") {
            std::cout << "¡Hasta pronto!";
            break;
        }

        bool found = false;

        for(auto& prof : professors) {
            if(prof.getDNI() == enteredDNI) { //probamos el profesor
                found = true;
                prof.printStudents();
                prof.printBestStudent();
                break;
            } else { //si no, probamos sus alumnos
                try {
                    Student aux = prof.searchStudent(enteredDNI); //si no lo encuentra lanza excepcion y no sigue
                    found = true;
                    printStudent(aux);
                    break;
                } catch (exception) {}
            }
        }

        if(!found) {
            std::cout << "El DNI introducido no pertenece a ningún profesor o alumno.\n\n";
        }
    }
}

void printStudent(Student stu) {
    std::cout << "\n----------------------------------------\n";
    std::cout << stu.getName() << " " << stu.getSurname() << " DNI: " << stu.getDNI();
    vector<float> grades = stu.getGrades();
    std::cout << "\nNotas: ";
    for(int j=0; j<grades.size(); j++) {
        std::cout << grades[j] << "\t";
    }
    std::cout << "\nNota media: ";
    std::cout << stu.getAverageGrade();
    std::cout << "\n----------------------------------------\n";
}

vector<Professor>& enterData() {
    Professor david = Professor("1234567", "David", "Martínez Martínez");
    david.addStudent("2345678", "Diego", "Fernández Fernández");
    david.setGrade("2345678", 7.5, 7, 8.9);
    david.addStudent("2345679", "Daniel", "Rivas Rodríguez");
    david.setGrade("2345679", 4 , 6);
    david.addStudent("2345680", "Francisco", "Rivera Gómez");
    david.setGrade("2345680", 10);
    david.addStudent("2345682", "Ángela", "de la Riva Rodríguez");
    david.setGrade("2345682", 9, 10);
    david.addStudent("2345690", "Esther", "Díaz Fernández");
    david.setGrade("2345690", 2, 6, 4);
    david.printStudents();
    david.printBestStudent();

    Professor ramon = Professor("1234568", "Ramón", "Fernández Díaz");
    ramon.addStudent("2345578", "Laura", "Gómez García");
    ramon.setGrade("2345578", 8.5);
    ramon.addStudent("2345579", "Ignacio", "Fernández Robles");
    ramon.setGrade("2345579", 8, 9.5);
    ramon.addStudent("2345580", "María", "Pérez Martínez");
    ramon.setGrade("2345580", 10, 10, 2);
    ramon.addStudent("2345582", "Víctor", "Cisneros Conde");
    ramon.setGrade("2345582", 5, 4);
    ramon.addStudent("2345590", "Kevin", "Sánchez Díaz");
    ramon.setGrade("2345590", 2, 6, 4);
    ramon.printStudents();
    ramon.printBestStudent();

    Professor lidia = Professor("1934567", "Lidia", "Núñez Sánchez");
    lidia.addStudent("2945678", "Diego", "Martínez Carrera");
    lidia.setGrade("2945678", 2, 2, 2);
    lidia.addStudent("2945679", "Olga", "García García");
    lidia.setGrade("2945679", 10, 5);
    lidia.addStudent("2945680", "Vanessa", "De la Torre López");
    lidia.setGrade("2945680", 10);
    lidia.addStudent("2945682", "Rogelio", "Alonso Morales");
    lidia.setGrade("2945682", 9, 10);
    lidia.addStudent("2945690", "Sergio", "García Alonso");
    lidia.setGrade("2945690", 2, 6, 1);
    lidia.printStudents();
    lidia.printBestStudent();
}