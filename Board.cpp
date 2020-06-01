//
// Created by osboxes on 5/19/20.
//

#include "Board.hpp"
#include <stdexcept>
#include "MoveDIR.hpp"
#include <iostream>

using namespace std;
namespace WarGame {
    Soldier *&Board::operator[](std::pair<int, int> location) {
        return board[location.first][location.second];
    }

    Soldier *Board::operator[](std::pair<int, int> location) const {
        return board[location.first][location.second];
    }

    void Board::move(uint player_number, std::pair<int,int> source, WarGame::MoveDIR direction)
    {
        Soldier * soldier = board[source.first][source.second];
        if(!soldier)
        {
            throw invalid_argument("There is no soldier in this location");
        }
        if(soldier->getPlayer() != player_number)
        {
            throw invalid_argument("The troop belongs to the other player");
        }

        switch(direction)
        {
            case Up:
                if(board[source.first + 1][source.second])
                {
                    throw invalid_argument("The target location is already populated");
                }

                board[source.first + 1][source.second] = soldier;//Triggers the move assignment operator
                break;
            case Down:
                if(board[source.first - 1][source.second])
                {
                    throw invalid_argument("The target location is already populated");
                }

                board[source.first - 1][source.second] = soldier;//Triggers the move assignment operator
                break;
            case Right:
                if(board[source.first][source.second + 1])
                {
                    throw invalid_argument("The target location is already populated");
                }

                board[source.first][source.second + 1] = soldier;//Triggers the move assignment operator
                break;
            case Left:
                if(board[source.first][source.second - 1])
                {
                    throw invalid_argument("The target location is already populated");
                }

                board[source.first][source.second - 1] = soldier;//Triggers the move assignment operator
                break;
        }

        soldier->move(direction, board);
    }

    bool Board::has_soldiers(uint player_number) const {
        return counter_soldiers[player_number - 1] > 0;
    }

    void Board::print_board(void)
    {
        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                cout << board[i][j]->getName() << "   ";
            }
            cout << endl;
        }
    }
}
