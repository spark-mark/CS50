#include <iostream>

using namespace std;


int main(void)
{
    // prompts user for a value from 1-8
    int height;
    do 
    {
        cout << "Height: ";
        cin >> height;
    }
    while (height < 1 || height > 8);
    
    //prints number of rows
    for (int i = 0; i < height; i++)
    {
        //prints number of spaces on one row
        for (int j = 0; j < height - i - 1; j++)
        {
            cout << " ";
        }
        
        //prints number of # on the left on one row
        for (int j = 0; j < i + 1; j++)
        {
            cout << "#";
        }

        // prints center column
        for (int j = 0; j < 2; j++)
        {
            cout << " ";
        }

        // prints number of # on the right on one row
        for (int j = 0; j < i + 1; j++)
        {
            cout << "#";
        }
        cout << "\n";
    }

}