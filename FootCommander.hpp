//
// Created by osboxes on 5/19/20.
//

#ifndef WARGAME_A_FOOTCOMMANDER_HPP
#define WARGAME_A_FOOTCOMMANDER_HPP

#include "Soldier.hpp"

namespace WarGame {
    class FootCommander : public Soldier {
        using Soldier::Soldier;
        static const int DMG = 20;
        static const int HP = 150;

        //void actuate_subordinates(vector<vector<Soldier *>> &board);
    protected:
        void act(pair<int, int> src, vector<vector<Soldier *>> &board) override;

    public:
        FootCommander(int player): Soldier(player, HP, "FC"){}
    };
}


#endif //WARGAME_A_FOOTCOMMANDER_HPP
