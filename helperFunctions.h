#ifndef BLACKJACK_HELPERFUNCTIONS_H
#define BLACKJACK_HELPERFUNCTIONS_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <memory.h>
    #include <ctype.h>
    #include <time.h>

    // initializeFunctions
    void initializeNewDeck(char deck[][3]);
    void initializeCardID(int cardID[52]);

    // getValueFunctions
    int getHandIndex(const int cardArray[]);
    int getHandLength(int currentPlayer[]);
    int getNumberOfAces(int currentPlayer[], int ln);
    int getValue(int currentPlayer[]);

    // checkFunctions
    int checkIfDrawn(int cardID, const int drawnCards[]);
    int hasTen(int currentPlayer[], int ln);
    int checkForBreak(int value);

    // utilities
    void drawCard(int currentPlayer[], int drawnCards[]);
    void printHand(int currentPlayer[], char *player, char deckValues[][3]);
    void capitalizeWord(char *word);
    void evaluateWinner(int playerVal, int dealerVal);
    void drawStartHand(int playersHand[], int dealersHand[], int drawnCards[]);
    void newGameMessage(int dealersHand[], char deckValues[][3]);

#endif
