#include "Piece.h"
#include "Board.h"
#include <string>
#include <iostream>
/*Implementation file for Board and Piece classes
*/
//Piece Implementation
Piece::Piece(int type)
{

}

//board Implementation
//Default constructor
Board::Board()
{
    std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    Board(fen);
}
Board::Board(std::string fen)
{
    //use size of 71 to account for the 7 backslashes
    for(std::size_t i = 0; i < fen.length(); i++)
    {
        if(isdigit(fen[i]))
        {
            //check logic here - increments i by number of empty spaces
            i+= fen[i]-1;
            continue;
        }
        switch(fen[i])
        {
            case 'p':
                m_bPawns |= (0b1 << i);
                break;

            case 'P':
                m_wPawns |= (0b1 << i);
                break;

            case 'n':
                m_bKnights |= (0b1 << i);
                break;

            case 'N':
                m_wKnights |= (0b1 << i);
                break;

            case 'b':
                m_bBishops |= (0b1 << i);
                break;

            case 'B':
                m_wBishops |= (0b1 << i);
                break;

            case 'r':
                m_bRooks |= (0b1 << i);
                break;

            case 'R':
                m_wRooks |= (0b1 << i);
                break;

            case 'q':
                m_bQueens |= (0b1 << i);
                break;

            case 'Q':
                m_wQueens |= (0b1 << i);
                break;

            case 'k':
                m_bKing |= (0b1 << i);
                break;

            case 'K':
                m_wKing |= (0b1 << i);
                break;
            default:
                return;
        }
    }
}