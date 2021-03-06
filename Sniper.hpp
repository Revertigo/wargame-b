//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_SNIPER_HPP
#define WARGAME_A_SNIPER_HPP

#include "Soldier.hpp"

class Sniper : public WarGame::Soldier{
    using Soldier::Soldier;

    static const int DMG = 50;
    static const int HP = 100;

    static pair<int,int> find_strongest_enemy(pair<int, int> src, vector<vector<Soldier*>> & board);
public:
    Sniper(int player):Soldier(player, HP, "S ", DMG){}
    void act(pair<int, int> src, vector<vector<Soldier *>> &board) override;
};



#endif //WARGAME_A_SNIPER_HPP
