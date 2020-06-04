//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_PARAMEDICCOMMANDER_HPP
#define WARGAME_A_PARAMEDICCOMMANDER_HPP

#include "Paramedic.hpp"

class ParamedicCommander: public Paramedic{
    static const int HP = 200;

protected:
    void act(pair<int, int> src, vector<vector<Soldier *>> &board) override;

public:
    ParamedicCommander(int player) : Paramedic(player, HP, "PC", 0) {}
};



#endif //WARGAME_A_PARAMEDICCOMMANDER_HPP
