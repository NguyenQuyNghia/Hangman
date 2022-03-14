#include <iostream>
#include <string>
#include <ctime>
using namespace std;


string WORDS_LIST[] { "book", "car", "cat", "balance", "notebook", "hangman", "home", "moon"
                      "school", "class", "child", "uniform" };
string chooseWord();
bool contains(string secretWord, char guess);
string update(string guessedWord, string secretWord, char guess);
void renderGame(string guessedWord, int badGuessCount);
char readAGuess();

const int MAX_BAD_GUESS = 7;

int main()
{
    srand(time(NULL));
    string secretWord = chooseWord();
    string guessedWord = string(secretWord.length(), '-');
    int badGuessCount = 0;
    do {
        renderGame(guessedWord, badGuessCount);
        char guess = readAGuess();
        if (contains(secretWord, guess))
        {
                guessedWord = update(guessedWord, secretWord, guess);
                cout<<guessedWord<<endl;
        }
        else
        {
            badGuessCount++;
            cout<<guessedWord<<endl;
        }
    } while (badGuessCount < 7 && secretWord != guessedWord);
    renderGame(guessedWord, badGuessCount);
    if (badGuessCount < 7)
    {
        cout << "Congratulations! You win!";
    }
    else
    {
        cout << "You lost. The correct word is " << secretWord;
    }
}
string chooseWord() {
    int index = rand() % 9 + 1;
    return WORDS_LIST[index];
}
void renderGame(string guessedWord,int badGuessCount) {
    switch (badGuessCount)
    {
    case 0:
        cout<< " ------------- \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " ----- \n";
        break;
    case 1:
        cout<< " ------------- \n";
        cout<< " |           | \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " ----- \n";
        break;
    case 2:
        cout<< " ------------- \n";
        cout<< " |           | \n";
        cout<< " |           O \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " ----- \n";
        break;
    case 3:
        cout<< " ------------- \n";
        cout<< " |           | \n";
        cout<< " |           O \n";
        cout<< " |           | \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " ----- \n";
        break;
    case 4:
        cout<< " ------------- \n";
        cout<< " |           | \n";
        cout<< " |           O \n";
        cout<< " |          /| \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " ----- \n";
        break;
    case 5:
        cout<< " ------------- \n";
        cout<< " |           | \n";
        cout<< " |           O \n";
        cout<< " |          /|\\   \n";
        cout<< " | \n";
        cout<< " | \n";
        cout<< " ----- \n";
        break;
    case 6:
        cout<< " ------------- \n";
        cout<< " |           | \n";
        cout<< " |           O \n";
        cout<< " |          /|\\   \n";
        cout<< " |          / \n";
        cout<< " | \n";
        cout<< " ----- \n";
        break;
    case 7:
        cout<< " ------------- \n";
        cout<< " |           | \n";
        cout<< " |           O \n";
        cout<< " |          /|\\    \n";
        cout<< " |          / \\    \n";
        cout<< " | \n";
        cout<< " ----- \n";
        break;
    }
}
string update(string guessedWord, string secretWord, char guess)
{
    for(int i=0; i< secretWord.length(); i++) {
        if (secretWord[i] == guess) {
            guessedWord[i] = guess;
        }
    }
    return guessedWord;
}
char readAGuess()
{
    char guess;
    cin >> guess;
    return guess;
}
bool contains(string secretWord, char guess)
{
    for (int i=0;i<secretWord.size();i++)
    {
        if (secretWord[i]==guess)
        {
            return true;
        }
    }
    return false;
}
