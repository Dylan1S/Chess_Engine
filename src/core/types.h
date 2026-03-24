#include <stdint.h>


namespace chess{
    using Move = uint16_t;
    using Piece = uint8_t;
    using Bitboard = uint64_t;
    //encoding move into int16
    //Structure of encoded move: flags: 15-12; from: 11-6; to: 5-0 

    //flags:    
    enum flags{
        SILENT = 0, //0000
        DOUBLE_PUSH = 1, //0001
        CASTLE_K = 2, //0010
        CASTLE_Q = 3, //0011
        PROMO_KNIGHT = 4, //0100
        PROMO_ROOK = 5,//0101
        PROMO_BISHOP = 6,//0110
        PROMO_QUEEN = 7,//0111
        CAPTURE = 8, //1000 
        EN_PASSENT = 9 //1001 
    };

    inline Move encode_move(const int& flags,const int& from,const int& to)
    {
        return (flags << 12) | (from << 6) | to;
    }

    inline uint8_t get_flags(const Move& move)
    {
        //return flags
        return (move >> 12) & 0xF;
    }

    inline bool is_capture(const Move& move)
    {
        //return true if this move is a capture move
        return get_flags(move) & 0b1000;
    }

    inline bool is_promo(const Move& move)
    {
        return get_flags(move) &0b0100;
    }


    //defining the squares
    enum squares{
        a8, b8, c8, d8, e8, f8, g8, h8,
        a7, b7, c7, d7, e7, f7, g7, h7,
        a6, b6, c6, d6, e6, f6, g6, h6,
        a5, b5, c5, d5, e5, f5, g5, h5,
        a4, b4, c4, d4, e4, f4, g4, h4,
        a3, b3, c3, d3, e3, f3, g3, h3,
        a2, b2, c2, d2, e2, f2, g2, h2,
        a1, b1, c1, d1, e1, f1, g1, h1,
    };
    
    //piece: bit 1: side, rest: type.
    //0 = white, 1 = black
    enum sides{ 
        WHITE = 0,
        BLACK = 1
    };

    enum ptype: Piece{
        KING = 5, //0101
        QUEEN = 4, //0100
        ROOK = 3, //0011
        BISHOP = 2, //0010
        KNIGHT = 1, //0001
        PAWN = 0 //0000
    };

    inline Piece encode_piece(const int& side, const int& type)
    {
        //encodes a side and type into a piece
        return (side << 4) | type;
    }

    inline bool is_white(const Piece& piece)
    {
        //returns true if the piece is white
        return (piece & WHITE);
    }

    inline bool is_king(const Piece& piece)
    {
        //returns true if the piece is a king
        return (piece & KING);
    }
}
