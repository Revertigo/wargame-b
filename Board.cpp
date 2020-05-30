//
// Created by osboxes on 5/19/20.
//

#include "Board.hpp"

namespace WarGame {
    Soldier *&Board::operator[](std::pair<int, int> location) {
        return board[location.first][location.second];
    }

    Soldier *Board::operator[](std::pair<int, int> location) const {
        return board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int,int> source, WarGame::MoveDIR direction)
    {
        return;
    }

    bool Board::has_soldiers(uint player_number) const {
        return true;
    }
}
