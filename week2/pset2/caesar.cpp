#include <iostream>
#include <cctype>
#include <string.h>

using namespace std;

bool only_digits(string key);
char rotate(char plainChar, int key);

int main(int argc, char*argv[])
{

    // Checks if command line argument is valid
    if (argc == 2 && only_digits(argv[1]))
    {
        // Converts string to integer
        int key = stoi(argv[1]);

        string plainText;

        // Prompt user for plaintext
        cout << "plaintext:  ";
        getline(cin, plainText);

        // Convert plaintext characters into ciphertext
        cout << "ciphertext: ";
        for (int i = 0; i < plainText.length(); i++)
        {
            cout << rotate(plainText[i], key);
        }


        return 0;
    }
    else
    {
        cout << "Usage: ./caesar key";
        return 1;
    }
}

bool only_digits(string key)
{
    bool digitCheck = false;

    for (int i = 0; i < key.length(); i++)
    {
        // Check if the user input only contains digits from 0-9
        if (key[i] >= 48 && key[i] <= 57)
        {
            digitCheck = true;
        }
        else
        {
            digitCheck = false;
            break;
        }
    }
    
    return digitCheck;
}

char rotate(char plainChar, int key)
{
    char cipherChar;

    // Using Caesar's 'Algorithm' to shift characters according to the key
    if (islower(plainChar))
    {
        cipherChar = (plainChar + key - 97) % 26;
        cipherChar += 97;
        return cipherChar;
    }
    else if (isupper(plainChar))
    {
        cipherChar = (plainChar + key - 65) % 26;
        cipherChar += 65;
        return cipherChar;
    }
    else
    {
        return plainChar;
    }
}