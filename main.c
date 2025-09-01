#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define POLE_Y 3
#define POLE_X 5

void show_pole(char poles [][POLE_X]);
void set_pole(char to [][POLE_X], char value, int y, int x);
bool isBoardFull(char pole[][POLE_X]);
bool check_to_win(char pole[][POLE_X], char role);

struct Player
{
    char name[100];
    char role;
    bool inWin;
};

typedef struct Player player;

int main()
{
    srand(time(NULL));

    int rand_x;
    int rand_y;
    int values[] = {0, 2, 4};

    char in_start;
    int choice_in_game;
    printf("Start game? (Y/N): ");
    in_start = getchar();
    getchar(); 

    if((in_start != 'Y') && (in_start != 'y'))
    {
        exit(0);
    }


    player pl1;
    pl1.inWin;

    player pl2;
    strcpy(pl2.name, "Max");
    pl2.inWin;

    while (pl1.role != 'X' && pl1.role != 'x' && pl1.role != 'O' && pl1.role != 'o')
    {
        printf("Choice your role: ");   

        pl1.role = getchar();   
        getchar(); 
    }
    
    if (pl1.role == 'X' || pl1.role == 'x')
    {
        pl2.role = 'o';
    }else{
        pl2.role = 'x';
    }

    printf("Enter your name: ");
    fgets(pl1.name, sizeof(pl1.name), stdin);
    pl1.name[strcspn(pl1.name, "\n")] = 0;
    printf("Your name: %s \n", pl1.name);



    char pole[POLE_Y][POLE_X]={
        " | | ",
        " | | ",
        " | | " };
    
    

        
    while (!isBoardFull(pole))
    {
        

        scanf("%d", &choice_in_game);
        
        switch (choice_in_game)
        {
        case 1:
            set_pole(pole, pl1.role, 0 ,0);
            show_pole(pole);
            break;
        case 2:
            set_pole(pole, pl1.role, 0 ,2);
            show_pole(pole);
            break;
        case 3:
            set_pole(pole, pl1.role, 0 ,4);
            show_pole(pole);
            break;
        case 4:
            set_pole(pole, pl1.role, 1 ,0);
            show_pole(pole);
            break;
        case 5:
            set_pole(pole, pl1.role, 1 ,2);
            show_pole(pole);
            break;
        case 6:
            set_pole(pole, pl1.role, 1 ,4);
            show_pole(pole);
            break;
        case 7:
            set_pole(pole, pl1.role, 2 ,0);
            show_pole(pole);
            break;
        case 8:
            set_pole(pole, pl1.role, 2 ,2);
            show_pole(pole);
            break;
        case 9:
            set_pole(pole, pl1.role, 2 ,4);
            show_pole(pole);
            break;
        default:
            break;
        }
        
        rand_x = values[rand() % 3]; 
        rand_y = (rand() % 3); 

        do {
            rand_x = values[rand() % 3]; 
            rand_y = rand() % 3;         
        } while (pole[rand_y][rand_x] != ' ');

        set_pole(pole, pl2.role, rand_y, rand_x);
        printf("rand_x: %d\n", rand_x);
        printf("rand_y: %d\n", rand_y);
        

        
        
    }
    
    show_pole(pole);
    
    pl1.inWin = check_to_win(pole, pl1.role);
    
    pl2.inWin = check_to_win(pole, pl2.role);


    if (pl1.inWin)
    {
        printf("%s is win!\n", pl1.name);
    }
    else if (pl2.inWin)
    {
        printf("%s is win!\n", pl2.name);
    }
    else
    {
        printf("draw!\n");
    }

    return 0;
}

void show_pole(char poles [][POLE_X])
{
    for (int i = 0; i < POLE_Y; i++)
    {
	    for(int j = 0 ; j < POLE_X; j++)
	    {
		    printf("%c", poles[i][j]);
	    }
        printf("\n");
    }
}

void set_pole(char to [][POLE_X], char value, int y, int x)
{
    to[y][x] = value;
}


bool isBoardFull(char pole[][POLE_X]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j <= 4; j += 2)
            if (pole[i][j] == ' ')
                return false;
    return true;
}

bool check_to_win(char pole[][POLE_X], char role)
{
            if (( (pole[0][0] == role) && (pole[0][2] == role) && (pole[0][4] == role) ) || ((pole[1][0] == role) && (pole[1][2] == role) && (pole[1][4] == role)) || ((pole[2][0] == role) && (pole[2][2] == role) && (pole[2][4] == role)))
                return true;
            else if (( (pole[0][0] == role) && (pole[1][0] == role) && (pole[2][0] == role) ) || ((pole[0][2] == role) && (pole[1][2] == role) && (pole[2][2] == role)) || ((pole[0][4] == role) && (pole[1][4] == role) && (pole[2][4] == role)))
                return true;
            else if (( (pole[0][0] == role) && (pole[1][2] == role) && (pole[2][4] == role) ) || ((pole[0][4] == role) && (pole[1][2] == role) && (pole[2][0] == role)))
                return true;
            else
                return false;
}