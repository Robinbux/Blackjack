#include "helperFunctions.h"

int checkIfDrawn(int cardID, const int drawnCards[]) {
    for (int i = 0; i < 24; i++) {
        if (drawnCards[i] == cardID) {
            return 1;
        }
    }
    return 0;
}

int hasTen(int currentPlayer[], int ln) {
    for (int i = 0; i < ln; i++) {
        if (currentPlayer[i] % 13 == 9 || currentPlayer[i] % 13 == 10 || currentPlayer[i] % 13 == 11 ||
            currentPlayer[i] % 13 == 12) {
            return 1;
        }
    }
    return 0;
}

int checkForBreak(int value) {
    if (value > 21) {
        printf("BUST! The bank won this round!\n");
        return 1;
    }
    if (value == 42) {
        printf("Blackjack!\n");
        return 1;
    }
    if (value == 21) {
        printf("21! Maximum reached!\n");
        return 1;
    }
    return 0;
}