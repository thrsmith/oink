#include "MoveGenerator.hpp"
#include "Position.hpp"
#include "BasicOperations.hpp"

using namespace std;

//#define OINK_MOVEGEN_DIAGNOSTICS

#ifdef OINK_MOVEGEN_DIAGNOSTICS
    #include "Display.hpp"
#endif

namespace chess
{
	static void generate_moves_from_destinations(Bitboard destinations, Move &move, MoveVector &moves, const Position &position, Side side)
	{
        Square dest_square;
		while (destinations)
        {
            destinations = get_and_clear_first_occ_square(destinations, &dest_square);
			move.set_destination(dest_square);
			move.set_captured_piece(position.squares[dest_square]);
            moves.push_back(move);
        }
	}

    static void generate_moves_from_destinations_with_promotion(Bitboard destinations, Move &move, MoveVector &moves, const Position &position, Side side, bool promoting)
	{
        Square dest_square;
		while (destinations)
        {
			destinations = get_and_clear_first_occ_square(destinations, &dest_square);
			move.set_destination(dest_square);
			move.set_captured_piece(position.squares[dest_square]);
			if (promoting)
			{
				move.set_promotion_piece(pieces::QUEENS[side]);
				moves.push_back(move);
				move.set_promotion_piece(pieces::ROOKS[side]);
				moves.push_back(move);
				move.set_promotion_piece(pieces::KNIGHTS[side]);
				moves.push_back(move);
				move.set_promotion_piece(pieces::BISHOPS[side]);
			}
            moves.push_back(move);
        }
	}

    static void generate_ep_move(Bitboard destinations, Move &move, MoveVector &moves, const Position &position, Side side)
	{
        if (destinations)
        {
            Square dest_square;
		    destinations = get_and_clear_first_occ_square(destinations, &dest_square);
		    move.set_destination(dest_square);
		    move.set_captured_piece(pieces::PAWNS[swap_side(side)]);
            move.set_en_passant(pieces::PAWNS[side]);
            moves.push_back(move);
        }

        // There is a maximum of one EP capture available in a given position.
        assert(!destinations);
	}

	void generate_king_moves(MoveVector &moves, const Position &position, Side side)
    {
		Move move;
		move.set_piece(pieces::KINGS[side]);

		Bitboard king = position.kings[side];
        assert(king);

		Square square = get_first_occ_square(king);
		move.set_source(square);

        Bitboard destinations = moves::king_moves[square] & ~position.sides[side];
		generate_moves_from_destinations(destinations, move, moves, position, side);

        if (side == sides::white && square == squares::e1)
        {
            if ((position.castling_rights & sides::CASTLING_RIGHTS_WHITE_KINGSIDE) && (position.squares[squares::h1] == pieces::WHITE_ROOK))
            {
                if (util::nil == (position.whole_board & moves::white_kingside_castling_mask))
                {
                    move.set_destination(squares::g1);
                    move.set_captured_piece(pieces::NONE);
                    move.set_castling(pieces::WHITE_KING);
                    moves.push_back(move);
                }
            }

            if ((position.castling_rights & sides::CASTLING_RIGHTS_WHITE_QUEENSIDE) && (position.squares[squares::a1] == pieces::WHITE_ROOK))
            {
                if (util::nil == (position.whole_board & moves::white_queenside_castling_mask))
                {
                    move.set_destination(squares::c1);
                    move.set_captured_piece(pieces::NONE);
                    move.set_castling(pieces::WHITE_KING);
                    moves.push_back(move);
                }
            }
        }
        else if (side == sides::black && square == squares::e8)
        {
            if ((position.castling_rights & sides::CASTLING_RIGHTS_BLACK_KINGSIDE) && (position.squares[squares::h8] == pieces::BLACK_ROOK))
            {
                if (util::nil == (position.whole_board & moves::black_kingside_castling_mask))
                {
                    move.set_destination(squares::g8);
                    move.set_captured_piece(pieces::NONE);
                    move.set_castling(pieces::BLACK_KING);
                    moves.push_back(move);
                }
            }

            if ((position.castling_rights & sides::CASTLING_RIGHTS_BLACK_QUEENSIDE) && (position.squares[squares::a8] == pieces::BLACK_ROOK))
            {
                if (util::nil == (position.whole_board & moves::black_queenside_castling_mask))
                {
                    move.set_destination(squares::c8);
                    move.set_captured_piece(pieces::NONE);
                    move.set_castling(pieces::BLACK_KING);
                    moves.push_back(move);
                }
            }
        }
    }

    void generate_knight_moves(MoveVector &moves, const Position &position, Side side)
    {
		Move move;
		move.set_piece(pieces::KNIGHTS[side]);

        Bitboard knights = position.knights[side];
        Square source_sq;
        while (knights)
        {
            knights = get_and_clear_first_occ_square(knights, &source_sq);
			move.set_source(source_sq);

            Bitboard destinations = moves::knight_moves[source_sq] & ~position.sides[side] & ~position.kings[swap_side(side)];
			generate_moves_from_destinations(destinations, move, moves, position, side);
        }
    }

	void generate_pawn_moves(MoveVector &moves, const Position &position, Side side)
    {
		Move move;
		move.set_piece(pieces::PAWNS[side]);

        Bitboard pawns = position.pawns[side];
        Square source_sq;
        while (pawns)
        {
            pawns = get_and_clear_first_occ_square(pawns, &source_sq);
			move.set_source(source_sq);
            move.set_en_passant(pieces::NONE);

			RankFile rank = square_to_rank(source_sq);
			bool promoting = (rank == sides::ABOUT_TO_PROMOTE[side]); //if we're on the 7th or 2nd ranks, we're gonna promote.

			Bitboard whole_board = position.whole_board;
			if (rank == sides::STARTING_PAWN_RANKS[side])
            {
				whole_board = exclude_fourth_or_fifth_rank_if_third_or_sixth_occupied(whole_board, side);
            }
			// Since for pawns we're doing captures separately, we use whole_board here. We also exclude 4th(5th) rank if 3rd(6th) is occupied.
            // Normal moves and promotions.
			Bitboard destinations = moves::pawn_moves[side][source_sq] & ~whole_board;
			generate_moves_from_destinations_with_promotion(destinations, move, moves, position, side, promoting);

            // Normal captures
            // OINK_TODO: why not combine captures and normal moves?
			destinations = moves::pawn_captures[side][source_sq] & position.sides[swap_side(side)] & ~position.kings[swap_side(side)];
			generate_moves_from_destinations_with_promotion(destinations, move, moves, position, side, promoting);

            // EP captures: ep_target_square is set if there is a valid target for an EP capture. 
            // The actual captured pawn will have to be fixed up later. 
            // OINK_TODO: cleaner way?
            Bitboard ep_bb = (position.ep_target_square == squares::NO_SQUARE) ? util::nil : util::one << position.ep_target_square;
            destinations = moves::pawn_captures[side][source_sq] & ep_bb;
            // There must be a maximum of one destination.
            generate_ep_move(destinations, move, moves, position, side);
        }
    }

	static void generate_rank_file_slider_moves(MoveVector &moves, const Position &position, Side side, Move &move, Bitboard moving_piece_bitboard)
	{
        Square source_sq;
		while (moving_piece_bitboard)
		{
            moving_piece_bitboard = get_and_clear_first_occ_square(moving_piece_bitboard, &source_sq);
			move.set_source(source_sq);

			RankFile rank, file;
			square_to_rank_file(source_sq, rank, file);

			Bitboard rank_occ = get_rank_occupancy(position.whole_board, rank);
			Bitboard file_occ = get_file_occupancy(position.whole_board, file);
			Bitboard destinations = (moves::rook_horiz_moves[source_sq][rank_occ] |
									 moves::rook_vert_moves[source_sq][file_occ])
									 & ~position.sides[side] & ~position.kings[swap_side(side)];

			generate_moves_from_destinations(destinations, move, moves, position, side);
		}
	}

    void generate_rook_moves(MoveVector &moves, const Position &position, Side side)
    {
		Move move;
		move.set_piece(pieces::ROOKS[side]);
		generate_rank_file_slider_moves(moves, position, side, move, position.rooks[side]);
    }

	static void generate_diagonal_slider_moves(MoveVector &moves, const Position &position, Side side, Move &move, Bitboard movingPieceBitboard)
	{
        Square source_sq;
		while (movingPieceBitboard)
		{
			movingPieceBitboard = get_and_clear_first_occ_square(movingPieceBitboard, &source_sq);
			move.set_source(source_sq);

#ifdef OINK_MOVEGEN_DIAGNOSTICS
            print_bitboards(
            {
                make_pair(position.whole_board, "whole board"),
				make_pair(moves::diag_masks_a1h8[source_sq], "a1h8 diagmasks for source_sq"),
                make_pair(moves::diag_masks_a8h1[source_sq], "a8h1 diagmasks for source_sq")
            },
            source_sq);
#endif

			Bitboard projected_a1h8_occ = project_occupancy_from_a1h8(position.whole_board, source_sq);
			Bitboard projected_a8h1_occ = project_occupancy_from_a8h1(position.whole_board, source_sq);
			Bitboard destinations = (moves::diag_moves_a1h8[source_sq][projected_a1h8_occ] | moves::diag_moves_a8h1[source_sq][projected_a8h1_occ])
				                     & ~position.sides[side] & ~position.kings[swap_side(side)];

			assert(projected_a8h1_occ <= util::fullrank);
			assert(projected_a1h8_occ <= util::fullrank);

#ifdef OINK_MOVEGEN_DIAGNOSTICS
            print_bitboard(projected_a1h8_occ, "projected_a1h8_occ");
            print_bitboard(projected_a8h1_occ, "projected_a8h1_occ");
			print_bitboards(
            {
				make_pair(moves::diag_moves_a1h8[source_sq][projected_a1h8_occ], "a1h8 moves"),
				make_pair(moves::diag_moves_a8h1[source_sq][projected_a8h1_occ], "a8h1 moves"),
				make_pair(destinations, "destinations"),
                make_pair(position.sides[sides::black], "black")
            },
            source_sq);
#endif
			generate_moves_from_destinations(destinations, move, moves, position, side);
		}
	}

    void generate_bishop_moves(MoveVector &moves, const Position &position, Side side)
    {
		Move move;
		move.set_piece(pieces::BISHOPS[side]);
		generate_diagonal_slider_moves(moves, position, side, move, position.bishops[side]);
    }

	void generate_queen_moves(MoveVector &moves, const Position &position, Side side)
	{
		Move rf_move;
		rf_move.set_piece(pieces::QUEENS[side]);
		generate_rank_file_slider_moves(moves, position, side, rf_move, position.queens[side]);

		Move diag_move;
		diag_move.set_piece(pieces::QUEENS[side]);
		generate_diagonal_slider_moves(moves, position, side, diag_move, position.queens[side]);
	}
    
	MoveVector generate_all_moves(const Position &position, Side side)
    {
        MoveVector moves;
        moves.reserve(OINK_MOVE_VECTOR_INITIAL_SIZE);

        generate_rook_moves(moves, position, side);
        generate_knight_moves(moves, position, side);
        generate_bishop_moves(moves, position, side);
        generate_queen_moves(moves, position, side);
        generate_king_moves(moves, position, side);
        generate_pawn_moves(moves, position, side);

        return moves;
    }
}