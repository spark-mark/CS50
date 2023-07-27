#include <iostream>
#include <cctype>

using namespace std;

bool valid(string password);

// Prompt user for password input and calls the check password function
int main(void)
{
    string password;
    
    cout << "Enter your password: ";
    cin >> password;

    if (valid(password))
    {
        cout << "Your password is valid!\n";
    }
    else
    {
        cout << "Your password needs at least one uppercase letter, lower case letter, number and symbol!";
    }
}

// individually verifies if at minimum one of each requirement is met
bool valid(string password)
{
    bool upperCheck = false;
    bool lowerCheck = false;
    bool numberCheck = false;
    bool symbolCheck = false;
    
    for (int i = 0; i < password.length(); i++)
    {
        if (isupper(password[i]))
        {
            upperCheck = true;
        }

        if (islower(password[i]))
        {
            lowerCheck = true;
        }

        if (isdigit(password[i]))
        {
            numberCheck = true;
        }

        if (!isalnum(password[i]))
        {
            symbolCheck = true;
        }
    }
    
    if (upperCheck == true && lowerCheck == true && numberCheck == true && symbolCheck == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}