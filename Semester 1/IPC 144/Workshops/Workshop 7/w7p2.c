#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <treasurehunt.h>



int main(void) {
    PlayerInfo player = { 0 }; // Initialize player structure
    GameInfo game = { 0 };     // Initialize game structure

    printf("================================\n");
    printf("        Treasure Hunt!          \n");
    printf("================================\n\n");


        configurePlayer(&player);
        configureGame(&game, player.lives);
        displayConfiguration(&player, &game);
      
      
    printf("======================================\n");
    printf("\n~ Get ready to play TREASURE HUNT! ~\n");
    printf("======================================\n");

    playGame(&player, &game);
    return 0;
}


8
