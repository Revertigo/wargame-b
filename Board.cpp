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
        std::pair<int,int> updated_source;

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
            case Up: {
                if (board[source.first + 1][source.second]) {
                    throw invalid_argument("The target location is already populated");
                }

                board[source.first + 1][source.second] = soldier;
                updated_source = {source.first + 1, source.second};
                break;
            }
            case Down: {
                if (board[source.first - 1][source.second]) {
                    throw invalid_argument("The target location is already populated");
                }

                board[source.first - 1][source.second] = std::move(soldier);//Triggers the move assignment operator
                updated_source = {source.first - 1, source.second};
                break;
            }
            case Right: {
                if (board[source.first][source.second + 1]) {
                    throw invalid_argument("The target location is already populated");
                }

                board[source.first][source.second + 1] = std::move(soldier);//Triggers the move assignment operator
                updated_source = {source.first, source.second + 1};
                break;
            }
            case Left: {
                if (board[source.first][source.second - 1]) {
                    throw invalid_argument("The target location is already populated");
                }

                board[source.first][source.second - 1] = std::move(soldier);//Triggers the move assignment operator
                updated_source = {source.first, source.second - 1};
                break;
            }
            default: {
                throw invalid_argument("None existing direction");
            }

        }
        board[source.first][source.second] = nullptr;//set previous location to nullptr(mark as free location)

        soldier->move(updated_source, direction, board);
    }

    //Assuming addition of new troops is only at the beginning of the game
    bool Board::has_soldiers(uint player_number) {
        bool result = false;
        //It's probably the first time, we will scan the board in order to next time have that info.
        for(int i = 0; i < board.size() && !result; i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] && board[i][j]->getPlayer() == player_number) {
                    result = true;
                }
            }
        }

        return result;
    }

    void Board::print_board(void)
    {
        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if(board[i][j]) {
                    cout << board[i][j]->getName() << "   ";
                } else{
                    cout << "X " << "   ";
                }
            }
            cout << endl;
        }
    }
}
