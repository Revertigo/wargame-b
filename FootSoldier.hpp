//
// Created by osboxes on 5/19/20.
//

#ifndef WARGAME_A_FOOTSOLDIER_HPP
#define WARGAME_A_FOOTSOLDIER_HPP

#include "Soldier.hpp"

namespace WarGame {
    class FootSoldier: public Soldier {
        const int DMG = 10;
        const int HP = 100;
    protected:
        void act(vector<vector<Soldier*>> & board) override;

    public:
        FootSoldier(int player): Soldier(player, HP){}
        void move(MoveDIR dir, vector<vector<Soldier*>> & board) override;

    };
}

#endif //WARGAME_A_FOOTSOLDIER_HPP
