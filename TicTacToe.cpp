#include "TicTacToe.h"

// Constructor
TicTacToe::TicTacToe()
{
    // Initialize Member Variables
    srand(time(0));
    mbGameOver = false;
}

// See description in header file
void TicTacToe::Introduction(void)
{
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
}

// See description in header file
void TicTacToe::getPlayerXName(void)
{
    std::string lcPlayerX;
    
    std::cout << "Who will play using X? ";
    std::getline(std::cin, lcPlayerX);
   
    mcPlayerX = lcPlayerX;
}
 
// See description in header file
void TicTacToe::getPlayerOName(void)
{
    std::string lcPlayerO;
    
    std::cout << "Who will play using O? ";
    std::getline(std::cin, lcPlayerO);
   
    mcPlayerO = lcPlayerO;
}
 
// See description in header file
void TicTacToe::start(void)
{
    // Clean the board
    InitalizeGameboard();
    
    // Used to determine whos turn it is
    bool lbIsXTurn = true;
    
    // Used to determine if the board is full
    int lnTurn = 0;
    
    while((mbBoard1GameOver != true || mbBoard2GameOver != true || mbBoard3GameOver != true))
    {
        // increment the turn
        lnTurn += 1;
        // Print the Gameboard
        DisplayGameboard();
        // Player selects Move
        GetMove(lbIsXTurn);
        
        // Check for a winner
        if(mbBoard1GameOver == false)
        {
            mbBoard1GameOver = CheckForWinner(lbIsXTurn, macGameBoard);
            if(mbBoard1GameOver == true)
            {
                if(lbIsXTurn == true)
                {
                    macBoardWinners[0] = "X";
                }
                else  
                {
                    macBoardWinners[0] = "O";
                }
            }
        }
        if(mbBoard2GameOver == false)
        {
            mbBoard2GameOver = CheckForWinner(lbIsXTurn, macGameBoard2);
            if(mbBoard2GameOver == true)
            {
                if(lbIsXTurn == true)
                {
                    macBoardWinners[1] = "X";
                }
                else  
                {
                    macBoardWinners[1] = "O";
                }
            }
        }
        if(mbBoard3GameOver == false)
        {
            mbBoard3GameOver = CheckForWinner(lbIsXTurn, macGameBoard3);
            if(mbBoard3GameOver == true)
            {
                if(lbIsXTurn == true)
                {
                    macBoardWinners[2] = "X";
                }
                else  
                {
                    macBoardWinners[2] = "O";
                }
            }
        }

        // Check for Tie
        if(mbGameOver == false)
        {
            mbGameOver = CheckForTie(lnTurn);
            if(mbGameOver == true)
            {
                mbBoard1GameOver = true;
                mbBoard2GameOver = true;
                mbBoard3GameOver = true;
                
                if(macBoardWinners[0] == " ")
                {
                    macBoardWinners[0] = "T";
                }
                if(macBoardWinners[1] == " ")
                {
                    macBoardWinners[1] = "T";
                }
                if(macBoardWinners[2] == " ")
                {
                    macBoardWinners[2] = "T";
                }
            }
        }
        
        // Switch to next player if the game is still going
        if(mbGameOver == false)
        {
            SwitchPlayer(lbIsXTurn);  
        }
    }
    
    // Print the Gameboard
    DisplayGameboard();
    
    // Prin the winner
    std::cout << "Board 1: " << macBoardWinners[0] << " Board 2: " << macBoardWinners[1] <<  " Board 3: " << macBoardWinners[2] << std::endl;
    DetermineWinner();
}
 
// See description in header file
bool TicTacToe::playAgain(void)
{
    std::string lcTemp;
    
    std::cout << "Would you like to play another game of Tic-Tac-Toe? ";
    std::getline(std::cin, lcTemp);
   
    return IsTheInputYes(lcTemp);
}

// See description in header file
bool TicTacToe::samePlayers(void)
{
    std::string lcTemp;
    
    std::cout << "Will the same players be playing? ";
    std::getline(std::cin, lcTemp);
   
    return IsTheInputYes(lcTemp);
}

// See description in header file
void TicTacToe::Conclusion(void)
{
    std::cout << "Thanks for playing Tic-Tac-Toe" << std::endl;
}


void TicTacToe::GetMove(bool abIsX)
{
    std::string lcPosition;
    std::string lcCurrentPlayer;
    std::string lcXorO;
    bool lbValidMove = false;
    bool lbFisrtAttempt = true;
    
    if(abIsX == true)
    {
        lcCurrentPlayer = mcPlayerX;
        lcXorO = "X";
    }
    else
    {
        lcCurrentPlayer = mcPlayerO;
        lcXorO = "O";
    }
    
    while(lbValidMove == false)
    {
        // Prompt the player to enter a move
        if(lbFisrtAttempt == true)
        {
            std::cout << lcCurrentPlayer << ", Where would you like to play? ";
        }
        else
        {
            std::cout << lcCurrentPlayer << ", you entered an invalid move. Please try again. ";
        }
        lbFisrtAttempt = false;
        std::getline(std::cin, lcPosition);
        
        // Check to see if the move is valid
        lbValidMove = ValidateMoveAndUpdate(lcPosition, lcXorO);
        
    }
}

bool TicTacToe::ValidateMoveAndUpdate(std::string acMove, const std::string& arcXorO)
{
    if((acMove == "A1" || acMove == "a1") && macGameBoard[macBoard1Row[0]][macBoard1Col[0]] == " ")
    {
        if(mbBoard1GameOver != true)
        {
            macGameBoard[macBoard1Row[0]][macBoard1Col[0]] = arcXorO;
        }
        if(mbBoard2GameOver != true)
        {
            macGameBoard2[macBoard2Row[0]][macBoard2Col[0]] = arcXorO;
        }
        if(mbBoard3GameOver != true)
        {
            macGameBoard3[macBoard3Row[0]][macBoard3Col[0]] = arcXorO;
        }
        return true;
    }
    else if((acMove == "A2" || acMove == "a2") && macGameBoard[macBoard1Row[0]][macBoard1Col[1]] == " ")
    {
        if(mbBoard1GameOver != true)
        {
            macGameBoard[macBoard1Row[0]][macBoard1Col[1]] = arcXorO;
        }
        if(mbBoard2GameOver != true)
        {
            macGameBoard2[macBoard2Row[0]][macBoard2Col[1]] = arcXorO;
        }
        if(mbBoard3GameOver != true)
        {
            macGameBoard3[macBoard3Row[0]][macBoard3Col[1]] = arcXorO;
        }
        return true;
    }
    else if((acMove == "A3" || acMove == "a3") && macGameBoard[macBoard1Row[0]][macBoard1Col[2]] == " ")
    {
        if(mbBoard1GameOver != true)
        {
            macGameBoard[macBoard1Row[0]][macBoard1Col[2]] = arcXorO;
        }
        if(mbBoard2GameOver != true)
        {
            macGameBoard2[macBoard2Row[0]][macBoard2Col[2]] = arcXorO;
        }
        if(mbBoard3GameOver != true)
        {
            macGameBoard3[macBoard3Row[0]][macBoard3Col[2]] = arcXorO;
        }
        return true;
    }
    else if((acMove == "B1" || acMove == "b1") && macGameBoard[macBoard1Row[1]][macBoard1Col[0]] == " ")
    {
        if(mbBoard1GameOver != true)
        {
            macGameBoard[macBoard1Row[1]][macBoard1Col[0]] = arcXorO;
        }
        if(mbBoard2GameOver != true)
        {
            macGameBoard2[macBoard2Row[1]][macBoard2Col[0]] = arcXorO;
        }
        if(mbBoard3GameOver != true)
        {
            macGameBoard3[macBoard3Row[1]][macBoard3Col[0]] = arcXorO;
        }
        return true;
    }
    else if((acMove == "B2" || acMove == "b2") && macGameBoard[macBoard1Row[1]][macBoard1Col[1]] == " ")
    {
        if(mbBoard1GameOver != true)
        {
            macGameBoard[macBoard1Row[1]][macBoard1Col[1]] = arcXorO;
        }
        if(mbBoard2GameOver != true)
        {
            macGameBoard2[macBoard2Row[1]][macBoard2Col[1]] = arcXorO;
        }
        if(mbBoard3GameOver != true)
        {
            macGameBoard3[macBoard3Row[1]][macBoard3Col[1]] = arcXorO;
        }
        return true;
    }
    else if((acMove == "B3" || acMove == "b3") && macGameBoard[macBoard1Row[1]][macBoard1Col[2]] == " ")
    {
        if(mbBoard1GameOver != true)
        {
            macGameBoard[macBoard1Row[1]][macBoard1Col[2]] = arcXorO;
        }
        if(mbBoard2GameOver != true)
        {
            macGameBoard2[macBoard2Row[1]][macBoard2Col[2]] = arcXorO;
        }
        if(mbBoard3GameOver != true)
        {
            macGameBoard3[macBoard3Row[1]][macBoard3Col[2]] = arcXorO;
        }
        return true;
    }
    else if((acMove == "C1" || acMove == "c1") && macGameBoard[macBoard1Row[2]][macBoard1Col[0]] == " ")
    {
        if(mbBoard1GameOver != true)
        {
            macGameBoard[macBoard1Row[2]][macBoard1Col[0]] = arcXorO;
        }
        if(mbBoard2GameOver != true)
        {
            macGameBoard2[macBoard2Row[2]][macBoard2Col[0]] = arcXorO;
        }
        if(mbBoard3GameOver != true)
        {
            macGameBoard3[macBoard3Row[2]][macBoard3Col[0]] = arcXorO;
        }
        return true;
    }
    else if((acMove == "C2" || acMove == "c2") && macGameBoard[macBoard1Row[2]][macBoard1Col[1]] == " ")
    {
        if(mbBoard1GameOver != true)
        {
            macGameBoard[macBoard1Row[2]][macBoard1Col[1]] = arcXorO;
        }
        if(mbBoard2GameOver != true)
        {
            macGameBoard2[macBoard2Row[2]][macBoard2Col[1]] = arcXorO;
        }
        if(mbBoard3GameOver != true)
        {
            macGameBoard3[macBoard3Row[2]][macBoard3Col[1]] = arcXorO;
        }
        return true;
    }
    else if((acMove == "C3" || acMove == "c3") && macGameBoard[macBoard1Row[2]][macBoard1Col[2]] == " ")
    {
        if(mbBoard1GameOver != true)
        {
            macGameBoard[macBoard1Row[2]][macBoard1Col[2]] = arcXorO;
        }
        if(mbBoard2GameOver != true)
        {
            macGameBoard2[macBoard2Row[2]][macBoard2Col[2]] = arcXorO;
        }
        if(mbBoard3GameOver != true)
        {
            macGameBoard3[macBoard3Row[2]][macBoard3Col[2]] = arcXorO;
        }
        return true;
    }
    else
    {
        // Do nothing with arcXorO
        return false;
    }
}

bool TicTacToe::CheckForWinner(bool abIsXTurn, std::string aacBoard[3][3])
{
    std::string lcXorO = " ";
    std::string lcCurrentPlayer = "";
    
    // Deterimine if we are checking for X or O
    if(abIsXTurn == true)
    {
        lcXorO = "X";
        lcCurrentPlayer = mcPlayerX;
    }
    else
    {
        lcXorO = "O";
        lcCurrentPlayer = mcPlayerO;
    }
    
    // Set the Closing Statement
    mcClosingStatement = lcCurrentPlayer + ", Congratulations you Win!";
    
    // Check Horizontals
    if(aacBoard[0][0] == lcXorO && aacBoard[0][1] == lcXorO && aacBoard[0][2] == lcXorO)
    {
        return true;
    }
    else if(aacBoard[1][0] == lcXorO && aacBoard[1][1] == lcXorO && aacBoard[1][2] == lcXorO)
    {
        return true;
    }
    else if(aacBoard[2][0] == lcXorO && aacBoard[2][1] == lcXorO && aacBoard[2][2] == lcXorO)
    {
        return true;
    }
    // Check Verticals
    else if(aacBoard[0][0] == lcXorO && aacBoard[1][0] == lcXorO && aacBoard[2][0] == lcXorO)
    {
        return true;
    }
    else if(aacBoard[0][1] == lcXorO && aacBoard[1][1] == lcXorO && aacBoard[2][1] == lcXorO)
    {
        return true;
    }
    else if(aacBoard[0][2] == lcXorO && aacBoard[1][2] == lcXorO && aacBoard[2][2] == lcXorO)
    {
        return true;
    }
    // Check Diagonals
    else if(aacBoard[0][0] == lcXorO && aacBoard[1][1] == lcXorO && aacBoard[2][2] == lcXorO)
    {
        return true;
    }
    else if(aacBoard[0][2] == lcXorO && aacBoard[1][1] == lcXorO && aacBoard[2][0] == lcXorO)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::CheckForWinner(bool abIsXTurn)
{
    std::string lcXorO = " ";
    std::string lcCurrentPlayer = "";
    
    // Deterimine if we are checking for X or O
    if(abIsXTurn == true)
    {
        lcXorO = "X";
        lcCurrentPlayer = mcPlayerX;
    }
    else
    {
        lcXorO = "O";
        lcCurrentPlayer = mcPlayerO;
    }
    
    // Set the Closing Statement
    mcClosingStatement = lcCurrentPlayer + ", Congratulations you Win!";
    
    // Check Horizontals
    if(macGameBoard[0][0] == lcXorO && macGameBoard[0][1] == lcXorO && macGameBoard[0][2] == lcXorO)
    {
        return true;
    }
    else if(macGameBoard[1][0] == lcXorO && macGameBoard[1][1] == lcXorO && macGameBoard[1][2] == lcXorO)
    {
        return true;
    }
    else if(macGameBoard[2][0] == lcXorO && macGameBoard[2][1] == lcXorO && macGameBoard[2][2] == lcXorO)
    {
        return true;
    }
    // Check Verticals
    else if(macGameBoard[0][0] == lcXorO && macGameBoard[1][0] == lcXorO && macGameBoard[2][0] == lcXorO)
    {
        return true;
    }
    else if(macGameBoard[0][1] == lcXorO && macGameBoard[1][1] == lcXorO && macGameBoard[2][1] == lcXorO)
    {
        return true;
    }
    else if(macGameBoard[0][2] == lcXorO && macGameBoard[1][2] == lcXorO && macGameBoard[2][2] == lcXorO)
    {
        return true;
    }
    // Check Diagonals
    else if(macGameBoard[0][0] == lcXorO && macGameBoard[1][1] == lcXorO && macGameBoard[2][2] == lcXorO)
    {
        return true;
    }
    else if(macGameBoard[0][2] == lcXorO && macGameBoard[1][1] == lcXorO && macGameBoard[2][0] == lcXorO)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::CheckForTie(int anTurn)
{
    if(anTurn == 9)
    {
        mcClosingStatement ="It's a tie!";
        return true;
    }
    else
    {
        return false;
    }
}

void TicTacToe::SwitchPlayer(bool& abIsXTurn)
{
    if(abIsXTurn == true)
    {
        abIsXTurn = false;
    }
    else
    {
        abIsXTurn = true;
    }
}

// See description in header file
bool TicTacToe::IsTheInputYes(std::string acYesOrNo)
{
    if( acYesOrNo == "Yes" || acYesOrNo == "yes" || acYesOrNo == "y" || acYesOrNo == "Y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void TicTacToe::InitalizeGameboard(void)
{
    // Top Row
    macGameBoard[0][0] = " ";
    macGameBoard[0][1] = " ";
    macGameBoard[0][2] = " ";
    
    // Middle Row
    macGameBoard[1][0] = " ";
    macGameBoard[1][1] = " ";
    macGameBoard[1][2] = " ";
    
    // Bottom Row
    macGameBoard[2][0] = " ";
    macGameBoard[2][1] = " ";
    macGameBoard[2][2] = " ";
    
    // Gameboard 1 Row
    macBoard1Row[0] = 0;
    macBoard1Row[1] = 1;
    macBoard1Row[2] = 2;
    
    // Gameboard 1 Col
    macBoard1Col[0] = 0;
    macBoard1Col[1] = 1;
    macBoard1Col[2] = 2;
    /////////////////////////////////////////////
    
    // Top Row
    macGameBoard2[0][0] = " ";
    macGameBoard2[0][1] = " ";
    macGameBoard2[0][2] = " ";
    
    // Middle Row
    macGameBoard2[1][0] = " ";
    macGameBoard2[1][1] = " ";
    macGameBoard2[1][2] = " ";
    
    // Bottom Row
    macGameBoard2[2][0] = " ";
    macGameBoard2[2][1] = " ";
    macGameBoard2[2][2] = " ";
    
    // Gameboard 2 Row
    macBoard2Row[0] = 0;
    macBoard2Row[1] = 1;
    macBoard2Row[2] = 2;
    
    // Gameboard 2 Col
    macBoard2Col[0] = 0;
    macBoard2Col[1] = 1;
    macBoard2Col[2] = 2;
    
    // Gameboard 2 Col header
    macBoard2ColHdr[0] = "1";
    macBoard2ColHdr[1] = "2";
    macBoard2ColHdr[2] = "3";
    
    // Gameboard 2 Row header
    macBoard2RowHdr[0] = "A";
    macBoard2RowHdr[1] = "B";
    macBoard2RowHdr[2] = "C";
    
    /////////////////////////////////////////////
    
    // Top Row
    macGameBoard3[0][0] = " ";
    macGameBoard3[0][1] = " ";
    macGameBoard3[0][2] = " ";
    
    // Middle Row
    macGameBoard3[1][0] = " ";
    macGameBoard3[1][1] = " ";
    macGameBoard3[1][2] = " ";
    
    // Bottom Row
    macGameBoard3[2][0] = " ";
    macGameBoard3[2][1] = " ";
    macGameBoard3[2][2] = " ";
    
    // Gameboard 3 Row
    macBoard3Row[0] = 0;
    macBoard3Row[1] = 1;
    macBoard3Row[2] = 2;
    
    // Gameboard 3 Col
    macBoard3Col[0] = 0;
    macBoard3Col[1] = 1;
    macBoard3Col[2] = 2;
    
    // Gameboard 3 Col header
    macBoard3ColHdr[0] = "1";
    macBoard3ColHdr[1] = "2";
    macBoard3ColHdr[2] = "3";
    
    // Gameboard 3 Row header
    macBoard3RowHdr[0] = "A";
    macBoard3RowHdr[1] = "B";
    macBoard3RowHdr[2] = "C";
    
    /////////////////////////////////////////////
    
    InitializeRandomArray();
    
    macBoardWinners[0] = " ";
    macBoardWinners[1] = " ";
    macBoardWinners[2] = " ";
    
    mbBoard1GameOver = false;
    mbBoard2GameOver = false;
    mbBoard3GameOver = false;
    mbGameOver = false;
}

void TicTacToe::InitializeRandomArray(void)
{
    // Shuffling our array using random_shuffle
    std::random_shuffle(macBoard2Row, macBoard2Row + 3);
    std::random_shuffle(macBoard3Row, macBoard3Row + 3);
    
    while((macBoard2Row[0] == 0 && macBoard2Row[1] == 1 && macBoard2Row[2] == 2))
    {
        std::random_shuffle(macBoard2Row, macBoard2Row + 3);
    }
    
    // Check to see if arrays are the same
    while((macBoard2Row[0] == macBoard3Row[0] && macBoard2Row[1] == macBoard3Row[1] && macBoard2Row[2] == macBoard3Row[2]) || (macBoard3Row[0] == 0 && macBoard3Row[1] == 1 && macBoard3Row[2] == 2))
    {
        std::random_shuffle(macBoard3Row, macBoard3Row + 3);
    }
    
    // Shuffling our array using random_shuffle
    std::random_shuffle(macBoard2Col, macBoard2Col + 3);
    std::random_shuffle(macBoard3Col, macBoard3Col + 3);
    
    // Check to see if arrays are the same
    while(macBoard2Col[0] == 0 && macBoard2Col[1] == 1 && macBoard2Col[2] == 2)
    {
        std::random_shuffle(macBoard2Col, macBoard2Col + 3);
    }
    
    while((macBoard2Col[0] == macBoard3Col[0] && macBoard2Col[1] == macBoard3Col[1] && macBoard2Col[2] == macBoard3Col[2]) || (macBoard3Col[0] == 0 && macBoard3Col[1] == 1 && macBoard3Col[2] == 2))
    {
        std::random_shuffle(macBoard3Col, macBoard3Col + 3);
    }
    
    // Gameboard 2 Col header
    macBoard2ColHdr[macBoard2Col[0]] = "1";
    macBoard2ColHdr[macBoard2Col[1]] = "2";
    macBoard2ColHdr[macBoard2Col[2]] = "3";
    
    // Gameboard 2 Row header
    macBoard2RowHdr[macBoard2Row[0]] = "A";
    macBoard2RowHdr[macBoard2Row[1]] = "B";
    macBoard2RowHdr[macBoard2Row[2]] = "C";
    
    // Gameboard 3 Col header
    macBoard3ColHdr[macBoard3Col[0]] = "1";
    macBoard3ColHdr[macBoard3Col[1]] = "2";
    macBoard3ColHdr[macBoard3Col[2]] = "3";
    
    // Gameboard 3 Row header
    macBoard3RowHdr[macBoard3Row[0]] = "A";
    macBoard3RowHdr[macBoard3Row[1]] = "B";
    macBoard3RowHdr[macBoard3Row[2]] = "C";
    
}

void TicTacToe::DetermineWinner(void)
{
    int lnXWins = 0;
    int lnOWins = 0;
    
    for(int lnBoards = 0; lnBoards < 3; lnBoards++)
    {
        if(macBoardWinners[lnBoards] == "X")
        {
            lnXWins++;
        }
        else if(macBoardWinners[lnBoards] == "O")
        {
            lnOWins++;
        }
    }
    
    if(lnXWins > lnOWins)
    {
        std::cout << mcPlayerX << " wins!!!" << mcPlayerX << " had " << lnXWins << " wins and " << mcPlayerO << " had " << lnOWins << " wins" << std::endl;
    }
    else if(lnOWins > lnXWins)
    {
        std::cout << mcPlayerO << " wins!!!" << mcPlayerX << " had " << lnXWins << " wins and " << mcPlayerO << " had " << lnOWins << " wins" << std::endl;
    }
    else
    {
        std::cout << "It's a Tie! " << mcPlayerX << " had " << lnXWins << " wins and " << mcPlayerO << " had " << lnOWins << " wins" << std::endl;
    }
    
}

void TicTacToe::ClearScreen(void)
{
     printf("\n\n\n\n\n\n");
}

void TicTacToe::DisplayGameboard(void)
{
    // Clear the Screen
    ClearScreen();
        
    // Display Player Names
    printf("\tX: %s\tO: %s\n\n", mcPlayerX.c_str(), mcPlayerO.c_str());
    // Display Gameboard
    
    printf("\t     1     2     3  \t     %s     %s     %s  \t     %s     %s     %s  \n", macBoard2ColHdr[0].c_str(),macBoard2ColHdr[1].c_str(),macBoard2ColHdr[2].c_str(),macBoard3ColHdr[0].c_str(),macBoard3ColHdr[1].c_str(),macBoard3ColHdr[2].c_str());
    printf("\t        |     |     \t        |     |     \t        |     |     \n");
    printf("\tA    %s  |  %s  |  %s \t%s    %s  |  %s  |  %s \t%s    %s  |  %s  |  %s \n",macGameBoard[0][0].c_str(), macGameBoard[0][1].c_str(), macGameBoard[0][2].c_str(),macBoard2RowHdr[0].c_str(),macGameBoard2[0][0].c_str(), macGameBoard2[0][1].c_str(), macGameBoard2[0][2].c_str(),macBoard3RowHdr[0].c_str(),macGameBoard3[0][0].c_str(), macGameBoard3[0][1].c_str(), macGameBoard3[0][2].c_str());
    printf("\t   _____|_____|_____\t   _____|_____|_____\t   _____|_____|_____\n");
    
    printf("\t        |     |     \t        |     |     \t        |     |     \n");
    printf("\tB    %s  |  %s  |  %s \t%s    %s  |  %s  |  %s \t%s    %s  |  %s  |  %s \n",macGameBoard[1][0].c_str(), macGameBoard[1][1].c_str(), macGameBoard[1][2].c_str(),macBoard2RowHdr[1].c_str(),macGameBoard2[1][0].c_str(), macGameBoard2[1][1].c_str(), macGameBoard2[1][2].c_str(),macBoard3RowHdr[1].c_str(),macGameBoard3[1][0].c_str(), macGameBoard3[1][1].c_str(), macGameBoard3[1][2].c_str());
    printf("\t   _____|_____|_____\t   _____|_____|_____\t   _____|_____|_____\n");
    
    printf("\t        |     |     \t        |     |     \t        |     |     \n");
    printf("\tC    %s  |  %s  |  %s \t%s    %s  |  %s  |  %s \t%s    %s  |  %s  |  %s \n",macGameBoard[2][0].c_str(), macGameBoard[2][1].c_str(), macGameBoard[2][2].c_str(),macBoard2RowHdr[2].c_str(),macGameBoard2[2][0].c_str(), macGameBoard2[2][1].c_str(), macGameBoard2[2][2].c_str(),macBoard3RowHdr[2].c_str(),macGameBoard3[2][0].c_str(), macGameBoard3[2][1].c_str(), macGameBoard3[2][2].c_str());
    printf("\t        |     |     \t        |     |     \t        |     |     \n\n");
}


