//
// Created by osboxes on 6/4/20.
//

/**
 * .ipp/.tpp(iline/template) is sort of like header file but intended for templates function implementations(just a common convention).
 * Since it's is like a header file, it can be included and thus making the generation of
 * function templates code(behind scenes) visible to other compilation units(for example, when SniperCommander
 * will try to generate the code with <Sniper> the code will be successfully generated at compile time
 * and be visible to it's translation unit(unlike with .cpp files).
 * To the compiler, the extension of the file doesn't really matter.
 */
#pragma once

namespace WarGame {
    template<typename T>
    void Soldier::actuate_subordinates(vector<vector<Soldier *>> &board) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                T *subordinate = dynamic_cast<T *>(board[i][j]);
                //Check it actually FootSoldier and they are on the same team
                if (subordinate && subordinate->getPlayer() == _player) {
                    subordinate->act({i, j}, board);//Make him attack the enemy as well !
                }
            }
        }
    }
}
