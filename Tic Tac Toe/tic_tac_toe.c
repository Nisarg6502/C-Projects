//preprocessor directives
#include<stdio.h> // header files 
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

//function prototypes
void SinglePlayer();
void TwoPlayer();
void get_player_name(char *player, char symbol);
void Rules();
void Game();
int GetInput();
void display(char arr[]);

//structure
struct chances{
    char array[9];
    bool used[9];
} chance;

//heading design function
void heading()
{
    //creates design
    for(int i = 0; i<3; i++)
    {   
        int n = (i==1)?30:40;
        for(int j=0; j<n; j++)
        {
            if(i==1 && j==16)
            {
                printf("  HELLO  #");
            } 
            printf("#");
        }
        printf("\n");
    }
    printf("\t\tTIC TAC TOE\n");
    for(int i = 0; i<40; i++)
    {
        printf("*");
    }
    return;
}

//menu function
void menu()
{
    printf("\n   Please select the number of Players:\n");
    printf("   1. Single Player - V/S AI (in development)\n");
    printf("   2. Two Player Game - V/S Friend \n");
    int no_of_players;

        //keeps prompting until right value is provided
        while (1)
        {
            printf("   Enter number of players(\"1\" or \"2\"): ");
            scanf("%i",&no_of_players);
            printf("\n   You selected, %i", no_of_players);
            if(no_of_players == 1 || no_of_players == 2)
            {
                break;
            }
        }
         if(no_of_players == 1)
         {
             SinglePlayer();
         }
         else
         {
             TwoPlayer();
         }   
}

//function for single player game
void SinglePlayer()
{
    printf("\n   You selected, Single Player - V/S AI");
    printf("\n   Sorry, this game is Under Development!");
}

//function for two player game
void TwoPlayer()
{
    printf("\n   You selected, Two Player Game - V/S Friend");
    char *first_player;
    char *second_player;
    
    get_player_name(first_player, 'X');
    get_player_name(second_player, 'O');

    Rules();
    Game();
}

void Game()
{
    char s;
    printf("\n\n   Enter \"S\" to Start:\n");
    scanf(" %c", &s);
    //keeps prompting user for input to start
    while(toupper(s) != 'S' )
    {
        printf("\n\n   Enter \"S\" to Start:\n");
        scanf(" %c", &s);
    }
    printf("\n   Game Begins!");
    
    //declaring arrays for struct
    for(size_t i = 0; i < 9; i++)
    {
        chance.array[i] = i+1+'0';
        chance.used[i] = false;
        printf("%c", chance.array[i]);
    }

    bool Xturn = true;//if true then playerX will play
    int no_of_turns = 9;
    bool game_over = false;

    //game begins
    while (game_over == false  && no_of_turns > 0)
    {        
        if (Xturn==true)
        {
            printf("\n   Player X enter a number: ");
            int input = GetInput();
            printf("%i", input);
            for (size_t i = 0; i < 9; i++)
            {
                if (chance.used[input-1]==false)
                {
                    break;
                }

                
            }
            chance.array[input-1] = 'X';
            chance.used[input-1] = true;
            
            
            display(chance.array);
            Xturn = false;
            no_of_turns--;
        }

        else{
            printf("\n   Player O enter a number: ");
            int input = GetInput();
            printf("%i", input);
            chance.array[input-1] = 'O';
            chance.used[input-1] = true;
            display(chance.array);
            Xturn = true;
            no_of_turns--;
        }
        
    }
    
    
}

//shows output of the game
void display(char arr[])
{
    printf("\n\t%c | %c | %c\n\t—— ——— ——\n\t%c | %c | %c\n\t—— ——— ——\n\t%c | %c | %c",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8] );
}
int GetInput()
{
    int x;
    scanf("%i", &x);
    return x;
}

//Rules of the game
void Rules()
{
    printf("\n\n   HOW TO PLAY:\n   1. There are 9 Blocks in this game, divided in 3 Rows and 3 Columns\n   2. Each Player is assigned a symbol.\n   3. Players take turns putting their marks in empty squares using the number pad.\n   4. The blocks are numbered as:\n\t1 | 2 | 3\n\t—— ——— ——\n\t4 | 5 | 6\n\t—— ——— ——\n\t7 | 8 | 9  \n   5. The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner.\n   6. When all 9 squares are full, the game is over.\n   7. If no player has 3 marks in a row, the game ends in a tie.");
}

//Gets the player name
void get_player_name(char *player, char symbol)
{
    printf("\n\nEnter the name of the Player%c (Less than 10 characters):", symbol);
    //allocate memory for players name
    player = (char *)malloc(sizeof(char)*10);
    scanf("%s", player);
    //check for null
    if(player == NULL)
    {
        return;
    }
    printf("The name of Player%c is: ", symbol);
    while (*player != '\0')
    {
        printf("%c", *(player));
        player++;
    }
}

//main function
void main()  
{   
    heading();    
    menu();
}   

