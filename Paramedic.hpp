//
// Created by osboxes on 5/22/20.
//

#ifndef WARGAME_A_PARAMEDIC_HPP
#define WARGAME_A_PARAMEDIC_HPP

#include "Soldier.hpp"

namespace WarGame {
    class Paramedic : public Soldier{
        const int HEAL = 200;//Full HP TODO:Fix for heal full not depending on the class
        const int HP = 100;
    protected:
        void act(vector<vector<Soldier *>> &board) override;

    public:
        Paramedic(int player): Soldier(player, HP){}
        void move(MoveDIR dir, vector<vector<Soldier *>> &board) override;
    };
}


#endif //WARGAME_A_PARAMEDIC_HPP
