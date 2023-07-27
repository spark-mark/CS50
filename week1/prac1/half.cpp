#include <iostream>

using namespace std;

double half(double bill, double tax, double tip);
// prompt for user bill, tax, and tip input
int main()
{
    double bill;
    double tax;
    double tip;

    do
    {
        cout << "Bill before tax and tip: ";
        cin >> bill;
    }
    while (bill < 0);
    
    do
    {
        cout << "Sale Tax Percent: ";
        cin >> tax;
    }
    while (tax < 0);

    do
    {
        cout << "Tip Percent: ";
        cin >> tip;
    }
    while (tip < 0);

    cout << "You will owe $" << half(bill, tax, tip) << " each!";

}

//percent conversion and split calculator
double half(double bill, double tax, double tip)
{
    tax = tax/100;
    tip = tip/100;
    double split;

    split = ((bill + bill * tax) + (bill + bill * tax) * tip)/2;
    return split;
}