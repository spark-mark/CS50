#include <iostream>
#include <cctype>
#include <string.h>

using namespace std;

string replace(string word);

// Checks if the user command meets the requirements
// char*argv[] is to prevent an compiler error. Not sure how it works but it does
int main( int argc, char*argv[])
{
    if (argc == 2)
    {
        cout << replace(argv[1]) << "\n";
        return 0;
    }
    else
    { 
        cout << "Usage: ./no-vowels word";
        return 1;
    }
}

// Checks if there are vowels (except u) and replaces them with l33tsp36k
string replace(string word)
{
    char vocab[5] = {'6', '3', '1', '0'};

    for (int i = 0; i < word.length(); i++)
    {
        char c = word[i];

        if (c == 'a' || c == 'A')
        {
            word[i] = vocab[0];
        }
        else if (c == 'e' || c == 'E')
        {
            word[i] = vocab[1];
        }
        else if (c == 'i' || c == 'I')
        {
            word[i] = vocab[2];
        }
        else if (c == 'o'|| c == 'O')
        {
            word[i] = vocab[3];
        }
        else
        {
            continue;
        }
    }
    return word;
}