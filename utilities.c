#include "helperFunctions.h"

void drawCard(int currentPlayer[], int drawnCards[]) {
    // int r = rand() % 20;
    int handPos = getHandIndex(currentPlayer);
    int drawnCardsPos = getHandIndex(drawnCards);
    int newCard;
    while (1) {
        newCard = rand() % 52 + 1;
        if (!checkIfDrawn(newCard, drawnCards)) {
            currentPlayer[handPos] = newCard;
            drawnCards[drawnCardsPos] = newCard;
            break;
        }
    }
}

void printHand(int currentPlayer[], char *player, char deckValues[][3]) {
    int ln = getHandLength(currentPlayer);
    int totalVal = 0;
    int currentVal;
    printf("%s Hand: ", player);
    for (int i = 0; i < ln; i++) {
        printf("%s ", deckValues[currentPlayer[i] - 1]);
    }
    putchar('\n');
}

void capitalizeWord(char *word) {
    int i = 0;

    while(word[i]) {
        word[i] = toupper(word[i]);
        i++;
    }
}

void evaluateWinner(int playerVal, int dealerVal) {
    // First check for Blackjacks
    if (playerVal == 42 && dealerVal == 42) {
        printf("Double Blackjack. The game is a draw");
    }
    else if (playerVal == 42) {
        printf("Blackjack! You won this round.");
    }
    else if (dealerVal == 42) {
        printf("The bank scores a blackjack. You lost!");
    }
    else if (dealerVal > 21) {
        printf("Bank busted. You won this round!");
    }
    else {
        printf("Your Score: %i, vs Banks Score: %i\n", playerVal, dealerVal);
        if (playerVal == dealerVal) {
            printf("Same Score. Draw.");
        }
        else {
            printf("%s won!", playerVal > dealerVal ? "You" : "Bank");
        }
    }
}

void drawStartHand(int playersHand[], int dealersHand[], int drawnCards[]) {
    drawCard(dealersHand, drawnCards);
    drawCard(playersHand, drawnCards);
    drawCard(playersHand, drawnCards);
}

void newGameMessage(int dealersHand[], char deckValues[][3]) {
    printf("Welcome to a new round of Blackjack!\n");
    printf("---Possible Actions---\n");
    printf("Hit: new card, Stand: no new card\n");
    printHand(dealersHand, "Dealers", deckValues);
    printf("Dealers Value: %i\n", getValue(dealersHand));
    printf("----------------------\n");
}