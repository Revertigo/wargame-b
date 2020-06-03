//
// Created by osboxes on 5/30/20.
//

#include "Soldier.hpp"

namespace WarGame {

    void Soldier::move(pair<int, int> src, MoveDIR dir, vector<vector<Soldier *>> &board) {
        act(src, board);
    }

    void Soldier::damage(const int amount, pair<int,int> loc, vector<vector<Soldier *>> &board) {
        _hp -= amount;
        if(getHp() <= 0)
        {
            delete this;
            board[loc.first][loc.second] = nullptr;
        }
    }
}