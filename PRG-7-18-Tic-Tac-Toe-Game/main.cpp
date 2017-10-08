//
//  main.cpp
//  PRG-7-18-Tic-Tac-Toe-Game
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that allows two players to play a game of tic-tac-toe. Use a two-
//  dimensional char array with three rows and three columns as the game board. Each
//  element of the array should be initialized with an asterisk (*). The program should run a
//  loop that does the following:
//
//  * Displays the contents of the board array.
//  * Allows player 1 to select a location on the board for an X. The program should ask
//    the user to enter the row and column numbers.
//  * Allows player 2 to select a location on the board for an O. The program should ask
//    the user to enter the row and column numbers.
//  * Determines whether a play has won, or a tie has occurred. If a player has won,
//    the program should declare that player the winner and end. If a tie has occurred, the
//    program should display an appropriate message and end.
//
//  Player 1 wins when there are three X's in a row on the game board. The Xs can appear in a
//  row, in a column, or diagonally across the board. Player 2 wins when there are three Os in
//  a row on the game board. The Os can appear in a row, in a column, or diagonally across
//  the board. A tie occurs when all of the locations on the board are full, but there is no winner.

#include <iostream>

using namespace std;

const int INT_ROWS = 3;
const int INT_COLS = 3;

void initializeGameBoard(char [][INT_COLS]);
void player1Turn(char [][INT_COLS]);
void player2Turn(char [][INT_COLS]);
void drawGameBoard(const char [][INT_COLS]);
void checkForWinner(const char [][INT_COLS], bool &);

int main()
{
    bool booGameOver = false;
    
    char chrGameBoard[INT_ROWS][INT_COLS];
    
    initializeGameBoard(chrGameBoard);
    drawGameBoard(chrGameBoard);
    
    while(booGameOver != true)
    {
        player1Turn(chrGameBoard);
        drawGameBoard(chrGameBoard);
        checkForWinner(chrGameBoard, booGameOver);
        
        if(booGameOver != true)
        {
            player2Turn(chrGameBoard);
            drawGameBoard(chrGameBoard);
            checkForWinner(chrGameBoard, booGameOver);
        }
    }
    
    return 0;
}

void initializeGameBoard(char gameBoard[][INT_COLS])
{
    for(int rows = 0 ; rows < INT_ROWS ; rows++)
    {
        for(int cols = 0 ; cols < INT_COLS ; cols++)
        {
            gameBoard[rows][cols] = '*';
        }
    }
}

void player1Turn(char gameBoard[][INT_COLS])
{
    int tempRow;
    int tempCol;
    
    bool isLegalMove = false;
    
    while(isLegalMove != true)
    {
        cout << "Player 1, please select an unfilled square by column and row\n"
        << "as two numbers separated by a space: ";
        cin >> tempRow >> tempCol;
        while(!cin || tempRow < 1 || tempRow > 3 || tempCol < 1 || tempCol > 3)
        {
            cout << "Please select two numbers between 1 and 3: ";
            cin >> tempRow >> tempCol;
        }
        
        tempRow -= 1;
        tempCol -= 1;
        
        if(gameBoard[tempRow][tempCol] == '*')
        {
            gameBoard[tempRow][tempCol] = 'X';
            isLegalMove = true;
        }
        else
        {
            cout << "That space is filled already.\n";
            isLegalMove = false;
        }
    }
    
    
}

void player2Turn(char gameBoard[][INT_COLS])
{
    int tempRow;
    int tempCol;
    
    bool isLegalMove = false;
    
    while(isLegalMove != true)
    {
        cout << "Player 2, please select an unfilled square by column and row\n"
        << "as two numbers separated by a space: ";
        cin >> tempRow >> tempCol;
        while(!cin || tempRow < 1 || tempRow > 3 || tempCol < 1 || tempCol > 3)
        {
            cout << "Please select two numbers between 1 and 3: ";
            cin >> tempRow >> tempCol;
        }
        
        tempRow -= 1;
        tempCol -= 1;
        
        if(gameBoard[tempRow][tempCol] == '*')
        {
            gameBoard[tempRow][tempCol] = 'O';
            isLegalMove = true;
        }
        else
        {
            cout << "That space is filled already.\n";
            isLegalMove = false;
        }
    }
    
    
}

void drawGameBoard(const char gameBoard[][INT_COLS])
{
    for(int rows = 0 ; rows < INT_ROWS ; rows++)
    {
        for(int cols = 0 ; cols < INT_COLS ; cols++)
        {
            cout << gameBoard[rows][cols] << " ";
        }
        cout << endl;
    }
}

void checkForWinner(const char gameBoard[][INT_COLS], bool &refIsWinner)
{
    int emptyCounter;
    
    emptyCounter = 0;
    
    for(int rows = 0 ; rows < INT_ROWS ; rows++)
    {
        for(int cols = 0 ; cols < INT_COLS ; cols++)
        {
            if(gameBoard[rows][cols] == '*')
            {
                emptyCounter++;
            }
        }
    }
    
    if((gameBoard[0][0] == 'X' && gameBoard[0][1] == 'X' && gameBoard[0][2] == 'X') ||
       (gameBoard[1][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[1][2] == 'X') ||
       (gameBoard[2][0] == 'X' && gameBoard[2][1] == 'X' && gameBoard[2][2] == 'X') ||
       (gameBoard[0][0] == 'X' && gameBoard[1][0] == 'X' && gameBoard[2][0] == 'X') ||
       (gameBoard[0][1] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][1] == 'X') ||
       (gameBoard[0][2] == 'X' && gameBoard[1][2] == 'X' && gameBoard[2][2] == 'X') ||
       (gameBoard[0][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][2] == 'X') ||
       (gameBoard[0][2] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][0] == 'X'))
    {
        cout << "Congratulations Player 1! You are the winner!\n";
        refIsWinner = true;
    }
    else if((gameBoard[0][0] == 'O' && gameBoard[0][1] == 'O' && gameBoard[0][2] == 'O') ||
            (gameBoard[1][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[1][2] == 'O') ||
            (gameBoard[2][0] == 'O' && gameBoard[2][1] == 'O' && gameBoard[2][2] == 'O') ||
            (gameBoard[0][0] == 'O' && gameBoard[1][0] == 'O' && gameBoard[2][0] == 'O') ||
            (gameBoard[0][1] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][1] == 'O') ||
            (gameBoard[0][2] == 'O' && gameBoard[1][2] == 'O' && gameBoard[2][2] == 'O') ||
            (gameBoard[0][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][2] == 'O') ||
            (gameBoard[0][2] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][0] == 'O'))
    {
        cout << "Congratulations Player 1! You are the winner!\n";
        refIsWinner = true;
    }
    else if(emptyCounter == 0)
    {
        cout << "There was a tie, no more moves to make.\n";
        refIsWinner = true;
    }
}

