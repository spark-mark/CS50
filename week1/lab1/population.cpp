#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int startSize;
    int endSize;
  
    // Prompt for start size
    do
    {
        cout << "Start Size: ";
        cin >> startSize;
    }
    while (startSize < 9);

    // Prompt for end size
    do
    {
        cout << "End Size: ";
        cin >> endSize;
    }
    while (endSize < startSize);
    
    int yearsPassed = 0;

    while (startSize < endSize)
    {
        startSize = startSize + startSize/3 - startSize/4;
        yearsPassed++;
        if (startSize >= endSize)
        {
            break;
        }

    }
    cout << "Years: " << yearsPassed;


}