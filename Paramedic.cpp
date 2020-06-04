//
// Created by osboxes on 5/22/20.
//

#include "Paramedic.hpp"



void Paramedic::heal_teammates(pair<int, int> src, vector<vector<Soldier *>> &board)
{
    vector<vector<Soldier *>> helper_board(board.size() + 2, std::vector<Soldier*>(board[0].size() + 2, nullptr));

    //Copy small board into bigger temporary board
    for(int i = 1; i < helper_board.size() - 1; i++)
    {
        for(int j = 1; j < helper_board[i].size() - 1; j++)
        {
            helper_board[i][j] = board[i - 1][j - 1];
        }
    }

    pair<int,int> helper_src = {src.first + 1, src.second + 1};
    //Now we can easily compare and heal without check specifically all boundaries.
    for(int i = helper_src.first-1; i <  helper_src.first + 2; i++){
        for(int j = helper_src.second - 1; j < helper_src.second + 2; j++){
            //If there is a soldier and he is on my team and it's not me - then heal !
            if(helper_board[i][j] && helper_board[helper_src.first][helper_src.second]->getPlayer() == helper_board[i][j]->getPlayer() &&
                    (i != helper_src.first || j != helper_src.second))
            {
                helper_board[i][j]->heal();
            }
        }
    }
}

void Paramedic::act(pair<int, int> src, vector<vector<Soldier *>> &board) {
    heal_teammates(src, board);
}

