//
// Created by osboxes on 5/19/20.
//
#include "doctest.h"
#include "Board.hpp"
#include "MoveDIR.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace std;
using namespace WarGame;

#define BOARD_SIZE 5

TEST_CASE("Check FootSoldier behavior"){
    WarGame::Board b(BOARD_SIZE,BOARD_SIZE);

    CHECK(b.has_soldiers(1) == false);
    CHECK(b.has_soldiers(2) == false);

    b[{1,1}] = new FootSoldier(1);
    b[{2,2}] = new FootSoldier(2);

    b.print_board();

    CHECK(b.has_soldiers(1) == true);
    CHECK(b.has_soldiers(2) == true);

    int move = MoveDIR::Up;//First move UP
    int x_loc_f1 = 1;
    int x_loc_f2 = 2;
    for(int i = 0; i < 9; i++)
    {
        //Move UP, then DOWN, then UP...
        CHECK_NOTHROW(b.move(1, pair(x_loc_f1, 1), (MoveDIR)move));
        CHECK_NOTHROW(b.move(2, pair(x_loc_f2, 2), (MoveDIR)move));
        move = 1 - move;
        x_loc_f1 = 3 - x_loc_f1;
        x_loc_f2 = 5 - x_loc_f2;
    }
    CHECK_NOTHROW(b.move(1, pair(x_loc_f1, 1), (MoveDIR)move));
    CHECK_THROWS(b.move(2, pair(x_loc_f2, 2), (MoveDIR)move));//f2 should be dead now

    CHECK(b.has_soldiers(2) == false);//Player 1 has won ! wonder why
    CHECK(b.has_soldiers(1) == true);
}

TEST_CASE("Check FootCommander behavior"){
    Board b(BOARD_SIZE,BOARD_SIZE);

    b[{1,1}] = new FootCommander(1);
    b[{2,2}] = new FootCommander(2);
    b[{3,3}] = new FootSoldier(2);

    int move = MoveDIR::Down;//Starting move is Down
    int x_loc_ft2 = 2;
    int x_loc_f1 = 1;

    //player's 1 FootCommander should be dead after exactly 5 rounds
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        //Move DOWN, then UP, then DOWN...
        CHECK_NOTHROW(b.move(1, pair(x_loc_f1, 1), (MoveDIR)move));//Moves FootSoldier
        CHECK_NOTHROW(b.move(2, pair(x_loc_ft2, 2), (MoveDIR)move));//Moves FootCommander
        move = 1 - move;
        x_loc_f1 = 1 - x_loc_f1;
        x_loc_ft2 = 3 - x_loc_ft2;
    }

    CHECK(b.has_soldiers(1) == false);
    CHECK(b.has_soldiers(2) == true);//Player 2 has won ! wonder why
}

TEST_CASE("Check Sniper behavior"){
    Board b(BOARD_SIZE,BOARD_SIZE);

    b[{2,2}] = new Sniper(1);
    b[{3,3}] = new Sniper(2);
    b[{1,1}] = new FootSoldier(1);
    b[{4,4}] = new FootSoldier(2);

    CHECK(b.has_soldiers(1) == true);
    CHECK(b.has_soldiers(2) == true);

    int move = MoveDIR::Left; //First move Left
    int y_loc_s1 = 2;
    int y_loc_s2 = 3;
    //Player 1 should win after 4 moves with sniper
    for(int i = 0; i < 2; i++)
    {
        CHECK(b.has_soldiers(2) == true);
        CHECK(b.has_soldiers(1) == true);
        CHECK_NOTHROW(b.move(1, pair(2, y_loc_s1), (MoveDIR)move));
        CHECK_NOTHROW(b.move(2, pair(3, y_loc_s2), (MoveDIR)move));
        move = 5 - move;
        y_loc_s1 = 3 - y_loc_s1;
        y_loc_s2 = 5 - y_loc_s2;
    }

    CHECK_NOTHROW(b.move(1, pair(2, y_loc_s1), (MoveDIR)move));
    move = 5 - move;
    y_loc_s1 = 3 - y_loc_s1;
    CHECK(b.has_soldiers(2) == true);
    CHECK_NOTHROW(b.move(1, pair(2, y_loc_s1), (MoveDIR)move));

    CHECK(b.has_soldiers(2) == false);//Player 1 should win
    CHECK(b.has_soldiers(1) == true);
}

TEST_CASE("Check SniperCommander behavior"){
    Board b(BOARD_SIZE,BOARD_SIZE);

    b[{2,2}] = new SniperCommander(1);
    b[{3,3}] = new SniperCommander(2);
    b[{1,1}] = new Sniper(1);
    b[{4,4}] = new FootSoldier(2);

    CHECK(b.has_soldiers(1) == true);
    CHECK(b.has_soldiers(2) == true);

    int move = MoveDIR::Left; //First move Left
    int y_loc_s1 = 2;
    int y_loc_s2 = 3;
    //Player 1 should win after 2 moves with sniper

    CHECK(b.has_soldiers(2) == true);
    CHECK(b.has_soldiers(1) == true);
    CHECK_NOTHROW(b.move(1, pair(2, y_loc_s1), (MoveDIR)move));
    CHECK_NOTHROW(b.move(2, pair(3, y_loc_s2), (MoveDIR)move));
    move = 5 - move;
    y_loc_s1 = 3 - y_loc_s1;
    y_loc_s2 = 5 - y_loc_s2;

    CHECK(b.has_soldiers(2) == true);
    CHECK_NOTHROW(b.move(1, pair(2, y_loc_s1), (MoveDIR)move));
    CHECK_THROWS(b.move(2, pair(3, y_loc_s2), (MoveDIR)move));//The SC2 should be dead
    CHECK_THROWS(b.move(2, pair(4, 4), (MoveDIR)move));//The FS should be dead
    move = 5 - move;
    y_loc_s1 = 3 - y_loc_s1;
    CHECK_NOTHROW(b.move(1, pair(2, y_loc_s1), (MoveDIR)move));//SC1 Should be alive
    CHECK_NOTHROW(b.move(1, pair(1, 1), (MoveDIR)move));//S1 Should be alive

    CHECK(b.has_soldiers(2) == false);//Player 1 should win
    CHECK(b.has_soldiers(1) == true);
}

TEST_CASE("Check Paramdedic behavior"){
    Board b(BOARD_SIZE,BOARD_SIZE);

    b[{2,2}] = new Paramedic(1);
    b[{3,3}] = new Paramedic(2);
    b[{1,1}] = new Sniper(1);
    b[{4,4}] = new Sniper(2);
    b[{3,1}] = new FootCommander(1);

    CHECK(b.has_soldiers(1) == true);
    CHECK(b.has_soldiers(2) == true);

    int move = MoveDIR::Left; //First move Left
    int y_loc_p1 = 2;
    int y_loc_p2 = 3;
    int y_loc_s1 = 1;
    int y_loc_s2 = 4;
    int y_loc_f1 = 1;

    //After 5 rounds p2 should be dead
    for(int i = 0; i < 4; i++)
    {
        CHECK(b.has_soldiers(2) == true);
        CHECK(b.has_soldiers(1) == true);
        CHECK_NOTHROW(b.move(1, pair(3, y_loc_f1), (MoveDIR)move));//Always target adversary paramedic
        CHECK_NOTHROW(b.move(1, pair(1, y_loc_s1), (MoveDIR)move));
        CHECK_NOTHROW(b.move(2, pair(4, y_loc_s2), (MoveDIR)move));
        CHECK_NOTHROW(b.move(1, pair(2, y_loc_p1), (MoveDIR)move));
        CHECK_NOTHROW(b.move(2, pair(3, y_loc_p2), (MoveDIR)move));

        move = 5 - move;
        y_loc_p1 = 3 - y_loc_p1;
        y_loc_p2 = 5 - y_loc_p2;
        y_loc_s1 = 1 - y_loc_s1;
        y_loc_s2 = 7 - y_loc_s2;
        y_loc_f1 = 1 - y_loc_f1;
    }

    CHECK(b.has_soldiers(2) == true);
    CHECK(b.has_soldiers(1) == true);
    CHECK_NOTHROW(b.move(1, pair(3, y_loc_f1), (MoveDIR)move));//Always target adversary paramedic
    CHECK_NOTHROW(b.move(1, pair(2, y_loc_s1), (MoveDIR)move));
    CHECK_NOTHROW(b.move(2, pair(3, y_loc_s2), (MoveDIR)move));
    CHECK_NOTHROW(b.move(1, pair(2, y_loc_p1), (MoveDIR)move));
    CHECK_THROWS(b.move(2, pair(3, y_loc_p2), (MoveDIR)move));//Check p2 is dead
    CHECK(b.has_soldiers(2) == true);//Check p2 still has soldiers(s2)

    move = 5 - move;
    y_loc_s1 = 1 - y_loc_s1;
    y_loc_s2 = 7 - y_loc_s2;

    CHECK_NOTHROW(b.move(1, pair(2, y_loc_s1), (MoveDIR)move));//Should kill s2(he now has 50 HP)
    CHECK_THROWS(b.move(2, pair(3, y_loc_s2), (MoveDIR)move));//Should be dead

    CHECK(b.has_soldiers(2) == false);//Player 1 should win
    CHECK(b.has_soldiers(1) == true);
}

TEST_CASE("Check ParamdedicCommander behavior"){
    Board b(BOARD_SIZE,BOARD_SIZE);

    b[{2,2}] = new Paramedic(1);
    b[{3,3}] = new Paramedic(2);
    b[{1,1}] = new FootCommander(1);
    b[{4,4}] = new Sniper(2);
    b[{1,4}] = new ParamedicCommander(1);

    CHECK(b.has_soldiers(1) == true);
    CHECK(b.has_soldiers(2) == true);

    int move = MoveDIR::Left; //First move Left
    int y_loc_p2 = 3;
    int y_loc_fc1 = 1;
    int y_loc_s2 = 4;
    int y_loc_pc1 = 4;

    /**
     * After 10 rounds p1 should win for sure(since he is always cured by p1 triggered by pc1).
     * On the other end, fc1 always attacks p2 so after 5 rounds he should be dead(since it doesn't heal itself).
     */
    for(int i = 0; i < 4; i++)
    {
        CHECK(b.has_soldiers(2) == true);
        CHECK(b.has_soldiers(1) == true);

        CHECK_NOTHROW(b.move(1, pair(1, y_loc_fc1), (MoveDIR)move));//Always target adversary paramedic
        CHECK_NOTHROW(b.move(2, pair(4, y_loc_s2), (MoveDIR)move));
        CHECK_NOTHROW(b.move(2, pair(3, y_loc_p2), (MoveDIR)move));
        CHECK_NOTHROW(b.move(1, pair(1, y_loc_pc1), (MoveDIR)move));

        move = 5 - move;
        y_loc_p2 = 5 - y_loc_p2;
        y_loc_fc1 = 1 - y_loc_fc1;
        y_loc_s2 = 7 - y_loc_s2;
        y_loc_pc1 = 7 - y_loc_pc1;
    }

    CHECK(b.has_soldiers(2) == true);
    CHECK(b.has_soldiers(1) == true);
    CHECK_NOTHROW(b.move(1, pair(1, y_loc_fc1), (MoveDIR)move));//Always target adversary paramedic
    CHECK_NOTHROW(b.move(2, pair(4, y_loc_s2), (MoveDIR)move));
    CHECK_THROWS(b.move(2, pair(3, y_loc_p2), (MoveDIR)move));//p2 should be dead now
    CHECK_NOTHROW(b.move(1, pair(1, y_loc_pc1), (MoveDIR)move));
    CHECK(b.has_soldiers(2) == true);//Check p2 still has soldiers(s2)

    move = 5 - move;
    y_loc_fc1 = 1 - y_loc_fc1;
    y_loc_s2 = 7 - y_loc_s2;
    y_loc_pc1 = 7 - y_loc_pc1;

    //Now without the dead p2
    for(int i = 0; i < 4; i++)
    {
        CHECK(b.has_soldiers(2) == true);
        CHECK(b.has_soldiers(1) == true);

        CHECK_NOTHROW(b.move(1, pair(1, y_loc_fc1), (MoveDIR)move));//Always target adversary paramedic
        CHECK_NOTHROW(b.move(2, pair(4, y_loc_s2), (MoveDIR)move));
        CHECK_NOTHROW(b.move(1, pair(1, y_loc_pc1), (MoveDIR)move));

        move = 5 - move;
        y_loc_fc1 = 1 - y_loc_fc1;
        y_loc_s2 = 7 - y_loc_s2;
        y_loc_pc1 = 7 - y_loc_pc1;
    }
    CHECK(b.has_soldiers(2) == true);
    CHECK(b.has_soldiers(1) == true);
    CHECK_NOTHROW(b.move(1, pair(1, y_loc_fc1), (MoveDIR)move));//Always target adversary paramedic
    CHECK_THROWS(b.move(2, pair(4, y_loc_s2), (MoveDIR)move));//sniper2 should be dead now
    CHECK_NOTHROW(b.move(1, pair(1, y_loc_pc1), (MoveDIR)move));

    CHECK(b.has_soldiers(2) == false);//Player 1 should win
    CHECK(b.has_soldiers(1) == true);
}