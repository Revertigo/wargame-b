//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_SNIPER_HPP
#define WARGAME_A_SNIPER_HPP

#include "Soldier.hpp"

namespace WarGame {
    class Sniper : public Soldier{
        static const int DMG = 50;
        static const int HP = 100;

    public:
        Sniper(int player):Soldier(player, HP, "S "){}
        void act(pair<int, int> src, vector<vector<Soldier *>> &board) override;
    };
}


#endif //WARGAME_A_SNIPER_HPP
