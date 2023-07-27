#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1;
    string word2;
    
    cout << "Player 1: \n";
    cin >> word1;

    cout << "Player 2: \n";
    cin >> word2;

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        cout << "Player 1 wins!";
    }
    else if (score1 < score2)
    {
        cout << "Player 2 wins!";
    }
    else
    {
        cout << "Tie!";
    }
}

int compute_score(string word)
{
    int wordLength = word.length();

    // Converts all letters into uppercase
    for (int i = 0; i < wordLength; i++)
    {
    word[i] = toupper(word[i]);
    }
    
    // Converts all letters into ASCII and then sums total points
    int sum = 0;
    for (int i = 0, n = 0; i < wordLength; i++)
    {
        n = word[i] - 64 - 1;
        sum += POINTS[n];
    }
    return sum;
}