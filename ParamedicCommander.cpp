//
// Created by osboxes on 5/22/20.
//

#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"

void ParamedicCommander::act(pair<int, int> src, vector<vector<Soldier *>> &board) {
    Paramedic::heal_teammates(src, board);
    actuate_subordinates<Paramedic>(board);
}

