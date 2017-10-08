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

const int INT_GAMEBOARD_SIZE = 9;

void initializeGameBoard(char[]);
void drawGameBoard(const char[]);
bool checkWinner(const char[]);
void playerOne(char[]);
void playerTwo(char[]);

int main()
{
    bool isGameOver = false;
    
    char chrArrayGameBoard[INT_GAMEBOARD_SIZE];
    
    initializeGameBoard(chrArrayGameBoard);
    drawGameBoard(chrArrayGameBoard);
    
    while(!isGameOver)
    {
        playerOne(chrArrayGameBoard);
        drawGameBoard(chrArrayGameBoard);
        isGameOver = checkWinner(chrArrayGameBoard);
        
        if(!isGameOver)
        {
            playerTwo(chrArrayGameBoard);
            drawGameBoard(chrArrayGameBoard);
            isGameOver = checkWinner(chrArrayGameBoard);
        }
    }
    
    return 0;
}

void initializeGameBoard(char chrGameBoard[])
{
    for(int index = 0 ; index < INT_GAMEBOARD_SIZE ; index++)
    {
        chrGameBoard[index] = index + 49; // Add 49 to convert int value to ascii character number values
    }
}

void drawGameBoard(const char chrGameBoard[])
{
    cout << endl << " " << chrGameBoard[0] << " | " << chrGameBoard[1] << " | " << chrGameBoard[2] << endl;
    cout << "----------" << endl;
    cout << " " << chrGameBoard[3] << " | " << chrGameBoard[4] << " | " << chrGameBoard[5] << endl;
    cout << "----------" << endl;
    cout << " " <<chrGameBoard[6] << " | " << chrGameBoard[7] << " | " << chrGameBoard[8] << endl << endl;
}

bool checkWinner(const char chrGameBoard[])
{
    bool gameOver = false;
    
    if((chrGameBoard[0] == 'X' && chrGameBoard[1] == 'X' && chrGameBoard[2] == 'X') ||
       (chrGameBoard[3] == 'X' && chrGameBoard[4] == 'X' && chrGameBoard[5] == 'X') ||
       (chrGameBoard[6] == 'X' && chrGameBoard[7] == 'X' && chrGameBoard[8] == 'X') ||
       (chrGameBoard[0] == 'X' && chrGameBoard[3] == 'X' && chrGameBoard[6] == 'X') ||
       (chrGameBoard[1] == 'X' && chrGameBoard[4] == 'X' && chrGameBoard[7] == 'X') ||
       (chrGameBoard[2] == 'X' && chrGameBoard[5] == 'X' && chrGameBoard[8] == 'X') ||
       (chrGameBoard[0] == 'X' && chrGameBoard[4] == 'X' && chrGameBoard[8] == 'X') ||
       (chrGameBoard[2] == 'X' && chrGameBoard[4] == 'X' && chrGameBoard[6] == 'X'))
    {
        gameOver = true;
        cout << "Congratulations Player One! You win!\n";
    }
    else if((chrGameBoard[0] == 'O' && chrGameBoard[1] == 'O' && chrGameBoard[2] == 'O') ||
            (chrGameBoard[3] == 'O' && chrGameBoard[4] == 'O' && chrGameBoard[5] == 'O') ||
            (chrGameBoard[6] == 'O' && chrGameBoard[7] == 'O' && chrGameBoard[8] == 'O') ||
            (chrGameBoard[0] == 'O' && chrGameBoard[3] == 'O' && chrGameBoard[6] == 'O') ||
            (chrGameBoard[1] == 'O' && chrGameBoard[4] == 'O' && chrGameBoard[7] == 'O') ||
            (chrGameBoard[2] == 'O' && chrGameBoard[5] == 'O' && chrGameBoard[8] == 'O') ||
            (chrGameBoard[0] == 'O' && chrGameBoard[4] == 'O' && chrGameBoard[8] == 'O') ||
            (chrGameBoard[2] == 'O' && chrGameBoard[4] == 'O' && chrGameBoard[6] == 'O'))
    {
        gameOver = true;
        cout << "Congratulations Player Two! You win!\n";
    }
    else if(chrGameBoard[0] != '1' && chrGameBoard[1] != '2' && chrGameBoard[2] != '3' &&
            chrGameBoard[3] != '4' && chrGameBoard[4] != '5' && chrGameBoard[5] != '6' &&
            chrGameBoard[6] != '7' && chrGameBoard[7] != '8' && chrGameBoard[8] != '9')
    {
        gameOver = true;
        cout << "No winner, there was a tie.\n";
    }
    else
    {
        
    }
    
    return gameOver;
}

void playerOne(char chrGameBoard[])
{
    int playerChoice;
    
    cout << "Player one, please enter a number on the board: ";
    cin >> playerChoice;
    while(!cin || playerChoice < 1 || playerChoice > 9)
    {
        cout << "Please enter a number visible on the board: ";
        cin.clear();
        cin.ignore();
        cin >> playerChoice;
    }
    
    if(chrGameBoard[playerChoice - 1] != 'X' && chrGameBoard[playerChoice - 1] != 'O')
    {
        chrGameBoard[playerChoice - 1] = 'X';
    }
    else
    {
        cout << "Please enter a number visible on the board: ";
        cin.clear();
        cin.ignore();
        cin >> playerChoice;
    }
    
}

void playerTwo(char chrGameBoard[])
{
    int playerChoice;
    
    cout << "Player two, please enter a number on the board: ";
    cin >> playerChoice;
    while(!cin || playerChoice < 1 || playerChoice > 9)
    {
        cout << "Please enter a number visible on the board: ";
        cin.clear();
        cin.ignore();
        cin >> playerChoice;
    }
    
    if(chrGameBoard[playerChoice - 1] != 'X' && chrGameBoard[playerChoice - 1] != 'O')
    {
        chrGameBoard[playerChoice - 1] = 'O';
    }
    else
    {
        cout << "Please enter a number visible on the board: ";
        cin.clear();
        cin.ignore();
        cin >> playerChoice;
    }
    
}

