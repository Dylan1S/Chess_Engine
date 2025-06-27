

class Piece
{
private:
    
enum ptype{
        KING = 6,
        QUEEN = 5,
        ROOK = 4,
        BISHOP = 3,
        KNIGHT = 2,
        PAWN = 1
    }type;
    bool white;
public:
    Piece(/* args */);
    ~Piece();
};

