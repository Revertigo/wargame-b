//
// Created by osboxes on 5/22/20.
//

#include "SniperCommander.hpp"
#include "Sniper.hpp"

namespace WarGame{

    void SniperCommander::act(pair<int, int> src , vector<vector<Soldier *>> &board) {
        pair<int, int> target = find_strongest_enemy(board);
        board[target.first][target.second]->damage(DMG, target, board);//damage the target player's soldier
        actuate_subordinate<Sniper>(board);
    }

//    void SniperCommander::actuate_subordinate(vector<vector<Soldier *>> &board)
//    {
//        for(int i = 0; i < board.size(); i++) {
//            for (int j = 0; j < board[i].size(); j++) {
//                FootSoldier *subordinate = dynamic_cast<FootSoldier*>(board[i][j]);
//                //Check it actually FootSoldier and they are on the same team
//                if (subordinate && board[i][j]->getPlayer() == _player) {
//                    subordinate->act({i, j}, board);//Make him attack the enemy as well !
//                }
//            }
//        }
//    }

}