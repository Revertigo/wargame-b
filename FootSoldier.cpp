//
// Created by osboxes on 5/19/20.
//

#include <cmath>
#include "FootSoldier.hpp"

namespace WarGame {

    //https://www.geeksforgeeks.org/program-calculate-distance-two-points/
    double FootSoldier::distance(int x1, int y1, int x2, int y2)
    {
        // Calculating distance
        return sqrt(pow(x2 - x1, 2) +
                    pow(y2 - y1, 2) * 1.0);
    }

    pair<int,int> FootSoldier::find_closest_enemy(pair<int, int> src, vector<vector<Soldier*>> & board)
    {
        double min_distance = numeric_limits<double>::max();//Assign MAX value
        pair<int,int> result(-1,-1);//mark it as unassigned

        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] && board[i][j]->getPlayer() != board[src.first][src.second]->getPlayer()) {
                    double dis = distance(src.first, src.second, i, j);
                    if (dis < min_distance) {
                        min_distance = dis;
                        result = {i, j};
                    }
                }
            }
        }

        return result;
    }

    void FootSoldier::act(pair<int, int> src, vector<vector<Soldier*>> & board) {
        pair<int, int> target = find_closest_enemy(src, board);
        if(!(target.first == -1 || target.second == -1)) {
            board[target.first][target.second]->damage(DMG, target, board);//damage the target player's soldier
        }
    }
}