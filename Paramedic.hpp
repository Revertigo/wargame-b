//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_PARAMEDIC_HPP
#define WARGAME_A_PARAMEDIC_HPP

#include "Soldier.hpp"
#include "ParamedicCommander.hpp"


class Paramedic : public WarGame::Soldier{
    friend class ParamedicCommander;
    static const int HP = 100;

    static void heal_teammates(pair<int, int> src, vector<vector<Soldier *>> &board);
public:
    Paramedic(int player): Soldier(player, HP, "P "){}
    void act(pair<int, int> src, vector<vector<Soldier *>> &board) override;
};



#endif //WARGAME_A_PARAMEDIC_HPP
