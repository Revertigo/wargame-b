//
// Created by osboxes on 5/19/20.
//

#ifndef WARGAME_A_FOOTCOMMANDER_HPP
#define WARGAME_A_FOOTCOMMANDER_HPP

#include "FootSoldier.hpp"

class FootCommander : public FootSoldier {
    using FootSoldier::FootSoldier;
    static const int DMG = 20;
    static const int HP = 150;

protected:
    void act(pair<int, int> src, vector<vector<Soldier *>> &board) override;

public:
    FootCommander(int player): FootSoldier(player, HP, "FC", DMG){}
};



#endif //WARGAME_A_FOOTCOMMANDER_HPP
