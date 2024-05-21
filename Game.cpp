#include "Game.h"
//main class
void Game::SetName(string name) {
    this->Name = std::move(name);
}
void Game::SetDev(string dev) {
    this->developer =std::move(dev);
}
void Game::SetHTP(string HTP) {
    this->HTP = std::move(HTP);
}
void Game::Welcome(string GameName) {
    system("cls");
    cout<<"----------------------------------------\n";
    cout<<"     \"Welcome to "<< GameName << "\"             \n";
    cout<<"----------------------------------------\n";
    sleep_for(1s);
}
void Game::GetData() {
    cout<<"The Game Name: "<<Name<<endl;
    sleep_for(1s);
    cout << "\ndeveloped by: " << developer << endl;
    sleep_for(1s);
    cout<<"\nHow to play this game: "<<HTP<<endl;
    system("pause");
}

Game::~Game() {
    delete this;
} //Destructor delete the object

int main(); //main declaration to cam make it as return in classes below

//Rock paper scissors
RockPaperScissors::RockPaperScissors() {
    RockPaperScissors::SetName("Rock Paper Scissors");
    RockPaperScissors::SetDev("Mohamed Abed, Sherif Hasan");
    RockPaperScissors::SetHTP(
            "\n\t\t\t\"You will play this game vs PC \n     You will choose ROCK,PAPER OR SCISSORS and the PC will choose one also and will see who will get more points\" \n\nEnter (e) to quit the game\n");
    RockPaperScissors::GetData();
}
int RockPaperScissors::play() {
    bool draw=false;
    int pc=0;
    string input,output;
    RockPaperScissors::Welcome(this->Name);
    do {
        srand(time(nullptr));
        Rand = rand();
        res = Rand % (3 - 1 + 1) + 1;
        cout<<"Rock,Paper or Scissors?\t(You can use shortcuts by first letter :D)\n";
        cin>>input;
        if (input[0]<97) {
            for (char & i : input)
                i+=32;
        }
        if (input[0]=='e') {
            system("cls");
            return main();
        }
        //1 is reference for rock, 2 for paper, 3 for scissors
        if ((input[0]=='r'&&res==1)||(input[0]=='p'&&res==2)||(input[0]=='s'&&res==3)) {
            draw=true;
            sleep_for(0.5s);
            cout<<"The PC chose the same :D, We gonna play again\n";
            sleep_for(1.5s);
            system("cls");
        }
        else if ((input[0]=='r'&&res==2)) {
            cout<<"You: "<<"Rock\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Paper\n";
            sleep_for(0.5s);
            cout<<"PC Win !!\n";
            pc++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
        else if ((input[0]=='r'&&res==3)) {
            cout<<"You: "<<"Rock\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Scissors\n";
            sleep_for(0.5s);
            cout<<"You Win !!\n";
            Points++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
        else if ((input[0]=='p'&&res==1)) {
            cout<<"You: "<<"Paper\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Rock\n";
            sleep_for(0.5s);
            cout<<"You Win !!\n";
            Points++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
        else if ((input[0]=='p'&&res==3)) {
            cout<<"You: "<<"Paper\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Scissors\n";
            sleep_for(0.5s);
            cout<<"PC Win !!\n";
            pc++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
        else if ((input[0]=='s'&&res==1)) {
            cout<<"You: "<<"Scissors\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Rock\n";
            sleep_for(0.5s);
            cout<<"PC Win !!\n";
            pc++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
        else if ((input[0]=='s'&&res==2)) {
            cout<<"You: "<<"Scissors\n";
            sleep_for(0.5s);
            cout<<"PC: "<<"Paper\n";
            sleep_for(0.5s);
            cout<<"You Win !!\n";
            Points++;
            sleep_for(1.5s);
            system("cls");
            cout<<"-------------------------\n";
            cout<<"\t\"Score\"\t\t\n"<<"You: "<<Points<<"\nPC: "<<pc<<endl;
            cout<<"-------------------------\n";
        }
    }while (draw||input[0]!='e');
    return main();
}

//Connect 4
Connect4::Connect4() {
    Connect4::SetName("Connect 4");
    Connect4::SetDev("Khaled Youssef, Salma Hany");
    Connect4::SetHTP("\n\"Connect Four is a classic two-player game where the goal is to get four of your X,or,O checkers in a row\n   either horizontally, vertically, or diagonally NOTE THAT:"
                     " in this game player 1 is X , player 2 is O\" \n\nEnter (0) to quit the game\n");
    Connect4::GetData();
    player = 1;
    rowIndex = 5;
    gameEnd = false;
    // Initialize the board with zeros
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            board[i][j] = 0;
        }
    }
}
void Connect4::draw() {
    system("cls");
    // to initialize the columns with its numbers
    for (int j = 0; j < 7; j++) {
        cout << "-" << j + 1 << "--";
    }
    //to make numbers horizontal
    cout << endl;
    //to initialize the shape and declare player 1x,2o
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == 0) {
                cout << "|  |";
            } else if (board[i][j] == 1) {
                cout << "|x |";
            } else if (board[i][j] == 2) {
                cout << "|o |";
            }
        }
        cout << endl;
    }
    for (int j = 0; j < 7; j++) {
        cout << "====";
    }
    cout << endl;
}
void Connect4::handleInput(int input) {
    if (rowIndex >= 0) {
        if (board[rowIndex][input] != 0) { // if the row is full
            rowIndex--;
            handleInput(input);
        }
        else {
            board[rowIndex][input] = player;
            rowIndex = 5;
        }
    }
    else {
        cout << "Wrong input please try again !\n";
        player = (player == 1) ? 2 : 1;
        rowIndex = 5;
    }
}
void Connect4::checkWinner() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++)
        {
            // check win with columns
            if (board[i][j]==player&&board[i][j-1]==player&&board[i][j-2]==player&&board[i][j-3]==player)
            {
                gameEnd = true;
                cout <<" congratulations player "<<player<<" win ! \n";
            }
                //check win with rows
            else if (board[i][j]==player&&board[i-1][j]==player&&board[i-2][j]==player&&board[i-3][j]==player)
            {
                gameEnd = true;
                cout <<" congratulations player "<<player<<" win ! \n";
            }
                //to check scissors to left side
            else if (board[i][j]==player&&board[i-1][j-1]==player&&board[i-2][j-2]==player&&board[i-3][j-3]==player)
            {
                gameEnd = true;
                cout <<" congratulations player "<<player<<" win ! \n";
            }
                //to check scissors to right side
            else if (board[i][j]==player&&board[i-1][j+1]==player&&board[i-2][j+2]==player&&board[i-3][j+3]==player)
            {
                gameEnd = true;
                cout <<" congratulations player "<<player<<" win ! \n";
            }

        }
    }
}
int Connect4::play() {
    Connect4::Welcome(this->Name);
    sleep_for(1s);
    draw();
    while (!gameEnd) {
        int input;
        if  (player==1) {
            cout << "Player X : ";
            cin >> input;
        }
        else{
            cout << "Player O : ";
            cin >> input;
        }
        if (input==0) return main(); //to back to main menu of user type e
        handleInput(input - 1);
        draw();
        checkWinner();
        player = (player == 1) ? 2 : 1;
    }
    system("pause");
    system("cls");
    return main();
}
//TIc Tac Toe
TicTacToe::TicTacToe() {
    TicTacToe::SetName("Tic Tac Toe");
    TicTacToe::SetDev("Mariam Mohamed, Mennatullah Abed");
    TicTacToe::SetHTP("\n\t\"Classic TicTacToe or as known as (X,O), You need to make your character (X or O) be in the same line\n\t\teither this line is horizontally, vertically, or diagonally\" \n\nEnter (e) to quit the game\n");
    TicTacToe::GetData();
}
void TicTacToe::printMatrix() {
    system("cls");
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cout << matrix[x][y] << '\t';
        }
        cout << endl;
    }
}
char TicTacToe::whoWin() {
    int xc, oc;
    for (int x = 0; x < 3; x++) {
        xc = oc = 0;
        for (int y = 0; y < 3; y++) {
            if (matrix[x][y] == 'x')
                xc++;
            else if (matrix[x][y] == 'o')
                oc++;
        }
        if (xc == 3 || oc == 3)
            return xc > oc ? 'x' : 'o';
    }

    for (int y = 0; y < 3; y++) {
        xc = oc = 0;
        for (int x = 0; x < 3; x++) {
            if (matrix[x][y] == 'x')
                xc++;
            else if (matrix[x][y] == 'o')
                oc++;
        }
        if (xc == 3 || oc == 3)
            return xc > oc ? 'x' : 'o';
    }


    if ((matrix[0][0] == 'x' && matrix[1][1] == 'x' && matrix[2][2] == 'x') ||
        (matrix[0][2] == 'x' && matrix[1][1] == 'x' && matrix[2][0] == 'x'))
        return 'x';
    else if ((matrix[0][0] == 'o' && matrix[1][1] == 'o' && matrix[2][2] == 'o') ||
             (matrix[0][2] == 'o' && matrix[1][1] == 'o' && matrix[2][0] == 'o'))
        return 'o';


    int counter = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (matrix[x][y] != 'x' && matrix[x][y] != 'o')
                counter++;
        }
    }
    if (counter == 0)
        return 'z';

    return '.';
}
int TicTacToe::play() {
    TicTacToe::Welcome(this->Name);
    sleep_for(1s);
    while (whoWin() == '.') {
        printMatrix();
        char pos;
        cout << "Choose your position - Player (" << player << ") :";
        cin >> pos;
        if (pos=='e') return main(); //to back to main menu of user type e
        bool validMove = false;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (matrix[x][y] == pos) {
                    matrix[x][y] = player;
                    validMove = true;
                    player = (player == 'x') ? 'o' : 'x';
                    break;
                }
            }
        }
        if (!validMove) {
            cout << "Invalid move! Please choose a valid position." << endl;
            sleep_for(2s);
        }
    }
    printMatrix();
    char winner = whoWin();
    if (winner == 'z')
        cout << "\nNo winner!!\n\n" << endl;
    else
        cout << "\nThe Winner is Player (" << winner << "), congratulations!!\n\n";
    sleep_for(3s);
    system("cls");
    return main();
}
