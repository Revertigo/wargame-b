//
// Created by osboxes on 5/19/20.
//

#ifndef WARGAME_A_FOOTSOLDIER_HPP
#define WARGAME_A_FOOTSOLDIER_HPP

#include "Soldier.hpp"

namespace WarGame {
    class FootSoldier: public Soldier {
        static const int DMG = 10;
        static const int HP = 100;

    public:
        FootSoldier(int player): Soldier(player, HP, "FS"){}
        void act(vector<vector<Soldier*>> & board) override;
    };
}

#endif //WARGAME_A_FOOTSOLDIER_HPP
