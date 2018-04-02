#include <random>
#include "Deck.h"

using namespace std;

void initDeck(int deck[], int numCards) {
    for (int i = 0; i < numCards; i++)
        deck[i] = i;
}

void shuffle(int deck[], int numShuffles) {
    srand(time(NULL));

    for (int i = 0; i < numShuffles; i++) {
        int index1 = rand() % numShuffles;
        int index2 = rand() % numShuffles;

	swap(deck[index1], deck[index2]);
    }
}

int dealCard(int deck[], int &cardPos){
    return deck[cardPos++];
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
