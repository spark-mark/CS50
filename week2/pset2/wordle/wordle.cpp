#include <iostream>
#include <cctype>
#include <string.h>
#include <time.h>

using namespace std;

// each of the text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, char*argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        cout << "Usage: ./wordle wordsize";
        return 1;
    }

    int wordsize = 0;

    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    if (stoi(argv[1]) >= 5 && stoi(argv[1]) <= 8)
    {
        wordsize = stoi(argv[1]);
    }
    else
    {
        cout << "Error: wordsize must be either 5, 6, 7, or 8";
        return 1;
    }

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN "This is WORDLE50" RESET "\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG
        for (int i = 0; i < wordsize; i++)
        {
            status[i] = 0;
        }

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);
        
        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    // print the game's result
    if (won == true)
    {
        cout << "You won!";
    }
    else
    {
        cout << "The " << wordsize << "-letter word was: " << choice << ". Thanks for playing!";
    }

    return 0;
}

string get_guess(int wordsize)
{
    string guess = "";

    // ensure users actually provide a guess that is the correct length
    do
    {
        cout << "Input a " << wordsize << "-letter word: ";
        cin >> guess;
    }
    while (guess.length() != wordsize);

    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;

    // compare guess to choice and score points as appropriate, storing points in status
    for (int i = 0; i < wordsize; i++)
    {
        if (guess[i] == choice[i])
        {
            status[i] = EXACT;
            score += 2;
            continue;
        }
        
        // check if guess letter appears anywhere in choice but is not in the same position
        for (int j = 0; j < wordsize; j++)
        {
            if (guess[i] == choice[j] && guess[i] != choice[i])
            {
                status[i] = CLOSE;
                score += 1;
                continue;
            }
        }
    }

    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    // print word character-for-character with correct color coding, then reset terminal font to normal
    for (int i = 0; i < wordsize; i++)
    {
        int color = status[i];
        switch (color)
        {
            case 0:
                printf(RED "%c" RESET, guess[i]);
                break;

            case 1:
                printf(YELLOW "%c" RESET, guess[i]);
                break;

            case 2:
                printf(GREEN "%c" RESET, guess[i]);
                break;
        }
    }

    printf("\n");
    return;
}
