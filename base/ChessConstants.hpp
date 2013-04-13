#ifndef CHESSCONSTANTS_HPP
#define CHESSCONSTANTS_HPP

#include "BasicTypes.hpp"
#include <vector>

namespace chess
{
    void InitializeConstants();

    namespace starting
    {
        const bitboard white_king	 = 0x0000000000000010; //e1 = bit 4 = 2^4 = 16
        const bitboard black_king	 = 0x1000000000000000;
        const bitboard white_rooks	 = 0x0000000000000081;
        const bitboard black_rooks	 = 0x8100000000000000;
        const bitboard white_knights = 0x0000000000000042;
        const bitboard black_knights = 0x4200000000000000;
        const bitboard white_bishops = 0x00000000000000A4;
        const bitboard black_bishops = 0xA400000000000000;
        const bitboard white_queen	 = 0x0000000000000008;
        const bitboard black_queen	 = 0x0800000000000000;
        const bitboard white_pawns	 = 0x000000000000FF00;
        const bitboard black_pawns	 = 0x00FF000000000000;
    }

    namespace util
    {
        const bitboard one  = 0x0000000000000001;
        const bitboard full = 0xffffffffffffffff;
        const bitboard nil =  0x0000000000000000;
        const bitboard fullrank = 0x00000000000000ff;
        const int NUM_SQUARES = 64;
        const int BOARD_SIZE  = 8;
		bitboard singleBit[BOARD_SIZE];
    }

	namespace ranks
	{
		const int first   = 0;
		const int second  = 1;
		const int third   = 2;
		const int fourth  = 3;
		const int fifth   = 4;
		const int sixth   = 5;
		const int seventh = 6;
		const int eighth  = 7;
	}

    namespace sides
    {
        const int white = 0;
        const int black = 1;
        //const int my_third_rank[] = {2,6};
		const int ABOUT_TO_PROMOTE[] = {ranks::seventh, ranks::second};

        //const int other_side[] = {1,0};
    }

	namespace pieces
	{
		const Piece NONE         = 0;
		const Piece WHITE_PAWN   = 1;         //  0001
		const Piece WHITE_KING   = 2;         //  0010
		const Piece WHITE_KNIGHT = 3;         //  0011
		const Piece WHITE_BISHOP = 5;         //  0101
		const Piece WHITE_ROOK   = 6;         //  0110
		const Piece WHITE_QUEEN  = 7;         //  0111
		const Piece BLACK_PAWN   = 9;         //  1001
		const Piece BLACK_KING   = 10;        //  1010
		const Piece BLACK_KNIGHT = 11;        //  1011
		const Piece BLACK_BISHOP = 13;        //  1101
		const Piece BLACK_ROOK   = 14;        //  1110
		const Piece BLACK_QUEEN  = 15;        //  1111

		const Piece KNIGHTS[2] = { 3, 11 };
		const Piece BISHOPS[2] = { 5, 13 };
		const Piece KINGS[2]   = { 2, 10 };
		const Piece PAWNS[2]   = { 1, 9 };
		const Piece ROOKS[2]   = { 6, 14 };
		const Piece QUEENS[2]  = { 7, 15 };
	}

	namespace squares
	{
		const int a1 = 0;
		const int b1 = 1;
		const int c1 = 2;
		const int d1 = 3;
		const int e1 = 4;
		const int f1 = 5;
		const int g1 = 6;
		const int h1 = 7;

		const int a2 = 8;
		const int b2 = 9;
		const int c2 = 10;
		const int d2 = 11;
		const int e2 = 12;
		const int f2 = 13;
		const int g2 = 14;
		const int h2 = 15;

		const int a3 = 16;
		const int b3 = 17;
		const int c3 = 18;
		const int d3 = 19;
		const int e3 = 20;
		const int f3 = 21;
		const int g3 = 22;
		const int h3 = 23;

		const int a4 = 24;
		const int b4 = 25;
		const int c4 = 26;
		const int d4 = 27;
		const int e4 = 28;
		const int f4 = 29;
		const int g4 = 30;
		const int h4 = 31;

		const int a5 = 32;
		const int b5 = 33;
		const int c5 = 34;
		const int d5 = 35;
		const int e5 = 36;
		const int f5 = 37;
		const int g5 = 38;
		const int h5 = 39;

		const int a6 = 40;
		const int b6 = 41;
		const int c6 = 42;
		const int d6 = 43;
		const int e6 = 44;
		const int f6 = 45;
		const int g6 = 46;
		const int h6 = 47;

		const int a7 = 48;
		const int b7 = 49;
		const int c7 = 50;
		const int d7 = 51;
		const int e7 = 52;
		const int f7 = 53;
		const int g7 = 54;
		const int h7 = 55;

		const int a8 = 56;
		const int b8 = 57;
		const int c8 = 58;
		const int d8 = 59;
		const int e8 = 60;
		const int f8 = 61;
		const int g8 = 62;
		const int h8 = 63;
	}

    namespace squarebits
    {
        const bitboard a1 = 0x0000000000000001;
        const bitboard b1 = 0x0000000000000002;
        const bitboard c1 = 0x0000000000000004;
        const bitboard d1 = 0x0000000000000008;
        const bitboard e1 = 0x0000000000000010;
        const bitboard f1 = 0x0000000000000020;
        const bitboard g1 = 0x0000000000000040;
        const bitboard h1 = 0x0000000000000080;
        const bitboard a2 = 0x0000000000000100;
        const bitboard b2 = 0x0000000000000200;
        const bitboard c2 = 0x0000000000000400;
        const bitboard d2 = 0x0000000000000800;
        const bitboard e2 = 0x0000000000001000;
        const bitboard f2 = 0x0000000000002000;
        const bitboard g2 = 0x0000000000004000;
        const bitboard h2 = 0x0000000000008000;
        const bitboard a3 = 0x0000000000010000;
        const bitboard b3 = 0x0000000000020000;
        const bitboard c3 = 0x0000000000040000;
        const bitboard d3 = 0x0000000000080000;
        const bitboard e3 = 0x0000000000100000;
        const bitboard f3 = 0x0000000000200000;
        const bitboard g3 = 0x0000000000400000;
        const bitboard h3 = 0x0000000000800000;
        const bitboard a4 = 0x0000000001000000;
        const bitboard b4 = 0x0000000002000000;
        const bitboard c4 = 0x0000000004000000;
        const bitboard d4 = 0x0000000008000000;
        const bitboard e4 = 0x0000000010000000;
        const bitboard f4 = 0x0000000020000000;
        const bitboard g4 = 0x0000000040000000;
        const bitboard h4 = 0x0000000080000000;
        const bitboard a5 = 0x0000000100000000;
        const bitboard b5 = 0x0000000200000000;
        const bitboard c5 = 0x0000000400000000;
        const bitboard d5 = 0x0000000800000000;
        const bitboard e5 = 0x0000001000000000;
        const bitboard f5 = 0x0000002000000000;
        const bitboard g5 = 0x0000004000000000;
        const bitboard h5 = 0x0000008000000000;
        const bitboard a6 = 0x0000010000000000;
        const bitboard b6 = 0x0000020000000000;
        const bitboard c6 = 0x0000040000000000;
        const bitboard d6 = 0x0000080000000000;
        const bitboard e6 = 0x0000100000000000;
        const bitboard f6 = 0x0000200000000000;
        const bitboard g6 = 0x0000400000000000;
        const bitboard h6 = 0x0000800000000000;
        const bitboard a7 = 0x0001000000000000;
        const bitboard b7 = 0x0002000000000000;
        const bitboard c7 = 0x0004000000000000;
        const bitboard d7 = 0x0008000000000000;
        const bitboard e7 = 0x0010000000000000;
        const bitboard f7 = 0x0020000000000000;
        const bitboard g7 = 0x0040000000000000;
        const bitboard h7 = 0x0080000000000000;
        const bitboard a8 = 0x0100000000000000;
        const bitboard b8 = 0x0200000000000000;
        const bitboard c8 = 0x0400000000000000;
        const bitboard d8 = 0x0800000000000000;
        const bitboard e8 = 0x1000000000000000;
        const bitboard f8 = 0x2000000000000000;
        const bitboard g8 = 0x4000000000000000;
        const bitboard h8 = 0x8000000000000000;

		const bitboard indexed[util::NUM_SQUARES] =
		{
			a1, b1, c1, d1, e1, f1, g1, h1,
			a2, b2, c2, d2, e2, f2, g2, h2,
			a3, b3, c3, d3, e3, f3, g3, h3,
			a4, b4, c4, d4, e4, f4, g4, h4,
			a5, b5, c5, d5, e5, f5, g5, h5,
			a6, b6, c6, d6, e6, f6, g6, h6,
			a7, b7, c7, d7, e7, f7, g7, h7,
			a8, b8, c8, d8, e8, f8, g8, h8
		};
    }

    namespace moves
    {
        const bitboard king_moves[util::NUM_SQUARES] = 
        {
            0x0000000000000302, //a1
            0x0000000000000705,
            0x0000000000000e0a,
            0x0000000000001c14,
            0x0000000000003828,
            0x0000000000007050,
            0x000000000000e0a0,
            0x000000000000c040, //h1
            0x0000000000030203, //a2
            0x0000000000070507,
            0x00000000000e0a0e,
            0x00000000001c141c,
            0x0000000000382838,
            0x0000000000705070,
            0x0000000000e0a0e0,
            0x0000000000c040c0, //h2
            0x0000000003020300, //a3
            0x0000000007050700,
            0x000000000e0a0e00,
            0x000000001c141c00,
            0x0000000038283800,
            0x0000000070507000,
            0x00000000e0a0e000,
            0x00000000c040c000, //h3
            0x0000000302030000,
            0x0000000705070000,
            0x0000000e0a0e0000,
            0x0000001c141c0000,
            0x0000003828380000,
            0x0000007050700000,
            0x000000e0a0e00000,
            0x000000c040c00000,
            0x0000030203000000,
            0x0000070507000000,
            0x00000e0a0e000000,
            0x00001c141c000000,
            0x0000382838000000,
            0x0000705070000000,
            0x0000e0a0e0000000,
            0x0000c040c0000000,
            0x0003020300000000,
            0x0007050700000000,
            0x000e0a0e00000000,
            0x001c141c00000000,
            0x0038283800000000,
            0x0070507000000000,
            0x00e0a0e000000000,
            0x00c040c000000000,
            0x0302030000000000,
            0x0705070000000000,
            0x0e0a0e0000000000,
            0x1c141c0000000000,
            0x3828380000000000,
            0x7050700000000000,
            0xe0a0e00000000000,
            0xc040c00000000000,
            0x0203000000000000,
            0x0507000000000000,
            0x0a0e000000000000,
            0x141c000000000000,
            0x2838000000000000,
            0x5070000000000000,
            0xa0e0000000000000,
            0x40c0000000000000
        };

        const bitboard pawn_moves[2][util::NUM_SQUARES] =
        {
            { //white
                0x0000000000000100,                                                                               
                0x0000000000000200,                                                                               
                0x0000000000000400,                                                                               
                0x0000000000000800,                                                                               
                0x0000000000001000,                                                                               
                0x0000000000002000,
                0x0000000000004000,
                0x0000000000008000,
                0x0000000001010000,
                0x0000000002020000,
                0x0000000004040000,
                0x0000000008080000,
                0x0000000010100000,
                0x0000000020200000,
                0x0000000040400000,
                0x0000000080800000,
                0x0000000001000000,
                0x0000000002000000,
                0x0000000004000000,
                0x0000000008000000,
                0x0000000010000000,
                0x0000000020000000,
                0x0000000040000000,
                0x0000000080000000,
                0x0000000100000000,
                0x0000000200000000,
                0x0000000400000000,
                0x0000000800000000,
                0x0000001000000000,
                0x0000002000000000,
                0x0000004000000000,
                0x0000008000000000,
                0x0000010000000000,
                0x0000020000000000,
                0x0000040000000000,
                0x0000080000000000,
                0x0000100000000000,
                0x0000200000000000,
                0x0000400000000000,
                0x0000800000000000,
                0x0001000000000000,
                0x0002000000000000,
                0x0004000000000000,
                0x0008000000000000,
                0x0010000000000000,
                0x0020000000000000,
                0x0040000000000000,
                0x0080000000000000,
                0x0100000000000000,
                0x0200000000000000,
                0x0400000000000000,
                0x0800000000000000,
                0x1000000000000000,
                0x2000000000000000,
                0x4000000000000000,
                0x8000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000
            },
            { //black
                0x0000000000000000,                                                                               
                0x0000000000000000,                                                                               
                0x0000000000000000,                                                                               
                0x0000000000000000,                                                                               
                0x0000000000000000,                                                                               
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000001,
                0x0000000000000002,
                0x0000000000000004,
                0x0000000000000008,
                0x0000000000000010,
                0x0000000000000020,
                0x0000000000000040,
                0x0000000000000080,
                0x0000000000000100,
                0x0000000000000200,
                0x0000000000000400,
                0x0000000000000800,
                0x0000000000001000,
                0x0000000000002000,
                0x0000000000004000,
                0x0000000000008000,
                0x0000000000010000,
                0x0000000000020000,
                0x0000000000040000,
                0x0000000000080000,
                0x0000000000100000,
                0x0000000000200000,
                0x0000000000400000,
                0x0000000000800000,
                0x0000000001000000,
                0x0000000002000000,
                0x0000000004000000,
                0x0000000008000000,
                0x0000000010000000,
                0x0000000020000000,
                0x0000000040000000,
                0x0000000080000000,
                0x0000000100000000,
                0x0000000200000000,
                0x0000000400000000,
                0x0000000800000000,
                0x0000001000000000,
                0x0000002000000000,
                0x0000004000000000,
                0x0000008000000000,
                0x0000010100000000,
                0x0000020200000000,
                0x0000040400000000,
                0x0000080800000000,
                0x0000101000000000,
                0x0000202000000000,
                0x0000404000000000,
                0x0000808000000000,
                0x0001000000000000,
                0x0002000000000000,
                0x0004000000000000,
                0x0008000000000000,
                0x0010000000000000,
                0x0020000000000000,
                0x0040000000000000,
                0x0080000000000000
            }
        };

        const bitboard pawn_captures[2][util::NUM_SQUARES] =
        {
            {
                0x0000000000000200,                                                                               
                0x0000000000000500,                                                                               
                0x0000000000000a00,                                                                               
                0x0000000000001400,                                                                               
                0x0000000000002800,                                                                               
                0x0000000000005000,
                0x000000000000a000,
                0x0000000000004000,
                0x0000000000020000,
                0x0000000000050000,
                0x00000000000a0000,
                0x0000000000140000,
                0x0000000000280000,
                0x0000000000500000,
                0x0000000000a00000,
                0x0000000000400000,
                0x0000000002000000,
                0x0000000005000000,
                0x000000000a000000,
                0x0000000014000000,
                0x0000000028000000,
                0x0000000050000000,
                0x00000000a0000000,
                0x0000000040000000,
                0x0000000200000000,
                0x0000000500000000,
                0x0000000a00000000,
                0x0000001400000000,
                0x0000002800000000,
                0x0000005000000000,
                0x000000a000000000,
                0x0000004000000000,
                0x0000020000000000,
                0x0000050000000000,
                0x00000a0000000000,
                0x0000140000000000,
                0x0000280000000000,
                0x0000500000000000,
                0x0000a00000000000,
                0x0000400000000000,
                0x0002000000000000,
                0x0005000000000000,
                0x000a000000000000,
                0x0014000000000000,
                0x0028000000000000,
                0x0050000000000000,
                0x00a0000000000000,
                0x0040000000000000,
                0x0200000000000000,
                0x0500000000000000,
                0x0a00000000000000,
                0x1400000000000000,
                0x2800000000000000,
                0x5000000000000000,
                0xa000000000000000,
                0x4000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000
            },
            {
                0x0000000000000000,                                                                               
                0x0000000000000000,                                                                               
                0x0000000000000000,                                                                               
                0x0000000000000000,                                                                               
                0x0000000000000000,                                                                               
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000000,
                0x0000000000000002,
                0x0000000000000005,
                0x000000000000000a,
                0x0000000000000014,
                0x0000000000000028,
                0x0000000000000050,
                0x00000000000000a0,
                0x0000000000000040,
                0x0000000000000200,
                0x0000000000000500,
                0x0000000000000a00,
                0x0000000000001400,
                0x0000000000002800,
                0x0000000000005000,
                0x000000000000a000,
                0x0000000000004000,
                0x0000000000020000,
                0x0000000000050000,
                0x00000000000a0000,
                0x0000000000140000,
                0x0000000000280000,
                0x0000000000500000,
                0x0000000000a00000,
                0x0000000000400000,
                0x0000000002000000,
                0x0000000005000000,
                0x000000000a000000,
                0x0000000014000000,
                0x0000000028000000,
                0x0000000050000000,
                0x00000000a0000000,
                0x0000000040000000,
                0x0000000200000000,
                0x0000000500000000,
                0x0000000a00000000,
                0x0000001400000000,
                0x0000002800000000,
                0x0000005000000000,
                0x000000a000000000,
                0x0000004000000000,
                0x0000020000000000,
                0x0000050000000000,
                0x00000a0000000000,
                0x0000140000000000,
                0x0000280000000000,
                0x0000500000000000,
                0x0000a00000000000,
                0x0000400000000000,
                0x0002000000000000,
                0x0005000000000000,
                0x000a000000000000,
                0x0014000000000000,
                0x0028000000000000,
                0x0050000000000000,
                0x00a0000000000000,
                0x0040000000000000
            }
        };

        extern bitboard knight_moves[util::NUM_SQUARES];
        extern bitboard rook_horiz_moves[util::NUM_SQUARES][256];
        extern bitboard rook_vert_moves[util::NUM_SQUARES][256];
        extern bitboard file_masks[util::BOARD_SIZE];
        extern bitboard rank_masks[util::BOARD_SIZE];
        extern bitboard diag_masks_a1h8[util::NUM_SQUARES];
        extern bitboard diag_masks_a8h1[util::NUM_SQUARES];
        extern bitboard diag_moves[util::NUM_SQUARES][256];

        /*const bitboard right_of[util::NUM_SQUARES] =
        {
        0x00000000000000fe,                                                 
        0x00000000000000fc,                                                 
        0x00000000000000f8,                                                 
        0x00000000000000f0,                                                 
        0x00000000000000e0,                                                 
        0x00000000000000c0,                                                 
        0x0000000000000080,
        0x0000000000000000,
        0x000000000000fe00,
        0x000000000000fc00,
        0x000000000000f800,
        0x000000000000f000,
        0x000000000000e000,
        0x000000000000c000,
        0x0000000000008000,
        0x0000000000000000,
        0x0000000000fe0000,
        0x0000000000fc0000,
        0x0000000000f80000,
        0x0000000000f00000,
        0x0000000000e00000,
        0x0000000000c00000,
        0x0000000000800000,
        0x0000000000000000,
        0x00000000fe000000,
        0x00000000fc000000,
        0x00000000f8000000,
        0x00000000f0000000,
        0x00000000e0000000,
        0x00000000c0000000,
        0x0000000080000000,
        0x0000000000000000,
        0x000000fe00000000,
        0x000000fc00000000,
        0x000000f800000000,
        0x000000f000000000,
        0x000000e000000000,
        0x000000c000000000,
        0x0000008000000000,
        0x0000000000000000,
        0x0000fe0000000000,
        0x0000fc0000000000,
        0x0000f80000000000,
        0x0000f00000000000,
        0x0000e00000000000,
        0x0000c00000000000,
        0x0000800000000000,
        0x0000000000000000,
        0x00fe000000000000,
        0x00fc000000000000,
        0x00f8000000000000,
        0x00f0000000000000,
        0x00e0000000000000,
        0x00c0000000000000,
        0x0080000000000000,
        0x0000000000000000,
        0xfe00000000000000,
        0xfc00000000000000,
        0xf800000000000000,
        0xf000000000000000,
        0xe000000000000000,
        0xc000000000000000,
        0x8000000000000000,
        0x0000000000000000
        };*/

        /*const bitboard left_of[util::NUM_SQUARES] =
        {
        0x0000000000000000,                                                          
        0x0000000000000001,                                                          
        0x0000000000000003,                                                          
        0x0000000000000007,                                                          
        0x000000000000000e,                                                          
        0x0000000000000018,
        0x0000000000000020,
        0x0000000000000000,
        0x00000000000000fe,
        0x00000000000001f8,
        0x00000000000003e0,
        0x0000000000000780,
        0x0000000000000e00,
        0x0000000000001800,
        0x0000000000002000,
        0x0000000000000000,
        0x000000000000fe00,
        0x000000000001f800,
        0x000000000003e000,
        0x0000000000078000,
        0x00000000000e0000,
        0x0000000000180000,
        0x0000000000200000,
        0x0000000000000000,
        0x0000000000fe0000,
        0x0000000001f80000,
        0x0000000003e00000,
        0x0000000007800000,
        0x000000000e000000,
        0x0000000018000000,
        0x0000000020000000,
        0x0000000000000000,
        0x00000000fe000000,
        0x00000001f8000000,
        0x00000003e0000000,
        0x0000000780000000,
        0x0000000e00000000,
        0x0000001800000000,
        0x0000002000000000,
        0x0000000000000000,
        0x000000fe00000000,
        0x000001f800000000,
        0x000003e000000000,
        0x0000078000000000,
        0x00000e0000000000,
        0x0000180000000000,
        0x0000200000000000,
        0x0000000000000000,
        0x0000fe0000000000,
        0x0001f80000000000,
        0x0003e00000000000,
        0x0007800000000000,
        0x000e000000000000,
        0x0018000000000000,
        0x0020000000000000,
        0x0000000000000000,
        0x00fe000000000000,
        0x01f8000000000000,
        0x03e0000000000000,
        0x0780000000000000,
        0x0e00000000000000,
        0x1800000000000000,
        0x2000000000000000,
        0x0000000000000000,
        };

        const bitboard up_from[util::NUM_SQUARES] =
        {
        0x0101010101010100,                          
        0x0202020202020200,                          
        0x0404040404040400,                          
        0x0808080808080800,                          
        0x1010101010101000,                          
        0x2020202020202000,
        0x4040404040404000,
        0x8080808080808000,
        0x0101010101010000,
        0x0202020202020000,
        0x0404040404040000,
        0x0808080808080000,
        0x1010101010100000,
        0x2020202020200000,
        0x4040404040400000,
        0x8080808080800000,
        0x0101010101000000,
        0x0202020202000000,
        0x0404040404000000,
        0x0808080808000000,
        0x1010101010000000,
        0x2020202020000000,
        0x4040404040000000,
        0x8080808080000000,
        0x0101010100000000,
        0x0202020200000000,
        0x0404040400000000,
        0x0808080800000000,
        0x1010101000000000,
        0x2020202000000000,
        0x4040404000000000,
        0x8080808000000000,
        0x0101010000000000,
        0x0202020000000000,
        0x0404040000000000,
        0x0808080000000000,
        0x1010100000000000,
        0x2020200000000000,
        0x4040400000000000,
        0x8080800000000000,
        0x0101000000000000,
        0x0202000000000000,
        0x0404000000000000,
        0x0808000000000000,
        0x1010000000000000,
        0x2020000000000000,
        0x4040000000000000,
        0x8080000000000000,
        0x0100000000000000,
        0x0200000000000000,
        0x0400000000000000,
        0x0800000000000000,
        0x1000000000000000,
        0x2000000000000000,
        0x4000000000000000,
        0x8000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000
        };

        const bitboard down_from[util::NUM_SQUARES] =
        {
        0x0000000000000000,                          
        0x0000000000000000,                          
        0x0000000000000000,                          
        0x0000000000000000,                          
        0x0000000000000000,                          
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000001,
        0x0000000000000002,
        0x0000000000000004,
        0x0000000000000008,
        0x0000000000000010,
        0x0000000000000020,
        0x0000000000000040,
        0x0000000000000080,
        0x0000000000000101,
        0x0000000000000202,
        0x0000000000000404,
        0x0000000000000808,
        0x0000000000001010,
        0x0000000000002020,
        0x0000000000004040,
        0x0000000000008080,
        0x0000000000010101,
        0x0000000000020202,
        0x0000000000040404,
        0x0000000000080808,
        0x0000000000101010,
        0x0000000000202020,
        0x0000000000404040,
        0x0000000000808080,
        0x0000000001010100,
        0x0000000002020200,
        0x0000000004040400,
        0x0000000008080800,
        0x0000000010101000,
        0x0000000020202000,
        0x0000000040404000,
        0x0000000080808000,
        0x0000000101000000,
        0x0000000202000000,
        0x0000000404000000,
        0x0000000808000000,
        0x0000001010000000,
        0x0000002020000000,
        0x0000004040000000,
        0x0000008080000000,
        0x0000010000000000,
        0x0000020000000000,
        0x0000040000000000,
        0x0000080000000000,
        0x0000100000000000,
        0x0000200000000000,
        0x0000400000000000,
        0x0000800000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000,
        0x0000000000000000
        };*/
    }
}
#endif