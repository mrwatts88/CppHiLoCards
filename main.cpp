#include <iostream>
#include "Deck.h"

using namespace std;

void showScore(int, int);
void getGuess(char &);
int getInitialSize();
void scoreRound(char, int, int, int &);

int main() {
    int deck[50];
    int score = 0;
    int currentCardPos = 0;
    int currentCardVal;
    int nextCardVal;
    char guess;

    int numCards = getInitialSize();
    initDeck(deck, numCards);
    shuffle(deck, numCards);

    // Start the game by dealing the first card
    currentCardVal = dealCard(deck, currentCardPos);

    while (numCards > currentCardPos) {
        showScore(score, currentCardVal);
        getGuess(guess);
        nextCardVal = dealCard(deck, currentCardPos);
        scoreRound(guess, nextCardVal, currentCardVal, score);
        currentCardVal = nextCardVal;
    }

    showScore(score, currentCardVal);
    return 0;
}

void showScore(int score, int currentCardVal){
    cout << "Score: " << score << "  Card: " << currentCardVal << endl;
}

void getGuess(char &guess){
    cout << "Will the next card be higher or lower? (h or l): ";
    cin >> guess;
}

int getInitialSize(){
    int numCards;
    // Get a valid size for the deck from user
    do {
        cout << "Enter the size of the deck (5 to 50): ";
        cin >> numCards;
    } while (numCards < 5 || numCards > 50);

    return numCards;
}

void scoreRound(char guess, int nextCardVal, int currentCardVal, int &score){
    if (guess == 'h' && nextCardVal > currentCardVal)
        score++;
    else if (guess == 'l' && nextCardVal < currentCardVal)
        score++;
    else
        score--;
}

