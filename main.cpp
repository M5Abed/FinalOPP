#include "Game.h"
using namespace std;

int main() {
    int ans;
    do {
        cout<<"--------------------------------------------------\n";
        cout<<"             \"Welcome to ARCADE\"             \n";
        cout<<"--------------------------------------------------\n";
        cout<<"\nChoose your game\n";
        cout<<"--------------------------------------------------\n";
        cout<<"     1. \"Rock,Paper, Scissors\"             \n";
        cout<<"     2. \"Tic Tac Toe\"             \n";
        cout<<"     3. \"Hang Man\"             \n";
        cout<<"     4. \"Connect Four\"             \n";
        cout<<"--------------------------------------------------\n";
        cin>>ans;
    }while (ans<1||ans>6);
    switch (ans) {
        case 1: {
            system("cls");
            auto *RPS = new RockPaperScissors;
            RPS->play();
            delete RPS;
        }
        case 2: {
            system("cls");
            auto *XO =new TicTacToe;
            XO->play();
            delete XO;
        }
        case 4: {
            system("cls");
            auto *c4 = new Connect4;
            c4->play();
            delete c4;
        }
        default:
            cout<<"Error";
    }
    return 0;
}
