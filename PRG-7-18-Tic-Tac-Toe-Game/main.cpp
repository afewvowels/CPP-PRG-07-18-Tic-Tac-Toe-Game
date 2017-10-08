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
    
    // Fill the empty gameboard with ASCII numbers
    initializeGameBoard(chrArrayGameBoard);
    // Display the board to the user
    drawGameBoard(chrArrayGameBoard);
    
    // Loops until isGameOver tests true
    while(!isGameOver)
    {
        // Player 1 turn, pass through gameboard array for modification
        playerOne(chrArrayGameBoard);
        // Redraw board with valid move
        drawGameBoard(chrArrayGameBoard);
        // Test after drawn to see if there's a winner
        isGameOver = checkWinner(chrArrayGameBoard);
        
        // Second test here in case player 1 wins
        // Otherwise if player 1 wins, player 2 has to take a turn
        // before initial isGameOver check determines the game
        // is over and breaks the loop.
        if(!isGameOver)
        {
            // Repeat player 1 steps for player 2
            playerTwo(chrArrayGameBoard);
            drawGameBoard(chrArrayGameBoard);
            isGameOver = checkWinner(chrArrayGameBoard);
        }
    }
    
    // Game over message
    cout << "GAME OVER" << endl;
    
    return 0;
}

// Fill the game board with numbers 1-9 for easy selection
// of spaces by players.
void initializeGameBoard(char chrGameBoard[])
{
    for(int index = 0 ; index < INT_GAMEBOARD_SIZE ; index++)
    {
        // Uses increasing index to add to fixed offset
        // to create numbers 1-9 to populate gameboard
        // (Which are characters, not integers)
        chrGameBoard[index] = index + 49; // Add 49 to convert int value to ascii character number values
    }
}

// Manually draw the game board and place array items
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
    // Used to pass back to main() to break game loop
    // Keep messaging here, pass back bool
    bool gameOver = false;
    
    // Test player 1 (X's) cases for win
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
    // Test player 2 (O's) cases for win
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
    // If all gameboard space have been modified (hold either X or O)
    // Checks to see if original values have all disappeared
    else if(chrGameBoard[0] != '1' && chrGameBoard[1] != '2' && chrGameBoard[2] != '3' &&
            chrGameBoard[3] != '4' && chrGameBoard[4] != '5' && chrGameBoard[5] != '6' &&
            chrGameBoard[6] != '7' && chrGameBoard[7] != '8' && chrGameBoard[8] != '9')
    {
        gameOver = true;
        cout << "No winner, there was a tie.\n";
    }
    // Fall-through case has to be empty as this is tested
    // after every player turn, no chance to throw
    // error message with last case :(
    else
    {
        
    }
    
    // Pass back gameOver to break loop in main()
    return gameOver;
}

// Player 1 turn
void playerOne(char chrGameBoard[])
{
    int playerChoice;
    
    // Used to keep track of whether a valid move has been made or not
    bool isValidMove;
    
    // Initialize to false, no valid move made
    isValidMove = false;
    
    // Use a loop to keep it on this player's turn until
    // they've made a valid move
    while(!isValidMove)
    {
        cout << "Player one, please enter a number on the board: ";
        cin >> playerChoice;
        // Data validation
        while(!cin || playerChoice < 1 || playerChoice > 9)
        {
            cout << "Please enter a number visible on the board: ";
            cin.clear();
            cin.ignore();
            cin >> playerChoice;
        }
        
        // Just check that space doesn't have an 'X' or an 'O' on it,
        // and sets isValidMove to true if the space is not an 'X' or an 'O'
        // otherwise it loops back and asks for user to select a number on the board
        if(chrGameBoard[playerChoice - 1] != 'X' && chrGameBoard[playerChoice - 1] != 'O')
        {
            // Set array value to player 1 symbol 'X'
            chrGameBoard[playerChoice - 1] = 'X';
            // Set isValidMove flag to true so loop breaks
            isValidMove = true;
        }
    }
}

// See player 1 for details on this function
void playerTwo(char chrGameBoard[])
{
    int playerChoice;
    
    bool isValidMove;
    
    isValidMove = false; // Initialize
    
    while(!isValidMove)
    {
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
            isValidMove = true;
        }
    }
}

