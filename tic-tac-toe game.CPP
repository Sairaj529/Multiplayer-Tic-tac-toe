#include<stdio>
#include<stdlib>
#include<iostream>
#include<conio>
#include<ctype>
#include<string>

using namespace std;
char matrix[3][3];
float win=0.0,loss=0.0,tot=0.0;

inline char check();
inline void get_move_from_player();
inline void get_move_from_computer();
inline void initialize();
inline void display();
inline void bonus();

inline int coin_toss()
{  char *coin[2];
   coin[0]="heads";
   coin[1]="tails";
   char str[20];
   gets(str);
   char ch=tolower(*str);
    randomize();
    int decider=rand()%2;
    //printf("deciders val is %d coin val is %c expression %d",decider,*coin[decider],*coin[decider]==ch);
    if(*coin[decider]==ch)
    return 1;
    else
    return 0;
    }



int main()
{
   char ch[20];
    char done=' ';
    randomize();
     do
     {

    printf("\nThis is a simple game of tic-tac-toe.");
    printf("\nYour X's");
    printf("\nYou will be playing against the computer.");
    printf("\nBut for you to win.....");
    printf("\nYou need to make sure its a draw");
    printf("\nThen you will get a nice message");
    printf("\n**************************************\n");
    printf("\nThis game contains a BONUS ROUND which basically switches places\n 1]This can either be benificial to you or the computer or no effect at all!!!!!");
    printf("\nSo enjoy yourself!!!!!!!");
    printf("\nEnter to continue:");
    getchar();
    printf("\nLets get started by a coin toss:");
    printf("\nChoose heads or tails");
    int cointossindx=coin_toss();
    char decision,des[20];
    if(cointossindx){
    printf("\nYou won,do you want to start or not(y/n)?");
    gets(des);
    decision=*des;
    }
    //////////////////////////////////
    else
    {
    randomize();
    register int val=rand()%2;
    if(val){
    printf("\nI'm gonna start");
    decision='n';
    }
    else
    {
    printf("\nI'll be nice,you start the game");
    decision='y';
    }
    }
       //printf("\nDecision %c and expression %d",decision,decision=='y');
      initialize();
      display();
      register int val=0;
      do
      {


         if(decision=='y'){
         get_move_from_player();
         display();}
         else{
         cout<<"\nMy turn";
         get_move_from_computer();
         display();
         }

         done=check(); ++val;
          if((val==9)&&(done==' '))
     {
       printf("\nIts a DRAW you WON!!!!");
       ++win;
       goto label;
       }

         if(done!=' ') break;
         if(decision=='y'){
         cout<<"\nMy turn";
         get_move_from_computer();
         display();}
         else{
         get_move_from_player();
         display();
         }

       if(val==5)
       {
         printf("\nBONUS ROUND:");
         bonus();
         display();
         }
         ++val;
         done=check();

         }while(done==' ');

           if(done=='X'){
            printf("\nYour adopted!!!!");
            ++loss;
           }
          else{
          printf("\nYour still adopted!!!!");
      printf("Nice......");
         ++loss;

        }
          label:
        display();

        do
        {
        ++tot;
        cout<<"\nWin % is "<<win/tot*100<<"%\nLoss % is "<<loss/tot*100<<'%';
        cout<<"\nTotal no.of times played "<<tot;
        printf("\nDo you want to continue?");
        gets(ch);

         }while(strcmpi(ch,"y")&&strcmpi(ch,"n"));

        }while(strcmpi(ch,"n"));

      return 0;
      }

      inline void initialize()
      {
         for(register int i=0;i<3;i++)
          for(register int j=0;j<3;j++)
            matrix[i][j]=' ';
        }

        inline void get_move_from_player()
        {
           register int x,y;
           char c;
            label:
           do
           {
            printf("\nenter the coordinates of the location(format: x,y where x and y are whole numbers):");
            scanf("%d %*c %d",&x,&y);
            --x;--y;
            }while(!(1<=x<=3||1<=y<=3));

            if(matrix[x][y]!=' ')
            {
              printf("\nThis location is already taken");
              printf("\nPlease enter the coordiantes again:");
             goto label;
             }
             matrix[x][y]='X';
           }

        inline void get_move_from_computer()
         {
      register int i=0,j=0;

      label:
       randomize();
       i=rand()%3;j=rand()%3;
       if(matrix[i][j]==' ')
        matrix[i][j]='O';
        else
        goto label;

          }

         inline void display()
         {
          register int t;
          printf("\n");
          for(t=0;t<3;t++)
          {
            printf("\t%c  | %c  | %c",matrix[t][0],matrix[t][1],matrix[t][2]);
            if(t<2) printf("\n\t---|----|---\n");
           }
           printf("\n");
          }

       inline char check()
        {
           //checking rows
           for(int i=0;i<3;i++)
             if((matrix[i][0]==matrix[i][1])&&(matrix[i][1]==matrix[i][2]))
               return matrix[i][0];

           //checking column
           for(int i=0;i<3;i++)
             if((matrix[0][i]==matrix[1][i])&&(matrix[1][i]==matrix[2][i]))
               return matrix[0][i];
         if((matrix[0][0]==matrix[1][1])&&(matrix[1][1]==matrix[2][2]))
            return matrix[0][0];
         if((matrix[0][2]==matrix[1][1])&&(matrix[1][1]==matrix[2][0]))
            return matrix[0][2];
            return ' ';
         }

       inline void bonus()
       {   cout<<"\nswapping time";
           randomize();
           int x,y,a,b;
           do{
           x=rand()%3,y=rand()%3,a=rand()%3,b=rand()%3;
           }while((x==a)&&(y==b));
           printf("\n(%d,%d) was swapped with (%d,%d)",x+1,y+1,a+1,b+1);
           if(matrix[x][y]!=' '||matrix[a][b]!=' ')
           {
               char temp=matrix[x][y];
               matrix[x][y]=matrix[a][b];
               matrix[a][b]=temp;
               }
          }



