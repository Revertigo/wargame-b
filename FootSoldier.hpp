//
// Created by osboxes on 5/19/20.
//

#ifndef WARGAME_A_FOOTSOLDIER_HPP
#define WARGAME_A_FOOTSOLDIER_HPP

#include "Soldier.hpp"


class FootSoldier: public WarGame::Soldier {
    using Soldier::Soldier;

    static const int DMG = 10;
    static const int HP = 100;
    int _dmg;

protected:
    double distance(int x1, int y1, int x2, int y2);
    pair<int,int> find_closest_enemy(pair<int, int> src, vector<vector<Soldier*>> & board);
    FootSoldier(int player, int hp, string name, int dmg): Soldier(player, hp, name), _dmg(dmg){}
public:
    FootSoldier(int player): FootSoldier(player, HP, "FS", DMG){}
    virtual void act(pair<int, int> src, vector<vector<Soldier*>> & board) override;
};


#endif //WARGAME_A_FOOTSOLDIER_HPP
