//
// Created by osboxes on 5/20/20.
//

#ifndef WARGAME_A_SOLDIER_HPP
#define WARGAME_A_SOLDIER_HPP

#include <exception>
#include <utility>
#include "MoveDIR.hpp"
#include <vector>
#include <string>

using namespace std;

namespace WarGame {
    class Soldier{

        double distance(int x1, int y1, int x2, int y2);
    protected:
        int _player;//1 or 2
        int _hp;
        pair<int,int> _loc;
        string _name;

        Soldier(int player, int hp, string name): _player(player), _hp(hp), _name(name){};

        pair<int,int> find_closest_enemy(vector<vector<Soldier*>> & board);
        pair<int,int> find_strongest_enemy(vector<vector<Soldier*>> & board);
    public:
        virtual void act(vector<vector<Soldier*>> & board) = 0;
        void move(MoveDIR dir, vector<vector<Soldier*>> & board);

        int getPlayer() const {return _player;}
        int getHp() const {return _hp;}
        const string getName() const {return _name;}
        const pair<int,int> &getLoc() const {return _loc;}
        void damage(int amount){_hp -= amount;}

        // Move Assignment Operator
        Soldier & operator=(Soldier&& other)
        {
            _player = exchange(other._player, 0);
            _hp = exchange(other._hp, 0);
            _loc = exchange(other._loc, nullptr);
            _name = exchange(other._name, nullptr);
            exchange(other, nullptr);//TODO:Check it's working !
            return *this;
        }
    };
}

#endif //WARGAME_A_SOLDIER_HPP
