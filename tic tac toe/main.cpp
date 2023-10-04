#include <iostream>
#include"dec.h"
using namespace std;

int main()
{
    int choice ;
    do
    {
         intro();
    take_turn();
    end_game();
    resetBoard();
    cout<<"Press 1 to play again or 0 to quit ";
    cin>>choice;
    }
    while(choice !=0);
    return 0;
}
