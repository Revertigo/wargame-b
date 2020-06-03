//
// Created by osboxes on 5/22/20.
//

#include "SniperCommander.hpp"
#include "Sniper.hpp"

namespace WarGame{

    void SniperCommander::act(pair<int, int> src , vector<vector<Soldier *>> &board) {
        pair<int, int> target = Sniper::find_strongest_enemy(src, board);
        board[target.first][target.second]->damage(DMG, target, board);//damage the target player's soldier
        actuate_subordinates<Sniper>(board);
    }
}