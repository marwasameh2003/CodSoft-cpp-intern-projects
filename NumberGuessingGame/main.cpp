#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void game()
{
    cout << "Welcome to Number Guessing Game :) \n";
    cout << "You need to guess a number between 1 and 10\n";
    srand(time(nullptr)); // Seed the random number generator
    int random_number = rand() % 10 + 1;
    int guess;

    do
    {
        cout << "Enter your guess :";
        cin >> guess;
        if (guess < random_number)
        {
            cout << "too low, try again\n";
        }
        else if (guess > random_number)
        {
            cout << "too high, try again\n";
        }
    } while (guess != random_number);
    cout << "Yes!! you guessed correct! the random number is " << random_number << "\n";
}

int main()
{
    game();
    return 0;
}
