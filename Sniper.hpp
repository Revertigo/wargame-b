//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_SNIPER_HPP
#define WARGAME_A_SNIPER_HPP

#include "Soldier.hpp"

namespace WarGame {
    class Sniper : public Soldier{
        const int DMG = 50;
        const int HP = 100;
    protected:
        void act(vector<vector<Soldier *>> &board) override;

    public:
        Sniper(int player):Soldier(player, HP){}
    };
}


#endif //WARGAME_A_SNIPER_HPP
