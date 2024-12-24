#include <iostream>
#include <fstream>
#include <variant>
#include <vector>
#include <string>

struct student{
    std::string name;
    char gender;
    std::string major;
    float gpa;
    int credits_taken;
};

void change_major(student &studentx, std::string n_major){
    studentx.major = n_major;
    studentx.gpa = 2.1;
}

void change_name(student &studentx, std::string n_name) {
    studentx.name = n_name;
}

void print_student(student &studentx){
    std::cout << &studentx << '\n';
    std::cout << studentx.name << '\n';
    std::cout << studentx.gender << '\n';
    std::cout << studentx.major << '\n';
    std::cout << studentx.gpa << '\n';
    std::cout << studentx.credits_taken << '\n';
}

std::ostream& operator<<(std::ostream& os, student& s) {
    os << "Name: " << s.name << "\tGender: " << s.gender 
    << "\tMajor: " << s.major << "\tGPA: " << s.gpa 
    << "\tCredits Taken: " << s.credits_taken;
    return os;
};

void save_to_file(student studentx, std::ofstream& file){
    file << studentx << std::endl;
    std::cout << "\nDATA WRITTEN TO FILE SUCCESSFULLY!" << std::endl;
}

void check_file(std::ofstream& file) {
    std::string LOG;
    (file.is_open()) ? (LOG = "FILE IS OPEN") : (LOG = "FILE CLOSED");
    std::cout << LOG;
    std::cout << std::endl << std::endl;
}

int main() {
    /*
    std::vector<student> docs;
    

    student student1;
    student1.name = "Daniel Jeremiah";
    student1.gender = 'M';
    student1.major = "Biochemistry";
    student1.gpa = 3.1;
    student1.credits_taken = 32;

    std::ofstream file;
    file.open("text.txt", std::ios::app);
    check_file(file);
    save_to_file(student1, file);

    print_student(student1);
    std::cout << std::endl;

    change_major(student1, "Journalism");
    print_student(student1);
    std::cout << std::endl;
    save_to_file(student1, file);

    change_name(student1, "Aniyah Lindo");
    print_student(student1);
    std::cout << std::endl;
    save_to_file(student1, file);


    file.close();
    check_file(file);/**/

    std::ifstream _file ("text.txt");

    std::vector<std::string> names;

    std::string input;

    while(std::getline(_file, input)) {
        names.push_back(input);
    }

    for (std::string n: names) {
        std::cout << '{' << n << '}' << ",\t\n";
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "NUMBER OF ELEMENTS: " << names.size();


    return 0;
}