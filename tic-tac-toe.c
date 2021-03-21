#include<stdio.h>
#include<stdlib.h>

char a[9]={'1','2','3','4','5','6','7','8','9'};
char player1[10],player2[10];
int i,player;
void check(char);
/*void red ()
{
  printf("\033[1;31m");
}*/
void gamename()
{
  printf("\t\t\t\tTic Tac Toe\n");
}
void display()
{
   printf("\n\t\t\t---------------------------------\n");
   printf("\t\t\t|          |          |         |\n");
   printf("\t\t\t|    %c     |    %c     |    %c    |\n",a[0],a[1],a[2]);
   printf("\t\t\t|          |          |         |\n");
   printf("\t\t\t|-------------------------------|\n");
   printf("\t\t\t|          |          |         |\n");
   printf("\t\t\t|    %c     |    %c     |    %c    |\n",a[3],a[4],a[5]);
   printf("\t\t\t|          |          |         |\n");
   printf("\t\t\t|-------------------------------|\n");
   printf("\t\t\t|          |          |         |\n");
   printf("\t\t\t|    %c     |    %c     |    %c    |\n",a[6],a[7],a[8]);
   printf("\t\t\t|          |          |         |\n");
   printf("\t\t\t--------------------------------\n");

}
void symbol_name()
{
   printf("\tPlayer 1 symbol: X\n");
   printf("\tPlayer 2 symbol: O\n");
   printf("\tEnter player 1 name:");
   gets(player1);
   printf("\tEnter player 2 name:");
   gets(player2);


}
void start()
{
   //player;
   printf("\tEnter who will start the game : player 1 or player 2\n");
   scanf("%d",&player);
   //getchar();
}
void play()
{
    char position;
    if(player==1)
    {
      printf("\t%s enter the position\n",player1);
      scanf("%s",&position);
      check(position);
    }
    else if(player==2)
    {
      printf("\t%s enter the position\n",player2);
      scanf("%s",&position);
      check(position);
    }
}
void check(char position)
{
   int i;
   if(player==1)
   {
     for(i=0;i<9;i++)
     {
       if(a[i]==position)
       {
          a[i]='X';
          player=2;

       }
     }
   }
   else if(player==2)
   {
     for(i=0;i<9;i++)
     {
       if(a[i]==position)
       {
          a[i]='O';
          player=1;

       }
     }
   }

}
int decision()
{
  if((a[0]=='X' && a[1]=='X' && a[2]=='X') || (a[3]=='X' && a[4]=='X' && a[5]=='X')||(a[6]=='X' && a[7]=='X' && a[8]=='X') || (a[0]=='X' && a[3]=='X' && a[6]=='X') || (a[1]=='X' && a[4]=='X' && a[7]=='X')||(a[2]=='X' && a[5]=='X' && a[8]=='X'))
  return (2);
  else if((a[0]=='O' && a[1]=='O' && a[2]=='O') || (a[3]=='O' && a[4]=='O' && a[5]=='O')||(a[6]=='O' && a[7]=='O' && a[8]=='O') || (a[0]=='O' && a[3]=='O' && a[6]=='O')|| (a[1]=='O' && a[4]=='O' && a[7]=='O')||(a[2]=='O' && a[5]=='O' && a[8]=='O'))
  return(3);
  else if((a[2]=='X' && a[4]=='X' && a[6]=='X')||(a[0]=='X' && a[4]=='X' && a[8]=='X'))
  return (2);
  else if((a[2]=='O' && a[4]=='O' && a[6]=='O')||(a[0]=='O' && a[4]=='O' && a[8]=='O'))
  return (3);
  else if(a[0]!='1' && a[1]!='2' && a[2]!='3' && a[3]!='4' && a[4]!='5' &&a[5]!='6' && a[6]!='7' && a[7]!='8' && a[8]!='9')
  return (4);
  else
  return 5;

}
int main()
{

  int win,c,again=1;
system("clear");
while(again)
  {
     win=0;c=1;
     system("clear");
     gamename();
     display();
     symbol_name();
     start();
     play();

    while(c)  //here c means the game will continue untill someone win//
    {
      system("clear");
      gamename();
      display();
      play();
      win=decision();
      system("clear");
      display();
      if(win==2)
      {
         printf("\n\t\t\t%s You won the match\n\n",player1);
         c=0;
      }
      else if(win==3)
      {
        printf("\t\t%s You won the match\n\n",player2);
        c=0;
      }
      else if(win==4)
      {
        printf("\t\t This match is draw\n\t\tBoth of you played well!!\n\n");
        c=0;
      }
      else
      {
        c=1;
      }
    }   // end of while(c) loop//
    printf("Do you want to play again: If yes enter 1 otherwise enter 0\n");
    scanf("%d%*c",&again);
    if(again==1)
    {
    a[0]='1';a[1]='2';a[2]='3';a[3]='4';a[4]='5';a[5]='6';a[6]='7';a[7]='8';a[8]='9';
    }
  }
  //getchar();
  printf("\tTHANKS FOR PLAYING\n");

}

