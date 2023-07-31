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
    int n = input.length();
    int number;
    int sum;

    for (int i = 0; i < input.length(); i++, n--)
    {
        number = (input[i] - 48) * 10^(n - 1);
        sum += number;
    }

    return sum;
}