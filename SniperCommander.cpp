//
// Created by osboxes on 5/22/20.
//

#include "SniperCommander.hpp"
#include "Sniper.hpp"

void SniperCommander::act(pair<int, int> src , vector<vector<Soldier *>> &board) {
    Sniper::act(src, board);
    actuate_subordinates<Sniper>(board);
}
