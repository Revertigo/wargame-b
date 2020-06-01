//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_SNIPERCOMMANDER_HPP
#define WARGAME_A_SNIPERCOMMANDER_HPP

#include "Soldier.hpp"
namespace WarGame {
    class SniperCommander: public Soldier {
        static const int DMG = 100;
        static const int HP = 120;

    protected:
        void act(vector<vector<Soldier *>> &board) override;

    public:
        SniperCommander(int player): Soldier(player, HP, "SC"){}
    };
}


#endif //WARGAME_A_SNIPERCOMMANDER_HPP
