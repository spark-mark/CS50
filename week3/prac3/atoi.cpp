#include <iostream>
#include <cctype>
#include <cmath>
#include <stdio.h>
#include <string.h>

using namespace std;

int convert(string input);

int main(void)
{
    string input;
    cout << "Enter a positive integer: ";
    cin >> input;

    // if input is a integer already, reject the input
    for (int i = 0, n = input.length(); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int n = input.length() - 1;
    int number = 0;
    int sum = 0;

    for (int i = 0; i < input.length(); i++, n--)
    {
        number = (input[i] - 48) * pow(10,n);
        sum += number; 
    }

    return sum;
}