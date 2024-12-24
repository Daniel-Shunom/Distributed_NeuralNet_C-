#include <iostream>

class Department {
public:
    struct Student {
        std::string fname, lname, major;
        int age;
        float gpa;
    };

    Student _student;

    Department(){
        _student.fname = _student.lname = _student.major;
        _student.age = 0;
        _student.gpa = 0.0;
    };

    void print_student(){
        std::cout << _student.fname << std::endl;
        std::cout << _student.lname << std::endl;
        std::cout << _student.major << std::endl;
        std::cout << _student.age << std::endl;
        std::cout << _student.gpa << std::endl;
        std::cout << std::endl << std::endl << std::endl;
    }

    void create_student(){
        std::cout << "ENTER STUDENT NAME\n \tFIRST NAME: ";
        std::cin >> _student.fname;
        std::cout << "\tLAST NAME: ";
        std::cin >> _student.lname;
        std::cout << std::endl << "ENTER STUDENT MAJOR\n \tMAJOR: ";
        std::cin >> _student.major;
        std::cout << std::endl;
        std::cout << std::endl << "ENTER STUDENT AGE\n \tAGE: ";
        std::cin >> _student.age;
        std::cout << std::endl << "ENTER STUDENT CURRENT GPA\n \tGPA: ";
        std::cin >> _student.gpa;

        std::cout << std::endl << "THANK YOU FOR REGISTERING!\n \tYOUR NAME IS: \t" + _student.fname + ' ' + _student.lname;
        std::cout << std::endl << std::endl;
    }

    void change_name() {
        std::cout << "ENTER NEW NAME\n \tFIRST NAME: ";
        std::cin >> _student.fname;
        std::cout << "\tLAST NAME: ";
        std::cin >> _student.lname;
        std::cout << std::endl << "NAME CHANGE SUCCESSFUL\n NEW NAME: \t" + _student.fname + ' ' + _student.lname;
        std::cout << std::endl << std::endl;
    }
};

int main() {
    Department cd;
    cd.print_student();
    
    cd.create_student();
    cd.print_student();

    cd.change_name();
    cd.print_student();

    return 0;
}