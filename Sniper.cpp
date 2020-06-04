//
// Created by osboxes on 5/22/20.
//

#include "Sniper.hpp"

void Sniper::act(pair<int, int> src, vector<vector<Soldier *>> &board) {
    pair<int, int> target = find_strongest_enemy(src, board);
    if(!(target.first == -1 || target.second == -1)) {
        board[target.first][target.second]->damage(_dmg, target, board);//damage the target player's soldier
    }
}

pair<int,int> Sniper::find_strongest_enemy(pair<int, int> src, vector<vector<Soldier*>> & board)
{
    double max_hp = 0;
    pair<int,int> result(-1,-1);//mark it as unassigned

    for(int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] && board[i][j]->getPlayer() != board[src.first][src.second]->getPlayer()) {
                double hp = board[i][j]->getHp();
                if (hp > max_hp) {
                    max_hp = hp;
                    result = {i, j};
                }
            }
        }
    }

    return result;
}

