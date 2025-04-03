#define _CRT_SECURE_NO_WARNINGS
#include<treasurehunt.h>

// Function to configure player settings
void configurePlayer(PlayerInfo* player) {
    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    // Get player symbol
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player->symbol); // Space before %c prevents issues with previous inputs

    // Get number of lives (validating input)
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player->lives);
        if (player->lives < MIN_LIVES || player->lives > MAX_LIVES) {
            printf("  Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
        }
    } while (player->lives < MIN_LIVES || player->lives > MAX_LIVES);

    // Initialize history array to 0 (no moves made)
    for (int i = 0; i < MAX_PATH; i++) {
        player->history[i] = 0;
    }

    printf("Player configuration set-up is complete\n\n");
}