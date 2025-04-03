#define _CRT_SECURE_NO_WARNINGS
#include<treasurehunt.h>

// Function to display the final configuration summary
void displayConfiguration(const PlayerInfo* player, const GameInfo* game) {
    printf("\n------------------------------------\n");
    printf(" TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf(" Symbol  : %c\n", player->symbol);
    printf(" Lives   : %d\n", player->lives);
    printf(" Treasure: [ready for gameplay]\n");
    printf(" History : [ready for gameplay]\n");

    printf("Game:\n");
    printf(" Path Length: %d\n", game->pathLength);

    // Print bomb placements
    printf(" Bombs    : ");
    for (int i = 0; i < game->pathLength; i++) {
        printf("%d", game->bombPositions[i]);
    }
    printf("\n");

    // Print treasure placements
    printf(" Treasure : ");
    for (int i = 0; i < game->pathLength; i++) {
        printf("%d", game->treasurePositions[i]);
    }
    printf("\n");
}
