#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

int index(int totalLetters, int totalWords, int totalSentences);

int main(void)
{
    string text;
    int totalLength = 0;
    int totalLetters = 0;
    int totalWords = 0;
    int totalSentences = 0;

    cout << "Text: ";
    getline(cin, text);


    // Calculate the total length of the text
    totalLength = text.length();

    // Calculate the total amount of letters of the text
    for (int i = 0; i < totalLength; i++)
    {
        // Counts letters
        if (isalpha(text[i]))
        {
            totalLetters++;
        }
    }

    // Calculate the total words in the text
    for (int i = 0; i < totalLength; i++)
    {
        // Counts the total spaces + 1 = totalWords
        if (text[i] == ' ')
        {
            totalWords++;
        }
    }
    totalWords++;

    // Calculate the total sentences in the text
    for (int i = 0; i < totalLength; i++)
    {
        // Counts the total ending punctuation in the text
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            totalSentences++;
        }
    }

    // Output grade level based on boundaries
    if (index(totalLetters, totalWords, totalSentences) < 1)
    {
        cout << "Before Grade 1";
    }
    else if (index(totalLetters, totalWords, totalSentences) >= 16)
    {
        cout << "Grade 16+";
    }
    else
    cout << "Grade " << index(totalLetters, totalWords, totalSentences);
}

int index(int totalLetters, int totalWords, int totalSentences)
{
    double L = 0;
    double S = 0;
    double I = 0;
    
    // Calculating the average number of letters/ sentences per 100 words of text
    L = (double) totalLetters / totalWords * 100;
    S = (double) totalSentences / totalWords * 100;

    // Coleman-Liau Index Formula
    I = 0.0588 * L - 0.296 * S - 15.8;
    return round(I);
}