#ifndef TREASURE_HUNT
#define TREASURE_HUNT

#define _CRT_SECURE_NO_WARNINGS

#define MAX_LIVES 10        // Maximum lives a player can have
#define MIN_LIVES 1         // Minimum lives a player can have
#define MIN_PATH 10         // Minimum path length
#define MAX_PATH 70         // Maximum path length
#define PATH_STEP 5         // Path length must be a multiple of this value
#define MAX_MOVES_PERCENT 0.75 // Max moves allowed as 75% of path length

// Structure to store player information
typedef struct {
    char symbol;                // Character symbol representing the player
    int lives;                  // Number of lives for the player
    int treasuresFound;          // Count of treasures found
    int history[MAX_PATH];       // Array storing past moves (1=visited, 0=not visited)
} PlayerInfo;

// Structure to store game configuration
typedef struct {
    int maxMoves;                // Maximum moves allowed
    int pathLength;              // Path length of the game
    int bombPositions[MAX_PATH]; // Array storing bomb placements (1=bomb, 0=no bomb)
    int treasurePositions[MAX_PATH]; // Array storing treasure placements (1=treasure, 0=no treasure)
} GameInfo;

// Function prototypes
void configurePlayer(PlayerInfo* player);
void configureGame(GameInfo* game, int playerLives);
void displayConfiguration(const PlayerInfo* player, const GameInfo* game);

#endif // !TREASURE_HUNT
