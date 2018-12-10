#include "helperFunctions.h"

int main() {
    // New seed for rand function
    srand(time(NULL));

    char deckValues[52][3];
    int cardID[52];
    int drawnCards[24] = {0};
    int playersHand[12] = {0};
    int dealersHand[12] = {0};
    int finalPlayerVal;
    int finalDealerVal;
    char action[10];

    initializeNewDeck(deckValues);
    initializeCardID(cardID);

    drawStartHand(playersHand, dealersHand, drawnCards);
    newGameMessage(dealersHand, deckValues);

    // Players turn
    while (1) {
        printHand(playersHand, "Your", deckValues);
        printf("Your Value: %i\n\n", getValue(playersHand));
        if (checkForBreak(getValue(playersHand))) {
            break;
        }
        printf("Next Action: ");
        scanf("%s", action);
        capitalizeWord(action);
        if (strcmp(action, "STAND") == 0) {
            break;
        } else if (strcmp(action, "HIT") == 0) {
            drawCard(playersHand, drawnCards);
        } else {
            printf("\nNo valid option!\n\n");
            printf("---Possible Actions---\n");
            printf("Hit: new card, Stand: no new card\n\n");
        }
    }
    finalPlayerVal = getValue(playersHand);

    // If the player busted, the bank doesn't need to continue
    if (finalPlayerVal > 21) {
        return 0;
    }

    // Dealers turn
    while (1) {
        printf("----------------------\n");
        printHand(dealersHand, "Dealers", deckValues);
        printf("Dealers Value: %i\n", getValue(dealersHand));
        if (getValue(dealersHand) > 16) {
            break;
        }
        else {
            printf("New card!\n");
            drawCard(dealersHand, drawnCards);
        }
    }
    finalDealerVal = getValue(dealersHand);

    evaluateWinner(finalPlayerVal, finalDealerVal);

    return 0;
}