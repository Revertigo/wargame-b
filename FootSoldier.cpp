//
// Created by osboxes on 5/19/20.
//

#include <stdexcept>
#include "FootSoldier.hpp"

namespace WarGame {

    void FootSoldier::act(vector<vector<Soldier*>> & board) {
        pair<int, int> target = find_closest_enemy(board);
        board[target.first][target.second]->damage(DMG);//damage the target player's soldier
    }
}