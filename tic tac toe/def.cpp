#include<iostream>
#include"dec.h"

using namespace std;
string board[9]={" "," "," "," "," "," "," "," "," "};
int player = 1;
int position = 0;

void intro()
{
    cout<<"press [Enter] to begin: ";
    getchar();
    cout<<"\n";

    cout<<"\n";
    cout<<"***********\n";
    cout<<"Tic-Tac-Toe\n";
    cout<<"***********\n";

    cout<<"Player 1) X\n";
    cout<<"Player 2) O\n";

    cout<<"The 3x3 grid is shown below: \n\n";
    cout<<"     |     |     \n";
    cout<<"  1  |  2  |  3  \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  4  |  5  |  6  \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  7  |  8  |  9  \n\n";

}

bool is_winner()
{
    bool winner = false;
    if(((board[0]==board[1])&& (board[1]==board[2])&&board[0]!=" ")||
        ((board[3]==board[4])&&(board[4]==board[5])&&board[3]!=" ")||
        ((board[6]==board[7])&&(board[7]==board[8])&&board[6]!=" "))
    {
        winner = true;
    }
    else if(((board[0]==board[3])&& (board[3]==board[6])&&board[0]!=" ")||
        ((board[1]==board[4])&&(board[4]==board[7])&&board[1]!=" ")||
        ((board[2]==board[5])&&(board[5]==board[8])&&board[2]!=" "))
    {
        winner = true;
    }
    else if(((board[0]==board[4])&& (board[4]==board[8])&&board[0]!=" ")||
        ((board[2]==board[4])&&(board[4]==board[5])&&board[2]!=" "))
    {
        winner = true;
    }
}

bool filled_up()
{
    bool filled = true;
    for(int i = 0 ; i<9;i++)
    {
        if(board[i]==" ")
        {
            filled=false;
        }
    }
    return filled;
}
void draw()
{
    cout<<"     |     |     \n";
    cout<<"  "<<board[0]<<"  |  "<<board[1]<<"  |  "<<board[2]<<"  \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[3]<<"  |  "<<board[4]<<"  |  "<<board[5]<<"  \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[6]<<"  |  "<<board[7]<<"  |  "<<board[8]<<"  \n";
}


void set_position()
{
    cout<<"Player "<<player<<"'s (Enter: (1:9))";
    while(!(cin>>position))
    {
        cout<<"Please enter a valid number between (1-9)\n";
    }
    cin.clear();
    cin.ignore();
    while(board[position-1]!=" ")
    {
        cout<<"Oops, that position is already filled\nTry again\n";
        cout<<"Player "<<player<<"'s (Enter: (1:9))";
        cin>>position;
        cout<<"\n";
    }
}
void update_board()
{
    if(player%2==1)
    {
        board[position-1]="X";
    }
    else
    {
        board[position-1]="O";
    }
}
void change_player()
{
    if(player ==1)
    {
        player++;
    }
    else
    {
        player--;
    }
}
void take_turn()
{
    while(!is_winner()&& !filled_up())
    {
        set_position();
        update_board();
        change_player();
        draw();
    }
}

void end_game()
{
    if(is_winner())
    {
        cout<<"There is a winner!\n";
    }
    else if(filled_up())
    {
        cout<<"It is a tie\n";
    }
}
void resetBoard()
{
    for(int i = 0 ; i<9;i++)
    {
        board[i]=" ";
    }
}
