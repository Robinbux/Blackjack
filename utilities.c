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

// Converts an abbreviation to a full expression. Example: H8 -> Eight of Hearts
char *convertToExpr(char *abbreviation) {
        //printf("LOL");
    char *fullExpr = malloc(sizeof(char) * 18); // Longest expression possible contains 17 chars
    switch (abbreviation[1]) {
        case '2': strcpy(fullExpr, "Two of "); break;
        case '3': strcpy(fullExpr, "Three of "); break;
        case '4': strcpy(fullExpr, "Four of "); break;
        case '5': strcpy(fullExpr, "Five of "); break;
        case '6': strcpy(fullExpr, "Six of "); break;
        case '7': strcpy(fullExpr, "Seven of "); break;
        case '8': strcpy(fullExpr, "Eight of "); break;
        case '9': strcpy(fullExpr, "Nine of "); break;
        case 'T': strcpy(fullExpr, "Ten of "); break;
        case 'J': strcpy(fullExpr, "Jack of "); break;
        case 'Q': strcpy(fullExpr, "Queen of "); break;
        case 'K': strcpy(fullExpr, "King of "); break;
        case 'A': strcpy(fullExpr, "Ace of "); break;
    }
    switch (abbreviation[0]) {
        case 'S': strcat(fullExpr, "Spades"); break;
        case 'C': strcat(fullExpr, "Clubs"); break;
        case 'H': strcat(fullExpr, "Hearts"); break;
        case 'D': strcat(fullExpr, "Diamonds"); break;
    }
    return fullExpr;
}

void printHand(int currentPlayer[], char *player, char deckValues[][3]) {
    int ln = getHandLength(currentPlayer);
    int totalVal = 0;
    int currentVal;
    printf("%s Hand: ", player);
    for (int i = 0; i < ln; i++) {
        printf("%s; ", convertToExpr(deckValues[currentPlayer[i] - 1]));
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
    printf("Welcome to a new round of Blackjack!\n\n");
    printf("---Possible Actions---\n");
    printf("Hit: new card, Stand: no new card\n\n");
    printHand(dealersHand, "Dealers", deckValues);
    printf("Dealers Value: %i\n", getValue(dealersHand));
    printf("----------------------\n");
}