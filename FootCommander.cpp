//
// Created by osboxes on 5/19/20.
//

#include "FootCommander.hpp"


void FootCommander::act(pair<int, int> src, vector<vector<Soldier *>> &board) {
    FootSoldier::act(src, board);//Calls father implementation
    actuate_subordinates<FootSoldier>(board);
}
