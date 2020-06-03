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
#include <algorithm>
#include <iostream>


using namespace std;

namespace WarGame {
    class Soldier{
        const int _INITIAL_HP;
    protected:
        int _player;//1 or 2
        int _hp;
        string _name;

        Soldier(int player, int hp, string name): _player(player), _hp(hp), _name(name), _INITIAL_HP(hp){};

        virtual void act(pair<int, int> src, vector<vector<Soldier*>> & board) = 0;

        template <class T>
        void actuate_subordinates(vector<vector<Soldier *>> &board) {

            for(int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    T * subordinate = dynamic_cast<T*>(board[i][j]);
                    //Check it actually FootSoldier and they are on the same team
                    if (subordinate && subordinate->getPlayer() == _player) {
                        subordinate->act({i, j}, board);//Make him attack the enemy as well !
                    }
                }
            }
        }

    public:
        virtual ~Soldier(){}//We want to call delete of the correct object
        void move(pair<int, int> src, MoveDIR dir, vector<vector<Soldier*>> & board);
        int getPlayer() const {return _player;}
        int getHp() const {return _hp;}
        const string getName() const {return _name;}
        void damage(const int amount, pair<int,int> loc, vector<vector<Soldier *>> &board);
        void heal(void){_hp = _INITIAL_HP;}

        // Move assignment operator
//        Soldier & operator=(Soldier & other)
//        {
//            if(this != &other) {
//                _player = exchange(other._player, 0);
//                _hp = exchange(other._hp, 0);
//                _name = std::move(other._name);
//            }
//            return *this;
//        }
//        //Copy assignment operator
//        Soldier & operator=(Soldier & other)
//        {
//            cout << "Inside assignment operator" << endl;
//            std::swap(_player, other._player);
//            std::swap(_hp, other._hp);
//            std::swap(_name, other._name);
//
//            return *this;
//        }
    };
}

#endif //WARGAME_A_SOLDIER_HPP
