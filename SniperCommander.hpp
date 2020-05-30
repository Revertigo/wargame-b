//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_SNIPERCOMMANDER_HPP
#define WARGAME_A_SNIPERCOMMANDER_HPP

#include "Soldier.hpp"
namespace WarGame {
    class SniperCommander: public Soldier {
        const int DMG = 100;
        const int HP = 120;

    protected:
        void act(vector<vector<Soldier *>> &board) override;

    public:
        SniperCommander(int player): Soldier(player, HP){}
        void move(MoveDIR dir, vector<vector<Soldier *>> &board) override;
    };
}


#endif //WARGAME_A_SNIPERCOMMANDER_HPP
