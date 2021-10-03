
#include<iostream>
using namespace std;
void enterBoard (char Board[10][10], int rows, int columns)
{
    char repeat;
    int liveRow, liveColumn;
    for (int i =0;i<rows;i++)
    {
        for (int j=0; j<columns;j++)
        {
            Board[i][j]='-';
        }
    }
    cout <<"Enter the live cells\n";
    cout <<"please enter the row/column between 1 and 10\n";
    do {
        do{
            cout <<"In row: ";
            cin >> liveRow;
        } while (liveRow<1 || liveRow>rows);
        do {
            cout <<"In column: ";
            cin >>liveColumn;
        }while (liveColumn<1||liveColumn>columns);
        Board[(liveRow-1)][(liveColumn-1)]='*';
        cout << "Would you like to add another cell?\n";
        cout<< "Y=y=yes or N=n=no"<<endl;
        cin >> repeat;
    }while (repeat=='y'||repeat=='Y');
}
int Neighbors (char Board[10][10],int x,int y)
{
    int neighbor=0;
    if (Board[x-1][y-1]=='*') ++neighbor;
    if (Board[x-1][y]=='*') ++neighbor;
    if (Board[x-1][y+1]=='*') ++neighbor;
    if (Board[x][y-1]=='*') ++neighbor;
    if (Board[x][y+1]=='*') ++neighbor;
    if (Board[x+1][y-1]=='*') ++neighbor;
    if (Board[x+1][y]=='*') ++neighbor;
    if (Board[x+1][y+1]=='*') ++neighbor;
    return neighbor;
}
void displayBoard (char Board[10][10], int rows, int columns)
{
    for (int i =0;i<rows;i++)
    {
        cout << "[";
        for (int j=0;j<columns;j++)
        {
            cout << Board[i][j];
        }
        cout << "]"<<endl;
    }
}

void copyBoard (char current_board[10][10], char next_board[10][10])
{
    for (int i =0;i<10;i++)
    {
        for (int j =0;j<10;j++)
        {
            next_board[i][j]=current_board[i][j];
        }
    }
}
int liveCells(char Board[10][10])
{
    int live =0;
    for (int i=0;i<10;i++)
    {
        for (int j =0;j<10;j++)
        {
            if (Board[i][j]=='*')
                ++live;
        }
    }
    return live;
}
void playGame (char currentBoard[10][10],char nextBoard[10][10],int rows, int columns)
{
    int numGenerations;
    int neighbors;
    int creature;
    cout << "How many generations do you want to play?\n";
    cin >> numGenerations;
    
    for (int generation=0;generation<numGenerations;generation++)
    {
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<columns;j++)
            {
                neighbors= Neighbors(currentBoard,i,j);
                if(neighbors<2)
                    nextBoard[i][j]='-';
                else if (neighbors>3)
                    nextBoard[i][j]='-';
                else if (neighbors==3)
                    nextBoard[i][j]='*';
                else if (currentBoard[i][j]=='*' && neighbors==2)
                    nextBoard[i][j]='*';
                else nextBoard[i][j]='-';
            }
        }
        cout << "Generation: "<<(generation+1)<<endl;
        creature=liveCells(nextBoard);
        cout <<"Number of creatures: "<<creature<<endl;
        displayBoard(nextBoard, rows, columns);
        cout <<endl;
        if (creature==0)
        { cout <<"Because no further changes occur, the program stopped"<<endl;
            break;
        }
        copyBoard(nextBoard, currentBoard);
       
}
}

int main ()
{
    char currentBoard[10][10];
    char nextBoard[10][10];
    const int cells=10;
    enterBoard(currentBoard, cells, cells);
    displayBoard(currentBoard, cells, cells);
    copyBoard(currentBoard, nextBoard);
    playGame(currentBoard, nextBoard, cells, cells);
    return 0;
}

/*Enter the live cells
 please enter the row/column between 1 and 10
 In row: 2
 In column: 2
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 3
 In column: 3
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 4
 In column: 4
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 5
 In column: 5
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 6
 In column: 6
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 7
 In column: 7
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 8
 In column: 8
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 9
 In column: 9
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 9
 In column: 2
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 8
 In column: 3
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 7
 In column: 4
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 6
 In column: 5
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 5
 In column: 6
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 4
 In column: 7
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 3
 In column: 8
 Would you like to add another cell?
 Y=y=yes or N=n=no
 y
 In row: 2
 In column: 9
 Would you like to add another cell?
 Y=y=yes or N=n=no
 n
 [----------]
 [-*------*-]
 [--*----*--]
 [---*--*---]
 [----**----]
 [----**----]
 [---*--*---]
 [--*----*--]
 [-*------*-]
 [----------]
 How many generations do you want to play?
 10
 Generation: 1
 Number of creatures: 16
 [----------]
 [----------]
 [--*----*--]
 [---****---]
 [---*--*---]
 [---*--*---]
 [---****---]
 [--*----*--]
 [----------]
 [----------]
 
 Generation: 2
 Number of creatures: 28
 [----------]
 [----------]
 [---****---]
 [--******--]
 [--**--**--]
 [--**--**--]
 [--******--]
 [---****---]
 [----------]
 [----------]
 
 Generation: 3
 Number of creatures: 12
 [----------]
 [----**----]
 [--*----*--]
 [----------]
 [-*------*-]
 [-*------*-]
 [----------]
 [--*----*--]
 [----**----]
 [----------]
 
 Generation: 4
 Number of creatures: 0
 [----------]
 [----------]
 [----------]
 [----------]
 [----------]
 [----------]
 [----------]
 [----------]
 [----------]
 [----------]
 
 Because no further changes occur, the program stopped
 Program ended with exit code: 0

*/
