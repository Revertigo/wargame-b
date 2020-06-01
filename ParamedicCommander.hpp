//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_PARAMEDICCOMMANDER_HPP
#define WARGAME_A_PARAMEDICCOMMANDER_HPP

#include "Soldier.hpp"
namespace WarGame {
    class ParamedicCommander: public Soldier {
        static const int HEAL = 200;//TODO:Fix for heal full not depending on the class
        static const int HP = 200;

    protected:
        void act(vector<vector<Soldier *>> &board) override;

    public:
        ParamedicCommander(int player) : Soldier(player, HP, "PC") {}
    };
}


#endif //WARGAME_A_PARAMEDICCOMMANDER_HPP