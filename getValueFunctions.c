#include "helperFunctions.h"

int getHandIndex(const int cardArray[]) {
    for (int i = 0; i < 24; i++) {
        if (cardArray[i] == 0) {
            return i;
        }
    }
    return 0;
}

int getHandLength(int currentPlayer[]) {
    for (int i = 0; i < 12; i++) {
        if (currentPlayer[i] == 0) {
            return i;
        }
    }
    return 0;
}

int getNumberOfAces(int currentPlayer[], int ln) {
    int numberOfAces = 0;
    for (int i = 0; i < ln; i++) {
        if (currentPlayer[i] % 13 == 0) {
            numberOfAces++;
        }
    }
    return numberOfAces;
}

int getValue(int currentPlayer[]) {
    int ln = getHandLength(currentPlayer);
    int nbrAces = getNumberOfAces(currentPlayer, ln);
    int totalVal = 0;
    int currentVal;

    // Check for potential Blackjack
    if (ln == 2 && nbrAces == 1 && hasTen(currentPlayer, ln)) {
        return 42;
    }

    for (int i = 0; i < ln; i++) {
        currentVal = currentPlayer[i] % 13 + 1;
        if (currentVal >= 2 && currentVal <= 9) {
            totalVal += currentVal;
        } else if (currentVal == 1){
            totalVal += 11;
        }
        else {
            totalVal += 10;
        }
    }
    // If val is greater than 21, all possible aces count as only 1 instead of 11
    while (totalVal > 21 && nbrAces > 0) {
        totalVal -= 10;
        nbrAces--;
    }

    return totalVal;
}

