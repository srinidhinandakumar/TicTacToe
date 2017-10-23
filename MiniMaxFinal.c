#include <stdio.h>
#include <string.h>

int posmax, posmin;
char a[10]={'0','1','2','3','4','5','6','7','8','9'};

void print_Board()
{
    int i;
    for (i = 1; i <= 9; i++)
    {
        printf("\t%c ",a[i]);

        if ((i) % 3 == 0)
        printf("\n");
    }
    printf("\n");
}

int check_win(char a[])
{

    if ((a[1] == 'X' && a[2] == 'X' && a[3] == 'X') ||
        (a[4] == 'X' && a[5] == 'X' && a[6] == 'X') ||
        (a[7] == 'X' && a[8] == 'X' && a[9] == 'X') ||
        (a[1] == 'X' && a[4] == 'X' && a[7] == 'X') ||
        (a[2] == 'X' && a[5] == 'X' && a[8] == 'X') ||
        (a[3] == 'X' && a[6] == 'X' && a[9] == 'X') ||
        (a[1] == 'X' && a[5] == 'X' && a[9] == 'X') ||
        (a[3] == 'X' && a[5] == 'X' && a[7] == 'X'))
    {
        return 1;
    }
    else if((a[1] == 'O' && a[2] == 'O' && a[3] == 'O') ||
            (a[4] == 'O' && a[5] == 'O' && a[6] == 'O') ||
            (a[7] == 'O' && a[8] == 'O' && a[9] == 'O') ||
            (a[1] == 'O' && a[4] == 'O' && a[7] == 'O') ||
            (a[2] == 'O' && a[5] == 'O' && a[8] == 'O') ||
            (a[3] == 'O' && a[6] == 'O' && a[9] == 'O') ||
            (a[1] == 'O' && a[5] == 'O' && a[9] == 'O') ||
            (a[3] == 'O' && a[5] == 'O' && a[7] == 'O'))
    {
        return -1;
    }
    else return 0;
}

int check_Draw(char a[])
{
    int i,flag=0;
    if(check_win(a)==0)
    {
        for(i=1;i<=9;i++)
        {
            if(a[i]!='X'&&a[i]!='O')
            {
                flag=1;
                return 0;
            }
        }
    }

    else if(flag!=1)
    return 1;
}

int mini_max(int player, char a[], int n)
{
    int i, score, j;
    char ch='h';
    int max = -200;
    int min = 200;

    int chk = check_win(a);
    if (chk == 1)
        return 1;
    else if (chk == (-1))
        return -1;
    else if (chk = check_Draw(a))
        return 0;

    for (i = 1; i <= 9; i++)
    {
        if(a[i]!='X'&&a[i]!='O')
        {
            ch=a[i];
            if(player == 2)//computer plays second
            {
                a[i]='O';
                score = mini_max(1,a,n+1);

                a[i]=ch;
                if(score < min)
                {
                    min = score;
                    if (n == 0)
                        posmin = i;
                }
            }
            else if (player == 1)//computer plays first
            {
                a[i]='X';
                score = mini_max(2,a, n + 1);
                a[i]=ch;
                if (score > max)
                {
                    max = score;
                    if (n == 0)
                        posmax = i;
                }
            }
        }
    }

    if (player == 1)
        return max;
    else return min;
}


// 1 is X, 2 is O
int main()
{
    int i, j, input, opt,choice=0,playerId=0;
    int chk1,chk2,chk;
    /*for(i = 1; i <= 9; i++)
        a[i] = '_';*/
    printf("\n\n--------TIC TAC TOE USING MINIMAX ALGORITHM--------\n\n");
    printf("\tPlayer:X\n\tComputer:O\n");
    printf("\nChoose to play first: 1/2 : ");
    scanf("%d",&choice);

    if(choice==1)
    {
        playerId=1;//player is X and plays first
    }
    else playerId=2;

    if(playerId==1)//User plays first
    {
        printf("\nBoard:\n");
            print_Board();

            for(i = 1; i <= 9; i++)
            {
                if (i % 2 == 1)
                 {
                     printf("\nPlayer X give input: ");
                     scanf("%d", &input);
                     a[input] = 'X';
                     printf("\nBoard:\n");
                    print_Board();
                 }
                else
                    {
                        posmax = -1;
                        posmin = -1;
                        printf("\nComputer's Move:\n");
                        opt = mini_max(2,a, 0);
                        a[posmin]='O';
                        printf("\nBoard:\n");
                        print_Board();


                    }

                chk1 = check_win(a);
                chk = check_Draw(a);
                if (chk1 == 1)
                {
                    printf("Player X: YOU win!\n");
                    break;
                }
                else if (chk1 == -1)
                {
                    printf("Player O: Computer wins!\n");
                    break;
                }
                else if(i == 9 && chk1 == 0 && chk != 0)
                printf("The game ends in a tie!\n");
            }

        /*else if ((chk == 0) && (i != 9))
        {
            posmax = -1;
            posmin = -1;
            if(i % 2 == 0)
            {
                opt = mini_max(1, board, 0);
                printf("Optimal move for player X is %d\n", posmax);
            }
            else
            {
            opt = mini_max(2, board, 0);
            printf("Optimal move for player O is %d\n", posmin);
            }
        }*/

    }
    else if(playerId==2)//Computer plays first
    {

                printf("Board:\n");
                print_Board();

                for(i = 1; i <= 9; i++)
                {
                    if (i % 2 == 0)
                     {
                         printf("Player X give input:\n");
                         scanf("%d", &input);
                         a[input] = 'X';
                         printf("Board:\n");
                        print_Board();
                     }
                    else
                        {
                            posmax = -1;
                            posmin = -1;
                            printf("Computer's Move:\n");
                            opt = mini_max(2,a, 0);
                            a[posmin]='O';
                            printf("Board:\n");
                            print_Board();


                        }

                    chk2 = check_win(a);
                    chk = check_Draw(a);
                    if (chk2 == 1)
                    {
                        printf("Player X: You wins!\n");
                        break;
                    }
                    else if (chk2 == -1)
                    {
                        printf("Player O: Computer win!\n");
                        break;
                    }
                    else if (i==9&&chk2 == 0 && chk != 0)
                    printf("The game ends in a tie!\n");
                }
    }
    return 0;
}
