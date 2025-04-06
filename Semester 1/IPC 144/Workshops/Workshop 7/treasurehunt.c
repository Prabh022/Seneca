#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<treasurehunt.h>


void displayBoard(const PlayerInfo* player, const GameInfo* game) {
    // Line 1 - Player's current position
    for (int i = 0; i < game->pathLength; i++) {
        if (player->history[i] == 1) {
            printf("%c", player->symbol);
        }
        else {
            printf(" ");
        }
    }
    printf("\n");

    // Line 2 - Game path
    for (int i = 0; i < game->pathLength; i++) {
        if (player->history[i] == 1) {
            if (game->bombPositions[i] && game->treasurePositions[i]) printf("&");
            else if (game->bombPositions[i]) printf("!");
            else if (game->treasurePositions[i]) printf("$");
            else printf(".");
        }
        else {
            printf("-");
        };
    }
    printf("\n");

    // Ruler lines
    for (int i = 1; i <= game->pathLength; i++) {
        if (i % 10 == 0) printf("|");
        else printf(" ");
    }
    printf("\n");
    for (int i = 1; i <= game->pathLength; i++) printf("%d", i % 10);
    printf("\n");
}

void playGame(PlayerInfo* player, GameInfo* game) {
    player->moves = game->maxMoves;

    while (player->lives > 0 && player->moves > 0) {
        displayBoard(player, game);

        printf("+---------------------------------------------------+\n");
        printf(" Lives: %2d | Treasures: %2d | Moves Remaining: %2d\n",
            player->lives, player->treasuresFound, player->moves);
        printf("+---------------------------------------------------+\n");

        int move;
        do {
            printf("Next Move [1-%d]: ", game->pathLength);
            scanf("%d", &move);
            if (move < 1 || move > game->pathLength)
                printf(" Out of Range!!!\n");
        } while (move < 1 || move > game->pathLength);

        move--; // Convert to 0-based index

        if (player->history[move]) {
            printf("===============> Dope! You've been here before!\n");
        }
        else {
            player->history[move] = 1;
            player->moves--;

            if (game->bombPositions[move] && game->treasurePositions[move]) {
                player->lives--;
                player->treasuresFound++;
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            }
            else if (game->bombPositions[move]) {
                player->lives--;
                printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            }
            else if (game->treasurePositions[move]) {
                player->treasuresFound++;
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            }
            else {
                printf("===============> [.] ...Nothing found here... [.]\n");
            }
        }
    }

    printf("##################\n# Game over! #\n##################\n");
    printf("You should play again and try to beat your score!\n");
}
