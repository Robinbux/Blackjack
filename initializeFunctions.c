#include "helperFunctions.h"

void initializeNewDeck(char deck[][3]) {
    const char *suits[] = {"S", "C", "H", "D"}; // S = Spades, C = Clubs, H = Hearts, D = Diamonds
    const char *values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
    char singleCard[3];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            strcpy(singleCard, "");
            strcat(singleCard, suits[i]);
            strcat(singleCard, values[j]);
            strcpy(deck[i * 13 + j], singleCard);
        }
    }
}

void initializeCardID(int cardID[52]) {
    for (int i = 0; i < 52; i++) {
        cardID[i] = i + 1;
    }
}
