//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_PARAMEDIC_HPP
#define WARGAME_A_PARAMEDIC_HPP

#include "Soldier.hpp"

namespace WarGame {
    class Paramedic : public Soldier{
        static const int HEAL = 200;//Full HP TODO:Fix for heal full not depending on the class
        static const int HP = 100;

    public:
        Paramedic(int player): Soldier(player, HP, "P "){}
        void act(pair<int, int> src, vector<vector<Soldier *>> &board) override;
    };
}


#endif //WARGAME_A_PARAMEDIC_HPP
