/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  :TSZ WA WONG
Student ID#:152181228
Email      :twwong9@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#define MIN_NUM_OF_LIVES 1
#define MAX_NUM_OF_LIVES 10

#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70
#define MULTIPLE 5

#include <stdio.h>

struct PlayerInfo
{
    int numOfLives;
    char playerSymbol;
    int numOfTreasure;
    int historyPositions[MAX_PATH_LENGTH];
};

struct GameInfo
{
    int max_Num_Move;
    int pathLength;
    int bombPositions[MAX_PATH_LENGTH];
    int treasurePositions[MAX_PATH_LENGTH];
};


int main(void)
{
    int i = 0,j = 0,nextMove = 0;
    struct PlayerInfo player;
    struct GameInfo game;
    
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c",&player.playerSymbol);
    
    do {
        printf("Set the number of lives: ");
        scanf("%d",&player.numOfLives);
        
        if (player.numOfLives < MIN_NUM_OF_LIVES || player.numOfLives > MAX_NUM_OF_LIVES)
        {
            printf("     Must be between %d and %d!\n",MIN_NUM_OF_LIVES,MAX_NUM_OF_LIVES );
        }
        
    }while (player.numOfLives < MIN_NUM_OF_LIVES  || player.numOfLives > MAX_NUM_OF_LIVES);
        
    for (i = 0; i< MAX_PATH_LENGTH; i++)
    {
        player.historyPositions[i] = 0;
    }
    
    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n");
    printf("------------------\n");
    
    do {
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &game.pathLength);
        
        if (game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH || game.pathLength%MULTIPLE != 0)
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }

    }while (game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH || game.pathLength%MULTIPLE != 0);
    
    do{
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.max_Num_Move);
        if (game.max_Num_Move < player.numOfLives || game.max_Num_Move > (int)(game.pathLength*0.75))
        {
            printf("    Value must be between %d and %d\n", player.numOfLives,(int)(game.pathLength*0.75));
        }
        
    }while (game.max_Num_Move < player.numOfLives || game.max_Num_Move > (int)(game.pathLength*0.75));
    
    
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n",MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",game.pathLength);
    
    for (i = 0; i < game.pathLength/MULTIPLE; i++) // i : 0,1,2,3,4,5,6
    {
        if (MULTIPLE*(i+1)<10)
        {
            printf("   Positions [ %d- %d]: ",MULTIPLE*i+1,MULTIPLE*(i+1));
        }
        else if (MULTIPLE*i+1 < 10)
        {
            printf("   Positions [ %d-%d]: ",MULTIPLE*i+1,MULTIPLE*(i+1));
        }
        else
        {
            printf("   Positions [%d-%d]: ",MULTIPLE*i+1,MULTIPLE*(i+1));
        }
       
        for (j = MULTIPLE*i; j <= MULTIPLE*(i+1)-1; j++) // j : 0,1,2,3,..., game.pathLength-1
        {
            scanf("%d",&game.bombPositions[j]);
        }
        
    }
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n",MULTIPLE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",game.pathLength);
    
    for (i = 0; i < game.pathLength/MULTIPLE; i++) // i : 0,1,2,3,4,5,6
    {
        if (MULTIPLE*(i+1)<10)
        {
            printf("   Positions [ %d- %d]: ",MULTIPLE*i+1,MULTIPLE*(i+1));
        }
        else if (MULTIPLE*i+1 < 10)
        {
            printf("   Positions [ %d-%d]: ",MULTIPLE*i+1,MULTIPLE*(i+1));
        }
        else
        {
            printf("   Positions [%d-%d]: ",MULTIPLE*i+1,MULTIPLE*(i+1));
        }
        for (j = MULTIPLE*i; j <= MULTIPLE*(i+1)-1; j++) // j : 0,1,2,3,..., game.pathLength-1
        {
            scanf("%d",&game.treasurePositions[j]);
        }
        
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.playerSymbol);
    printf("   Lives      : %d\n", player.numOfLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d",game.bombPositions[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d",game.treasurePositions[i]);
    }
      
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n  ");
    for (i = 0; i<game.pathLength; i++)
    {
        printf("-");
        
    }
    printf("\n  ");
    
    for (i = 1; i<=game.pathLength; i++)
    {
       
        if (i%10 == 0)
        {
            printf("%d",i/10);
        }
        else
        {
            printf("|");
        }
        
    }
    printf("\n  ");
    
    for (i = 1,j=1 ; i<=game.pathLength; i++)
    {
        if (i%10 == 0)
        {
            printf("0");
            j -=10 ;
        }
        else
        {
            printf("%d",j);
        }
        j++;
    }
    
    while (player.numOfLives > 0 && game.max_Num_Move > 0)
    {
        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.numOfLives, player.numOfTreasure, game.max_Num_Move);
        printf("+---------------------------------------------------+\n");
        
        
        do{
            printf("Next Move [1-%d]: ",game.pathLength);
            scanf("%d",&nextMove);
            if (nextMove <1 || nextMove > game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }
            
        }while (nextMove <1 || nextMove > game.pathLength);
        
        
        
        if(player.historyPositions[nextMove-1] == 1)
        {
                printf("\n===============> Dope! You've been here before!\n");
        }
        else
        {
            if (game.bombPositions[nextMove-1] == 1 && game.treasurePositions[nextMove-1] == 1)
            {
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                player.numOfLives--;
                player.numOfTreasure++;
                game.max_Num_Move--;
                
            }
            else if (game.bombPositions[nextMove-1] == 0 && game.treasurePositions[nextMove-1] == 1)
            {
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
                player.numOfTreasure++;
                game.max_Num_Move--;
            }
            else if (game.bombPositions[nextMove-1] == 1 && game.treasurePositions[nextMove-1] == 0)
            {
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
                player.numOfLives--;
                game.max_Num_Move--;
                if (player.numOfLives == 0)
                {
                    printf("\nNo more LIVES remaining!\n");
                }
            }
            else
            {
                printf("\n===============> [.] ...Nothing found here... [.]\n");
                game.max_Num_Move--;
            }
        }

           
        
        player.historyPositions[nextMove-1] = 1;
        
        printf("\n  ");
        
        for (i = 0 ; i< game.pathLength ;i++)
        {
            if (i == nextMove-1)
            {
                printf("%c", player.playerSymbol);
                i = game.pathLength;
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n  ");
            
        for (i = 0 ; i< game.pathLength ;i++)
        {
            if (player.historyPositions[i] == 1)
            {
                
                if (game.bombPositions[i] == 1 && game.treasurePositions[i] == 1)
                {
                    printf("&");
                }
                else if (game.bombPositions[i] == 0 && game.treasurePositions[i] == 1)
                {
                    printf("$");
                }
                else if (game.bombPositions[i] == 1 && game.treasurePositions[i] == 0)
                {
                    printf("!");
                }
                else
                {
                    printf(".");
                }
            }
            else
            {
                printf("-");
            }
            
        }

        printf("\n  ");
        
        for (i = 1; i<=game.pathLength; i++)
        {
            
            if (i%10 == 0)
            {
                printf("%d",i/10);
            }
            else
            {
                printf("|");
            }
            
        }
        printf("\n  ");
        
        for (i = 1,j=1 ; i<=game.pathLength; i++)
        {
            if (i%10 == 0)
            {
                printf("0");
                j -=10 ;
            }
            else
            {
                printf("%d",j);
            }
            j++;
        }

    }
    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.numOfLives, player.numOfTreasure, game.max_Num_Move);
    printf("+---------------------------------------------------+\n");
    
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n");
    
    return 0;
}
