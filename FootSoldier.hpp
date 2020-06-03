//
// Created by osboxes on 5/19/20.
//

#ifndef WARGAME_A_FOOTSOLDIER_HPP
#define WARGAME_A_FOOTSOLDIER_HPP

#include "Soldier.hpp"
#include "FootCommander.hpp"

namespace WarGame {
    class FootSoldier: public Soldier {
        friend class FootCommander;

        static const int DMG = 10;
        static const int HP = 100;

        static double distance(int x1, int y1, int x2, int y2);
        static pair<int,int> find_closest_enemy(pair<int, int> src, vector<vector<Soldier*>> & board);
    public:
        FootSoldier(int player): Soldier(player, HP, "FS"){}
        void act(pair<int, int> src, vector<vector<Soldier*>> & board) override;
    };
}

#endif //WARGAME_A_FOOTSOLDIER_HPP
