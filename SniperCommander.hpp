//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_SNIPERCOMMANDER_HPP
#define WARGAME_A_SNIPERCOMMANDER_HPP

#include "Sniper.hpp"

class SniperCommander: public Sniper {
    static const int DMG = 100;
    static const int HP = 120;

protected:
    void act(pair<int, int> src, vector<vector<Soldier *>> &board) override;

public:
    SniperCommander(int player): Sniper(player, HP, "SC", DMG){}
};



#endif //WARGAME_A_SNIPERCOMMANDER_HPP
