#ifndef CONSOLE_DISPLAY_HPP
#define CONSOLE_DISPLAY_HPP

#include <engine/ChessConstants.hpp>
#include <engine/Move.hpp>

#include <vector>
#include <utility>
#include <string>
#include <algorithm>

namespace chess
{
    class Position;

	void print_position(const Position &position);

    void print_bitboard(const Bitboard bitboard, Square highlight_square);
    void print_bitboard(const Bitboard bitboard);
    void print_bitboard(const Bitboard bitboard, const char* title);
    void print_bitboard(const Bitboard bitboard, const char* title, Square highlight_square);

	void print_bitboards(const std::vector<std::pair<Bitboard, std::string>> &bitboards, Square highlight_square = squares::NO_SQUARE);
    template<typename Cont>
    void print_bitboards(const Cont &bitboards, Square highlight_square = squares::NO_SQUARE)
    {
        std::vector<std::pair<Bitboard, std::string>> bbs_with_names;
        std::transform(std::begin(bitboards), std::end(bitboards), std::back_inserter(bbs_with_names), [](Bitboard b) { return std::make_pair(b, ""); } );
        print_bitboards(bbs_with_names, highlight_square);
    }

    void print_move(Move move, int move_num, Side side, util::PositionType pos_characteristics, PosEvaluationFrac eval);

    std::string move_to_coordtext(Move move);
}

#endif // CONSOLE_DISPLAY_HPP
