//
// Created by osboxes on 5/19/20.
//

#include "FootCommander.hpp"
#include "FootSoldier.hpp"

namespace WarGame {
    void FootCommander::act(pair<int, int> src, vector<vector<Soldier *>> &board) {
        pair<int, int> target = FootSoldier::find_closest_enemy(src, board);
        if(!(target.first == -1 || target.second == -1)) {
            board[target.first][target.second]->damage(DMG, target, board);//damage the target player's soldier
            actuate_subordinates<FootSoldier>(board);
        }
    }
}
