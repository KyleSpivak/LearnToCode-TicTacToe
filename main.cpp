/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "TicTacToe.h"


int main()
{
    // Create a game of TicTacToe
    TicTacToe lcGame;
    
    // Introduce the Game
    lcGame.Introduction();
    
    // Initialize the Game
    bool lbPlaying = true;
    bool lbSamePlayers = false;
    std::string lcPlayerX = "X";
    std::string lcPlayerO = "O";
    
    // Play the Game
    while(lbPlaying == true)
    {
        // Check to see if new players
        if(lbSamePlayers == false)
        {
            // Get User Info
            lcGame.getPlayerXName();
            lcGame.getPlayerOName();   
        }
        
        // Start the Game
        lcGame.start();
        
        // Ask if players want to play again
        lbPlaying = lcGame.playAgain();
        
        // Ask if same players
        if(lbPlaying == true)
        {
           lbSamePlayers = lcGame.samePlayers(); 
        }
    }
    
    lcGame.Conclusion();
}
