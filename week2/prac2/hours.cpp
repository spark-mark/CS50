#include <iostream>
#include <cctype>

using namespace std;

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks;
    
    // Prompt user for no. weeks taking CS50
    cout << "Number of weeks taking CS50: ";
    cin >> weeks;
    
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        cout << "Week " << i << " HW Hours: ";
        cin >> hours[i];
    }

    // Prompt user for which option they want
    char output;
    do
    {
        cout << "Enter T for total hours, A for average hours per week: ";
        cin >> output;
        output = toupper(output);
    } 
    while (output != 'T' && output != 'A');

    cout << calc_hours(hours, weeks, output) << " Hours\n";

    return 0;
}

float calc_hours(int hours[], int weeks, char output)
{
    // Calculate the total and average hours taken 
    float totalHours;
    float averageHours;

    for (int i = 0; i < weeks; i++)
    {
        totalHours += hours[i];
        averageHours += hours[i];
    }

    averageHours /= (float) weeks;

    if (output == 'T')
    {
        return totalHours;
    } 
    else
    {
        return averageHours;
    }
}