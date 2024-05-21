#include <iostream>
#include "Game.h"
using namespace std;
int main() {
    Game* Games[3];

    int ans;
    do {
        system("cls");
        cout<<"             \"Welcome to ARCADE\"             \n";
        cout<<"--------------------------------------------------\n";
        cout<<"\nChoose your game\n";
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"     1. \"Rock,Paper, Scissors\"             \n";
        cout<<"     2. \"Tic Tac Toe\"             \n";
        cout<<"     3. \"Connect4\"             \n";
        cout<<"--------------------------------------------------\n";
        cout<<"Enter a number between 1~3 : ";
        cin>>ans;
    }while (ans<1||ans>3);
    switch (ans) {
        case 1: {
            system("cls");
            Games[0]=new RockPaperScissors();
            Games[0]->play();
            delete Games[0];
            break;
        }
        case 2: {
            system("cls");
            Games[1]=new TicTacToe();
            Games[1]->play();

            delete Games[1];
            break;
        }
        case 3: {
            system("cls");
            Games[2]=new Connect4();
            Games[2]->play();
            delete Games[2];
            break;
        }
        default:
            cout<<"Error";
    }
    return 0;
}