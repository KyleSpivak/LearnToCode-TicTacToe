#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <stdio.h>
#include <random>

class TicTacToe
{
public:

    // Constructor
    TicTacToe();
    // Destructor
    ~TicTacToe() = default;
    // Copy Constructor
    TicTacToe(TicTacToe const&) = default;
    // Assignment Operator
    TicTacToe& operator=(const TicTacToe&) = default;
    
    ////// Public Functions //////
   
    /**
     * Introduce the user to the program  
     *
     * @param void
     * @return void
     */
    void Introduction(void);
   
    /**
     * Get the username of the Player using X  
     *
     * @param void
     * @return void
     */
    void getPlayerXName(void);
     
    /**
     * Get the username of the Player using O  
     *
     * @param void
     * @return void
     */
    void getPlayerOName(void);
     
    /**
     * Starts the Game  
     *
     * @param void
     * @return void
     */
    void start();
     
    /**
     * Ask the Players if they would like to play again
     *
     * @param void
     * @return bool
     */
    bool playAgain(void);

    /**
     * Ask the Players if they are playing with the same players
     *
     * @param void
     * @return bool
     */
    bool samePlayers(void);
    
    /**
     * Conclusion the user to the program  
     *
     * @param void
     * @return void
     */
    void Conclusion(void);


private:

    ////// Private Functions //////
    
    /**
     * Get the current Players Move  
     *
     * @param bool abIsX
     * @return void
     */
    void GetMove(bool abIsX);
    
    /**
     * Check to see if the move is valid  
     *
     * @param std::string acMove
     * @return bool
     */
    bool ValidateMoveAndUpdate(std::string acMove, const std::string& arcXorO);
    
    /**
     * Calculate total height in Inches  
     *
     * @param std::string acYesOrNo
     * @return bool lbYes
     */
    bool IsTheInputYes(std::string acYesOrNo);
    
    /**
     * Initalizes the Values in the Gameboard 
     *
     * @param void
     * @return void
     */
    void InitalizeGameboard(void);
    
    /**
     * Clears the terminal 
     *
     * @param void
     * @return void
     */
    void ClearScreen(void);
    
    /**
     * Displays the Gameboard to the user 
     *
     * @param void
     * @return void
     */
    void DisplayGameboard(void);
    
    /**
     * Check to see if anyone won 
     *
     * @param bool abIsXTurn
     * @return bool
     */
    bool CheckForWinner(bool abIsXTurn);
    
    /**
     * Check to see if 9 turns have passed without a winner 
     *
     * @param int anTurn
     * @return bool
     */
    bool CheckForTie(int anTurn);
    
    /**
     * Switches to next player 
     *
     * @param bool& abIsXTurn
     * @return void
     */
    void SwitchPlayer(bool& abIsXTurn);
    
    /**
     * Randomizes Integer Array 0-2 
     *
     * @param int[3] aanRandomArray
     * @return void
     */
    void InitializeRandomArray(void);
    
    
    ////// Private Variables //////
    std::string mcPlayerX;
    std::string mcPlayerO;
    std::string mcClosingStatement;
    bool mbGameOver;
    
    std::string macGameBoard[3][3];
    int macBoard1Row[3];
    int macBoard1Col[3];
    
    std::string macGameBoard2[3][3];
    int macBoard2Row[3];
    int macBoard2Col[3];
    std::string macBoard2ColHdr[3]; 
    std::string macBoard2RowHdr[3]; 
    
    std::string macGameBoard3[3][3];
    int macBoard3Row[3];
    int macBoard3Col[3];
    std::string macBoard3ColHdr[3]; 
    std::string macBoard3RowHdr[3]; 
};

#endif