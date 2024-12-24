#include <iostream>


class User
{
private:
    static long user_count;
    int age;
public:
    User(int user_age);
    ~User();
    int get_user_count();
};

long User::user_count = 0;


User::User(int user_age) :age(user_age){
    user_count++;
};

User::~User() {
    int user_age = 0;
    user_count--;
}

int User::get_user_count() {
    return user_count;
}

int main() {
    User md(0);

    std::cout << "[USER COUNT]: " << md.get_user_count() << std::endl << std::endl;
    User user1(1), user2(2), user3(3), user4(4), user5(5);
    std::cout << "[USER COUNT]: " << md.get_user_count() << std::endl << std::endl;
    md.~User(); 
    std::cout << "[USER COUNT]: " << md.get_user_count() << std::endl << std::endl;
    return 0;
    std::cout << "[USER COUNT]: " << md.get_user_count() << std::endl << std::endl;
}