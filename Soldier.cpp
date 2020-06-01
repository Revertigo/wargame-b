//
// Created by osboxes on 5/30/20.
//

#include <cmath>
#include "Soldier.hpp"
#include <stdexcept>

namespace WarGame {

    //https://www.geeksforgeeks.org/program-calculate-distance-two-points/
    double Soldier::distance(int x1, int y1, int x2, int y2)
    {
        // Calculating distance
        return sqrt(pow(x2 - x1, 2) +
                    pow(y2 - y1, 2) * 1.0);
    }

    pair<int,int> Soldier::find_closest_enemy(vector<vector<Soldier*>> & board)
    {
        double min_distance = numeric_limits<double>::max();//Assign MAX value
        pair<int,int> result(-1,-1);//mark it as unassigned

        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != nullptr && board[i][j]->getPlayer() != _player) {
                    double dis = distance(_loc.first, _loc.second, board[i][j]->getLoc().first,
                                          board[i][j]->getLoc().second);
                    if (dis < min_distance) {
                        min_distance = dis;
                        result = board[i][j]->getLoc();
                    }
                }
            }
        }

        return result;
    }

    pair<int,int> Soldier::find_strongest_enemy(vector<vector<Soldier*>> & board)
    {
        double max_hp = 0;
        pair<int,int> result(-1,-1);//mark it as unassigned

        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != nullptr && board[i][j]->getPlayer() != _player) {
                    double hp = board[i][j]->getHp();
                    if (hp > max_hp) {
                        max_hp = hp;
                        result = board[i][j]->getLoc();
                    }
                }
            }
        }

        return result;
    }

    void Soldier::move(MoveDIR dir, vector<vector<Soldier *>> &board) {
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