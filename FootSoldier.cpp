//
// Created by osboxes on 5/19/20.
//

#include <stdexcept>
#include "FootSoldier.hpp"

namespace WarGame {

    void FootSoldier::act(vector<vector<Soldier*>> & board) {
        pair<int, int> target = find_closet_enemy(board);
        board[target.first][target.second]->damage(DMG);//damage the target player's soldier
    }

    void FootSoldier::move(MoveDIR dir, vector<vector<Soldier*>> & board) {
        switch (dir)
        {
            case Up:
            {
                _loc.first +=1;//first = x, second = y
                break;
            }
            case Down:
            {
                _loc.first -=1;
                break;
            }
            case Right:
            {
                _loc.second +=1;
                break;
            }
            case Left:
            {
                _loc.second -=1;
                break;
            }
            default:
            {
                throw invalid_argument("Unknown direction");
            }
        }

        act(board);
    }
}