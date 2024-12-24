#include "game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

int end_game() {
    return 0;
}

template<typename T>
void Swap(T&x, T&y) {
    T temp = x;
    x = y;
    y = temp;
}


int play_game() {
    int guess;
    int random_number = rand() % 251;

    int arr[250];
    int guess_count = 1;

    std::cout << "YOUR JOB IS TO GUESS A RANDOM NUMBER WE KNOW OF.";
    std::cout << "\nGUESS THE NUMBER: ";
    
    while(true) {
        std::cin >> guess;
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (guess != random_number) {
            arr[guess_count++] = guess;

            std::cout << "Hint/answer, the number is: " << random_number << std::endl << std::endl; std::cout << "WRONG NUMBER. TRY AGAIN: "; } else { std::cout << "\nYOU WIN!"; std::cout << "\nNumber of guesses: " << guess_count << '\n'; for (int i = 0; i < guess_count; i++) { std::cout << arr[i] << '\t'; } return 0; }/* */
    }
    std::cout << "YOUR NUMBER IS: " << random_number;
}


int guess_game() {
    srand(time(NULL));
    int choice;
    
    do {
        std::cout << "\n0. QUIT \n1. PLAY \nEnter Choice: ";
        std::cin >> choice;

        switch(choice) {
            case 0:
                std::cout << "GOODBYE!";
                return 0;

            case 1:
                //std::cout << "LET'S PLAY!";
                play_game();
                break;
        }
    } while(choice != 0);
    return 0; 
}


std::vector<std::string> name = {"Daniel", "Aniyah", "Joseph", "Jeremiah"};

int main() {
    for (int i = 0; i < name.size(); i++) {
        std::cout << name[i] << '\t';
    }

    std::cout << "\nCapacity is: " << name.capacity();
    std::cout << "\nName Size is: " << name.size() << "\n\n\n";

    name.push_back("David");

    for (int i = 0; i < name.size(); i++) {
        std::cout << name[i] << '\t';
    }

    std::cout << "\nCapacity is: " << name.capacity();
    std::cout << "\nName Size is: " << name.size() << "\n\n\n";

    return 0;
}