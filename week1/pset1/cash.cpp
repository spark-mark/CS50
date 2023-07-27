#include <iostream>

using namespace std;

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum of coins and print total number of coins
    int coins = quarters + dimes + nickels + pennies;
    cout << coins;
}

int get_cents(void)
{
    int cents;
    do
    {
        cout << "Change owed:";
        cin >> cents;
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    int store = cents;
    
    while (store - 25 >= 0)
    {
        quarters++;
        store = store - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    int store = cents;

    while (store - 10 >= 0)
    {
        dimes++;
        store = store - 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    int store = cents;

    while (store - 5 >= 0)
    {
        nickels++;
        store = store - 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    int store = cents;

    while (store - 1 >= 0)
    {
        pennies++;
        store = store - 1;
    }
    return pennies;
}