#include <string>
#define __bitBoard unsigned __int64
class Board
{
private:
    unsigned char* grid;
    //Defining Bitboards
    __bitBoard m_wPawns;
    __bitBoard m_bPawns;
    __bitBoard m_wRooks;
    __bitBoard m_bRooks;
    __bitBoard m_wKnights;
    __bitBoard m_bKnights;
    __bitBoard m_wBishops;
    __bitBoard m_bBishops;
    __bitBoard m_wQueens;
    __bitBoard m_bQueens;
    __bitBoard m_wKing;
    __bitBoard m_bKing;
    
public:
    Board();
    Board(std::string FEN);
    ~Board();
};