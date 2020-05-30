//
// Created by osboxes on 5/19/20.
//

#ifndef WARGAME_A_FOOTCOMMANDER_HPP
#define WARGAME_A_FOOTCOMMANDER_HPP

#include "Soldier.hpp"

namespace WarGame {
    class FootCommander : public Soldier {
        const int DMG = 20;
        const int HP = 150;

    protected:
        void act(vector<vector<Soldier *>> &board) override;

    public:
        FootCommander(int player): Soldier(player, HP){}

        void move(MoveDIR dir, vector<vector<Soldier *>> &board) override;
    };
}


#endif //WARGAME_A_FOOTCOMMANDER_HPP
