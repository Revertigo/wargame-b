//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_PARAMEDICCOMMANDER_HPP
#define WARGAME_A_PARAMEDICCOMMANDER_HPP

#include "Soldier.hpp"
namespace WarGame {
    class ParamedicCommander: public Soldier {
        const int HEAL = 200;//TODO:Fix for heal full not depending on the class
        const int HP = 200;

    protected:
        void act(vector<vector<Soldier *>> &board) override;

    public:
        ParamedicCommander(int player) : Soldier(player, HP) {}

        void move(MoveDIR dir, vector<vector<Soldier *>> &board) override;
    };
}


#endif //WARGAME_A_PARAMEDICCOMMANDER_HPP
