//
// Created by osboxes on 5/19/20.
//

#include "FootCommander.hpp"
#include "FootSoldier.hpp"

namespace WarGame {
    void FootCommander::act(vector<vector<Soldier *>> &board) {
        pair<int, int> target = find_closest_enemy(board);
        board[target.first][target.second]->damage(DMG);//damage the target player's soldier
        actuate_subordinate(board);
    }

    void FootCommander::actuate_subordinate(vector<vector<Soldier *>> &board)
    {
        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                FootSoldier *subordinate = dynamic_cast<FootSoldier*>(board[i][j]);
                //Check it actually FootSoldier and they are on the same team
                if (subordinate && board[i][j]->getPlayer() == _player) {
                    subordinate->act(board);//Make him attack the enemy as well !
                }
            }
        }
    }
}
