#define _CRT_SECURE_NO_WARNINGS
#include<treasurehunt.h>

// Function to configure game settings
void configureGame(GameInfo* game, int playerLives) {
    printf("GAME Configuration\n");
    printf("------------------\n");

    // Get path length (must be a multiple of PATH_STEP and within valid range)
    do {
        printf("Set the path length (a multiple of %d between %d-%d): ", PATH_STEP, MIN_PATH, MAX_PATH);
        scanf("%d", &game->pathLength);
        if (game->pathLength < MIN_PATH || game->pathLength > MAX_PATH || game->pathLength % PATH_STEP != 0) {
            printf("  Must be a multiple of %d and between %d-%d!!!\n", PATH_STEP, MIN_PATH, MAX_PATH);
        }
    } while (game->pathLength < MIN_PATH || game->pathLength > MAX_PATH || game->pathLength % PATH_STEP != 0);

    // Calculate the maximum allowed moves (75% of path length)
    int maxMovesLimit = (int)(game->pathLength * MAX_MOVES_PERCENT);

    // Ensure max moves is at least equal to the player's lives
    if (maxMovesLimit < playerLives) {
        maxMovesLimit = playerLives;
    }

    // Get max moves (validating input)
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game->maxMoves);
        if (game->maxMoves < playerLives || game->maxMoves > maxMovesLimit) {
            printf("  Value must be between %d and %d\n", playerLives, maxMovesLimit);
        }
    } while (game->maxMoves < playerLives || game->maxMoves > maxMovesLimit);

    // Get bomb placements
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where 1=BOMB, and 0=NO BOMB.\n");
    for (int i = 0; i < game->pathLength; i += PATH_STEP) {
        printf(" Positions [%2d-%2d]: ", i + 1, i + PATH_STEP);
        for (int j = 0; j < PATH_STEP; j++) {
            scanf("%d", &game->bombPositions[i + j]);
        }
    }
    printf("BOMB placement set\n");

    // Get treasure placements
    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where 1=TREASURE, and 0=NO TREASURE.\n");
    for (int i = 0; i < game->pathLength; i += PATH_STEP) {
        printf(" Positions [%2d-%2d]: ", i + 1, i + PATH_STEP);
        for (int j = 0; j < PATH_STEP; j++) {
            scanf("%d", &game->treasurePositions[i + j]);
        }
    }
    printf("TREASURE placement set\n");
    printf("GAME configuration set-up is complete...\n");
}