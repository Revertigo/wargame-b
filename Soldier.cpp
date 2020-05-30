//
// Created by osboxes on 5/30/20.
//

#include <cmath>
#include "Soldier.hpp"

namespace WarGame {

    //https://www.geeksforgeeks.org/program-calculate-distance-two-points/
    double Soldier::distance(int x1, int y1, int x2, int y2)
    {
        // Calculating distance
        return sqrt(pow(x2 - x1, 2) +
                    pow(y2 - y1, 2) * 1.0);
    }

    pair<int,int> Soldier::find_closet_enemy(vector<vector<Soldier*>> & board)
    {
        double min_distance = numeric_limits<double>::max();
        pair<int,int> result(-1,-1);//Sign it as unassigned

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++)
                if(board[i][j] != nullptr && board[i][j]->getPlayer() != _player)
                {
                    double dis = distance(_loc.first, _loc.second, board[i][j]->getLoc().first, board[i][j]->getLoc().second);
                    if(dis < min_distance)
                    {
                        min_distance = dis;
                        result = board[i][j]->getLoc();
                    }
                }
        }

        return result;
    }
}