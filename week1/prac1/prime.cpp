#include <iostream>
#include <cmath>

using namespace std;

bool prime(int number);

// prompt for user min and max value input
int main (void)
{
    int min;
    do
    {
        cout << "Minimum: ";
        cin >> min;
    }
    while (min < 1);

    int max;
    do
    {
        cout << "Maximum: ";
        cin >> max;
    } 
    while (min > max);

    // increases number variable starting from user's min to max
    for (int number = min; number <= max; number++)
    {
        if (prime(number))
        {
            cout << number << "\n";
        }
    }
}

// checks if the number is a prime
bool prime(int number)
{
    int i = 2;
    while (number%i != 0)
    {
        i++;
    }
    if (number == i)
    {
        return number;
    }
    else 
    {
        return false;
    }
}