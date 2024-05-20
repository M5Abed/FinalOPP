#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include <ctime>
#include <thread>

using namespace std;
using namespace this_thread;

//HTP -> How to play

class Game {
protected:
    string Name;
    string Develper;
    string HTP;
public:
    void SetName(string);
    void SetDev(string);
    void SetHTP(string);
    void Welcome(string);
    void GetData();
    virtual int play()=0;
};

class RockPaperScissors:public Game{
protected:
    int Points=0;
    int Rand=0;
    int res=0;
public:
    int play();
    RockPaperScissors();
};

class Connect4: public Game {
private:
    int board[6][7];
    int player;
    int rowIndex;
    bool gameEnd;

public:
    Connect4();
    void handleInput(int input) ;

    void checkWinner() ;
    void draw() ;
    int play() ;

};

class TicTacToe:public Game{
private:
    char player = 'x';
    char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
public:
    TicTacToe();
    void printMatrix();
    char whoWin() ;
    int play() ;
};

#endif //GAME_H