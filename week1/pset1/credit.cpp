#include <iostream>
#include <cmath>

using namespace std;

int count_digits(long long num, int digits);
bool verification(long long num, int digits);
int card_type(long long num, int digits);

int main()
{
    long long num;
    int digits;

    // Prompt for user input
    do
    {
        cout << "Number: ";
        cin >> num;
        digits = count_digits(num, digits);
    } 
    while (digits < 13 || digits == 14 || digits > 16);
    
    // if card is legitimate, determine type of card
    if (verification(num, digits))
    {
        card_type(num, digits);
    }
    else
    {
        cout << "INVALID";
    }
}

// counts total digits
int count_digits(long long num, int digits)
{
    return digits = floor(log10(num) + 1);
}

// Luhn's Algorithm verification
bool verification(long long num, int digits)
{
    // Store num in array format (store a duplicate variable)
    int firstArray[digits];
    int secondArray[digits];
    long long numStore = num;

    for (int i = 0; i < digits; i++)
    {
        firstArray[i] = 2 * (numStore % 10);
        secondArray[i] = numStore % 10;
        numStore /= 10;
    }

    // Sum of the digits of alternating numbers starting from the second last digit
    int firstSum = 0;
    

    for (int i = 1; i < digits; i+=2)
    {
        int firstDigit = 0;
        int secondDigit = 0;

        if (firstArray[i] <= 9)
        {
            firstSum += firstArray[i];        
        }
        else
        {
            firstDigit = firstArray[i] % 10;
            secondDigit = (firstArray[i] / 10) % 10;    
        }

        firstSum = firstSum + firstDigit + secondDigit;
    }
    
    // Sum of the second alternate numbers starting from the last digit
    int secondSum = 0;
    
    for (int i = 0; i < digits; i+=2)
    {
        secondSum += secondArray[i];
    }

    // Sum of firstSum and secondSum
    int totalSum = firstSum + secondSum;

    // Check if number is valid
    if (totalSum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int card_type(long long num, int digits)
{
    // Store num in array format (store a duplicate variable)
    int thirdArray[digits];
    long long numStore = num;

    for (int i = 0; i < digits; i++)
    {
        thirdArray[i] = numStore % 10;
        numStore /= 10;
    }

    // Extracting the first two digits of num
    int firstDigit = thirdArray[digits - 1];
    int secondDigit = thirdArray[digits - 2];

    int sumTwo = firstDigit * 10 + secondDigit;

    // Check if first two digits correspond to recognized card companies
    if (sumTwo == 34 || sumTwo == 37)
    {
        cout << "AMEX";
    }
    else if (sumTwo >= 51 && sumTwo <= 55)
    {
        cout << "MasterCard";
    }
    else if (sumTwo >= 40 && sumTwo <= 49)
    {
        cout << "VISA";
    }
    else
    {
        cout << "INVALID";
    }
    return 0;
}