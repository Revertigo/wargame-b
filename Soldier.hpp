//
// Created by osboxes on 5/20/20.
//

#pragma once

#include <vector>
#include <string>

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

        template <typename T>
        void actuate_subordinates(vector<vector<Soldier *>> &board);

    public:
        virtual ~Soldier(){}//We want to call delete of the correct object
        void move(pair<int, int> src, vector<vector<Soldier*>> & board);
        int getPlayer() const {return _player;}
        int getHp() const {return _hp;}
        const string getName() const {return _name;}
        void damage(const int amount, pair<int,int> loc, vector<vector<Soldier *>> &board);
        void heal(void){_hp = _INITIAL_HP;}
    };
}

/**
 * put in the end of the file makes it possible for the header to include the .ipp file(which is visible to the compiler
 * when compiling this translation unit). On the other hand, if we put the inclusion in the start of the header,
 * the class Soldier is still not existed yet(because include directive do copy & paste) and thats why
 * we can't implement the template function.(You can't implement inside none existing class !!)
 */
#include "Soldier.ipp"
