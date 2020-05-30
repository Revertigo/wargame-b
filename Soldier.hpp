//
// Created by osboxes on 5/20/20.
//

#ifndef WARGAME_A_SOLDIER_HPP
#define WARGAME_A_SOLDIER_HPP

#include <exception>
#include <utility>
#include "MoveDIR.hpp"
#include <vector>

using namespace std;

namespace WarGame {
    class Soldier{

        double distance(int x1, int y1, int x2, int y2);
    protected:
        int _player;//1 or 2
        int _hp;
        pair<int,int> _loc;

        Soldier(int player, int hp): _player(player), _hp(hp){};
        virtual void act(vector<vector<Soldier*>> & board) = 0;

        pair<int,int> find_closet_enemy(vector<vector<Soldier*>> & board);
    public:
        virtual void move(MoveDIR dir, vector<vector<Soldier*>> & board) = 0;

        int getPlayer() const {return _player;}
        const pair<int,int> &getLoc() const {return _loc;}
        void damage(int amount){_hp -= amount;}
    };
}

#endif //WARGAME_A_SOLDIER_HPP
