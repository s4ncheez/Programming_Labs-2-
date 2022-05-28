#ifndef CUBE_H
#define CUBE_H
#include <utility>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Cube {
public:
    vector<vector<vector<int>>> sides;

    Cube() {
        sides.assign (6, vector<vector<int>> (3, vector<int> (3)));
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    sides[i][j][k] = i;
                }
            }
        }
    }

    bool is_cube_solved () {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (sides[i][j][k] != sides[i][1][1]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void right_turn (bool flag) {
        if (flag) {
            vector<vector<int>> side = sides[2];
            for (int i = 0; i < 3; i++) {
                for (int j = 2; j >= 0; j--) {
                    sides[2][i][2 - j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[1][0][2], sides[1][1][2], sides[1][2][2]};
            for (int i = 0; i < 3; i++){
                sides[1][i][2] = sides[0][i][2];
            }
            for (int i = 0; i < 3; i++){
                sides[0][i][2] = sides[3][2-i][0];
            }
            for (int i = 0; i < 3; i++){
                sides[3][i][0] = sides[5][2-i][2];
            }
            for (int i = 0; i < 3; i++){
                sides[5][i][2] = tmp[i];
            }
        }
        else {
            vector<vector<int>> side = sides[2];
            for (int i = 2; i >= 0; i--){
                for(int j = 0; j < 3; j++){
                    sides[2][2-i][j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[1][0][2], sides[1][1][2], sides[1][2][2]};
            for (int i = 0; i < 3; i++){
                sides[1][i][2] = sides[5][i][2];
            }
            for (int i = 0; i < 3; i++){
                sides[5][i][2] = sides[3][2-i][0];
            }
            for (int i = 0; i < 3; i++){
                sides[3][i][0] = sides[0][2-i][2];
            }
            for (int i = 0; i < 3; i++){
                sides[0][i][2] = tmp[i];
            }
        }
    }

    void left_turn (bool flag) {
        if (flag) {
            vector<vector<int>> side = sides[4];
            for (int i = 0; i < 3; i++){
                for (int j = 2; j >= 0; j--){
                    sides[4][i][2-j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[1][0][0], sides[1][1][0], sides[1][2][0]};
            for (int i = 0; i < 3; i++){
                sides[1][i][0] = sides[5][i][0];
            }
            for (int i = 0; i < 3; i++){
                sides[5][i][0] = sides[3][2-i][2];
            }
            for (int i = 0; i < 3; i++){
                sides[3][i][2] = sides[0][2-i][0];
            }
            for (int i = 0; i < 3; i++){
                sides[0][i][0] = tmp[i];
            }
        }
        else {
            vector<vector<int>> side = sides[4];
            for (int i = 2; i >= 0; i--){
                for (int j = 0; j < 3; j++){
                    sides[4][2-i][j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[1][0][0], sides[1][1][0], sides[1][2][0]};
            for (int i = 0; i < 3; i++){
                sides[1][i][0] = sides[0][i][0];
            }
            for (int i = 0; i < 3; i++){
                sides[0][i][0] = sides[3][2-i][2];
            }
            for (int i = 0; i < 3; i++){
                sides[3][i][2] = sides[5][2-i][0];
            }
            for (int i = 0; i < 3; i++){
                sides[5][i][0] = tmp[i];
            }
        }
    }

    void up_turn (bool flag) {
        if (flag) {
            vector<vector<int>> side = sides[5];
            for (int i = 0; i < 3; i++){
                for (int j = 2; j >= 0; j--){
                    sides[5][i][2-j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[1][0][0], sides[1][0][1], sides[1][0][2]};
            for (int i = 0; i < 3; i++){
                sides[1][0][i] = sides[2][0][i];
            }
            for (int i = 0; i < 3; i++){
                sides[2][0][i] = sides[3][0][i];
            }
            for (int i = 0; i < 3; i++){
                sides[3][0][i] = sides[4][0][i];
            }
            for (int i = 0; i < 3; i++){
                sides[4][0][i] = tmp[i];
            }
        }
        else {
            vector<vector<int>> side = sides[5];
            for (int i = 2; i >= 0; i--){
                for (int j = 0; j < 3; j++){
                    sides[5][2-i][j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[1][0][0], sides[1][0][1], sides[1][0][2]};
            for (int i = 0; i < 3; i++){
                sides[1][0][i] = sides[4][0][i];
            }
            for (int i = 0; i < 3; i++){
                sides[4][0][i] = sides[3][0][i];
            }
            for (int i = 0; i < 3; i++){
                sides[3][0][i] = sides[2][0][i];
            }
            for (int i = 0; i < 3; i++){
                sides[2][0][i] = tmp[i];
            }
        }
    }

    void down_turn (bool flag) {
        if (flag) {
            vector<vector<int>> side = sides[0];
            for (int i = 0; i < 3; i++){
                for (int j = 2; j >= 0; j--){
                    sides[0][i][2-j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[1][2][0], sides[1][2][1], sides[1][2][2]};
            for (int i = 0; i < 3; i++){
                sides[1][2][i] = sides[4][2][i];
            }
            for (int i = 0; i < 3; i++){
                sides[4][2][i] = sides[3][2][i];
            }
            for (int i = 0; i < 3; i++){
                sides[3][2][i] = sides[2][2][i];
            }
            for (int i = 0; i < 3; i++){
                sides[2][2][i] = tmp[i];
            }
        }
        else {
            vector<vector<int>> side = sides[0];
            for (int i = 2; i >= 0; i--){
                for (int j = 0; j < 3; j++){
                    sides[0][2-i][j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[1][2][0], sides[1][2][1], sides[1][2][2]};
            for (int i = 0; i < 3; i++){
                sides[1][2][i] = sides[2][2][i];
            }
            for (int i = 0; i < 3; i++){
                sides[2][2][i] = sides[3][2][i];
            }
            for (int i = 0; i < 3; i++){
                sides[3][2][i] = sides[4][2][i];
            }
            for (int i = 0; i < 3; i++){
                sides[4][2][i] = tmp[i];
            }
        }
    }

    void front_turn (bool flag) {
        if (flag) {
            vector<vector<int>> side = sides[1];
            for (int i = 0; i < 3; i++){
                for (int j = 2; j >= 0; j--){
                    sides[1][i][2-j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[2][0][0], sides[2][1][0], sides[2][2][0]};
            for (int i = 0; i < 3; i++){
                sides[2][i][0]=sides[5][2][i];
            }
            for (int i = 0; i < 3; i++){
                sides[5][2][i] = sides[4][2-i][2];
            }
            for (int i = 0; i < 3; i++){
                sides[4][i][2] = sides[0][0][i];
            }
            for (int i = 0; i < 3; i++){
                sides[0][0][2-i] = tmp[i];
            }
        }
        else {
            vector<vector<int>> side = sides[1];
            for (int i = 2; i >= 0; i--){
                for (int j = 0; j < 3; j++){
                    sides[1][2-i][j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[2][0][0], sides[2][1][0], sides[2][2][0]};
            for (int i = 0; i < 3; i++){
                sides[2][i][0] = sides[0][0][2-i];
            }
            for (int i = 0; i < 3; i++){
                sides[0][0][i] = sides[4][i][2];
            }
            for (int i = 0; i < 3; i++){
                sides[4][i][2] = sides[5][2][2-i];
            }
            for (int i = 0; i < 3; i++){
                sides[5][2][i] = tmp[i];
            }
        }
    }

    void back_turn (bool flag) {
        if (flag) {
            vector<vector<int>> side = sides[3];
            for (int i = 0; i < 3; i++){
                for (int j = 2; j >= 0; j--){
                    sides[3][i][2-j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[2][0][2], sides[2][1][2], sides[2][2][2]};
            for (int i = 0; i < 3; i++){
                sides[2][i][2] = sides[0][2][2-i];
            }
            for (int i = 0; i < 3; i++){
                sides[0][2][i] = sides[4][i][0];
            }
            for (int i = 0; i < 3; i++){
                sides[4][i][0] = sides[5][0][2-i];
            }
            for (int i = 0; i < 3; i++){
                sides[5][0][i] = tmp[i];
            }
        }
        else {
            vector<vector<int>> side = sides[3];
            for (int i = 2; i >= 0; i--){
                for (int j = 0; j < 3; j++){
                    sides[3][2-i][j] = side[j][i];
                }
            }
            vector<int> tmp = {sides[2][0][2], sides[2][1][2], sides[2][2][2]};
            for(int i = 0; i < 3; i++){
                sides[2][i][2] = sides[5][0][i];
            }
            for(int i = 0; i < 3; i++){
                sides[5][0][i] = sides[4][2-i][0];
            }
            for(int i = 0; i < 3; i++){
                sides[4][i][0] = sides[0][2][i];
            }
            for(int i = 0; i < 3; i++){
                sides[0][2][i] = tmp[2-i];
            }
        }
    }
};

class algorithm {
private:
    int Down_col, Front_col, Right_col, Back_col, Left_col, Up_col;
    Cube cube;
public:
    vector<int> actions;
    explicit algorithm (Cube _cube) {
        cube = move(_cube);
        Down_col = cube.sides[0][1][1];
        Front_col = cube.sides[1][1][1];
        Right_col = cube.sides[2][1][1];
        Back_col = cube.sides[3][1][1];
        Left_col = cube.sides[4][1][1];
        Up_col = cube.sides[5][1][1];
    }

    void turn (vector<int> turns) {
        for (int &turn: turns) {
            if (turn == 0) {
                cube.down_turn(true);
            }
            if (turn == 1) {
                cube.down_turn(false);
            }
            if (turn == 2) {
                cube.front_turn(true);
            }
            if (turn == 3) {
                cube.front_turn(false);
            }
            if (turn == 4) {
                cube.right_turn(true);
            }
            if (turn == 5) {
                cube.right_turn(false);
            }
            if (turn == 6) {
                cube.back_turn(true);
            }
            if (turn == 7) {
                cube.back_turn(false);
            }
            if (turn == 8) {
                cube.left_turn(true);
            }
            if (turn == 9) {
                cube.left_turn(false);
            }
            if (turn == 10) {
                cube.up_turn(true);
            }
            if (turn == 11) {
                cube.up_turn(false);
            }
            actions.push_back(turn);
        }
    }

    void first_step () {
        int counter=0;
        while (counter < 4){
            vector<vector<vector<int>>> sid = cube.sides;
            if (sid[1][0][1] == Front_col && sid[5][2][1] == Down_col){
                turn({2, 2});
                counter = 0;
                continue;
            }
            if (sid[2][0][1] == Right_col && sid[5][1][2] == Down_col){
                turn({4, 4});
                counter = 0;
                continue;
            }
            if (sid[4][0][1] == Left_col && sid[5][1][0] == Down_col){
                turn({8, 8});
                counter = 0;
                continue;
            }
            if (sid[3][0][1] == Back_col && sid[5][0][1] == Down_col){
                turn({6, 6});
                counter = 0;
                continue;
            }

            if (sid[1][0][1] == Down_col && sid[5][2][1] == Front_col){
                turn({11, 5, 2, 4});
                counter = 0;
                continue;
            }
            if (sid[2][0][1] == Down_col && sid[5][1][2] == Right_col){
                turn({11, 7, 4, 6});
                counter = 0;
                continue;
            }
            if (sid[4][0][1] == Down_col && sid[5][1][0] == Left_col){
                turn({11, 3, 8, 2});
                counter = 0;
                continue;
            }
            if (sid[3][0][1] == Down_col && sid[5][0][1] == Back_col){
                turn({11, 9, 6, 8});
                counter = 0;
                continue;
            }
            if (sid[1][1][2] == Down_col){
                turn({3, 11, 2});
                counter = 0;
                continue;
            }
            if (sid[2][1][2] == Down_col){
                turn({5, 11, 4});
                counter = 0;
                continue;
            }
            if (sid[4][1][2] == Down_col){
                turn({9, 11, 8});
                counter = 0;
                continue;
            }
            if (sid[3][1][2] == Down_col){
                turn({7, 11, 6});
                counter = 0;
                continue;
            }

            if (sid[1][1][0] == Down_col){
                turn({2, 11, 3});
                counter = 0;
                continue;
            }
            if (sid[2][1][0] == Down_col){
                turn({4, 11, 5});
                counter = 0;
                continue;
            }
            if (sid[4][1][0] == Down_col){
                turn({8, 11, 9});
                counter=0;
                continue;
            }
            if (sid[3][1][0] == Down_col){
                turn({6, 11, 7});
                counter = 0;
                continue;
            }

            if (sid[1][2][1] == Down_col){
                turn({2, 2, 11, 2, 2});
                counter = 0;
                continue;
            }
            if (sid[2][2][1] == Down_col){
                turn({4, 4, 11, 4, 4});
                counter = 0;
                continue;
            }
            if (sid[4][2][1] == Down_col){
                turn({8, 8, 11, 8, 8});
                counter = 0;
                continue;
            }
            if (sid[3][2][1] == Down_col){
                turn({6, 6, 11, 6, 6});
                counter = 0;
                continue;
            }

            if (sid[0][0][1] == Down_col && sid [1][2][1]!= Front_col){
                turn({2, 2, 11, 2, 2});
                counter = 0;
                continue;
            }
            if (sid[0][1][2] == Down_col && sid[2][2][1]!= Right_col){
                turn({4, 4, 11, 4, 4});
                counter = 0;
                continue;
            }
            if (sid[0][1][0] == Down_col && sid[4][2][1]!= Left_col){
                turn({8, 8, 11, 8, 8});
                counter = 0;
                continue;
            }
            if (sid[0][2][1] == Down_col && sid[3][2][1] != Back_col){
                turn({6, 6, 11, 6, 6});
                counter = 0;
                continue;
            }
            cube.up_turn(true);
            actions.push_back(10);
            counter++;
        }
        for (int i = 0; i < 4; i++){
            actions.pop_back();
            cube.up_turn(false);
        }
    }

    void second_step () {
        int counter = 0;
        while (counter < 4){
            vector<vector<vector<int>>> sid = cube.sides;
            if (sid[1][2][1] == Front_col && sid[1][0][2] == Down_col && sid[5][2][2] == Front_col && sid[2][0][0] == Right_col && sid[2][2][1] == Right_col){
                turn({3, 11, 2});
                counter = 0;
                continue;
            }
            if (sid[1][0][0] == Front_col && sid[1][2][1] == Front_col && sid[4][0][2] == Down_col && sid[4][2][1] == Left_col && sid[5][2][0] == Left_col){
                turn({9, 11, 8});
                counter = 0;
                continue;
            }
            if (sid[2][0][2] == Down_col && sid[2][2][1] == Right_col && sid[5][0][2] == Right_col && sid[3][0][0] == Back_col && sid[3][2][1] == Back_col){
                turn({5, 11, 4});
                counter = 0;
                continue;
            }
            if (sid[3][0][2] == Down_col && sid[3][2][1] == Back_col && sid[5][0][0] == Back_col && sid[4][0][0] == Left_col && sid[4][2][1] == Left_col){
                turn({7, 11, 6});
                counter = 0;
                continue;
            }
            if (sid[1][0][2] == Front_col && sid[1][2][1] == Front_col && sid[5][2][2] == Right_col && sid[2][0][0] == Down_col && sid[2][2][1] == Right_col){
                turn({4, 10, 5});
                counter = 0;
                continue;
            }
            if (sid[1][0][0] == Down_col && sid[1][2][1] == Front_col && sid[5][2][0] == Front_col && sid[4][2][1] == Left_col && sid[4][0][2] == Left_col){
                turn({2, 10, 3});
                counter = 0;
                continue;
            }
            if (sid[3][0][0] == Down_col && sid[3][2][1] == Back_col && sid[5][0][2] == Back_col && sid[2][0][2] == Right_col && sid[2][2][1] == Right_col){
                turn({6, 10, 7});
                counter = 0;
                continue;
            }
            if (sid[3][0][2] == Back_col && sid[3][2][1] == Back_col && sid[5][0][0] == Left_col && sid[4][0][0] == Down_col && sid[4][2][1] == Left_col){
                turn({8, 10, 9});
                counter = 0;
                continue;
            }
            if (sid[1][2][1] == Front_col && sid[1][0][2] == Right_col && sid[5][2][2] == Down_col && sid[2][0][0] == Front_col && sid[2][2][1] == Right_col){
                turn({4, 11, 5, 11, 11, 4, 10, 5});
                counter = 0;
                continue;
            }
            if (sid[1][0][0] == Left_col && sid[1][2][1] == Front_col && sid[5][2][0] == Down_col && sid[4][0][2] == Front_col && sid[4][2][1] == Left_col){
                turn({2, 11, 3, 11, 11, 2, 10, 3});
                counter = 0;
                continue;
            }
            if (sid[3][0][0] == Right_col && sid[3][2][1] == Back_col && sid[5][0][2] == Down_col && sid[2][0][2] == Back_col && sid[2][2][1] == Right_col){
                turn({6, 11, 7, 11, 11, 6, 10, 7});
                counter = 0;
                continue;
            }
            if (sid[3][2][1] == Back_col && sid[3][0][2] == Left_col && sid[5][0][0] == Down_col && sid[4][0][0] == Back_col && sid[4][2][1] == Left_col){
                turn({8, 11, 9, 11, 11, 8, 10, 9});
                counter = 0;
                continue;
            }
            if (sid[1][2][1] == Front_col && sid[1][2][2] == Down_col && sid[2][2][1] == Right_col){
                turn({3, 11, 2});
                counter=0;
                continue;
            }
            if (sid[1][2][1] == Front_col && sid[4][2][1] == Left_col && sid[4][2][2] == Down_col){
                turn({9, 11, 8});
                counter=0;
                continue;
            }
            if (sid[3][2][1] == Back_col && sid[2][2][1] == Right_col && sid[2][2][2] == Down_col){
                turn({5, 11, 4});
                counter=0;
                continue;
            }
            if (sid[3][2][2] == Down_col && sid[3][2][1] == Back_col && sid[4][2][1] == Left_col){
                turn({7, 11, 6});
                counter=0;
                continue;
            }

            if (sid[1][2][1] == Front_col && sid[2][2][0] == Down_col && sid[2][2][1] == Right_col){
                turn({3, 11, 2});
                counter=0;
                continue;
            }
            if (sid[1][2][0] == Down_col && sid[1][2][1] == Front_col && sid[4][2][1] == Left_col){
                turn({9, 11, 8});
                counter=0;
                continue;
            }
            if (sid[3][2][0] == Down_col && sid[3][2][1] == Back_col && sid[2][2][1] == Right_col){
                turn({5, 11, 4});
                counter=0;
                continue;
            }
            if (sid[3][2][1] == Back_col && sid[4][2][0] == Down_col && sid[4][2][1] == Left_col){
                turn({7, 11, 6});
                counter=0;
                continue;
            }

            if (sid[4][2][1] == Left_col && sid[1][2][1] == Front_col && sid[0][0][0] == Down_col && (sid[4][2][2] != Left_col || sid[1][2][0] != Front_col)){
                turn({2, 11, 3});
                counter=0;
                continue;
            }
            if (sid[2][2][1] == Right_col && sid[1][2][1] == Front_col && sid[0][0][2] == Down_col && (sid[1][2][2] != Front_col || sid[2][2][0] != Right_col)){
                turn({4, 11, 5});
                counter=0;
                continue;
            }
            if (sid[4][2][1] == Left_col && sid[3][2][1] == Back_col && sid[0][2][0] == Down_col && (sid[4][2][0] != Left_col || sid[3][2][2] != Back_col)){
                turn({8, 11, 9});
                counter=0;
                continue;
            }
            if (sid[3][2][1] == Back_col && sid[2][2][1] == Right_col && sid[0][2][2] == Down_col && (sid[2][2][2] != Right_col || sid[3][2][0] != Back_col)){
                turn({6, 11, 7});
                counter=0;
                continue;
            }
            cube.up_turn(true);
            actions.push_back(10);
            ++counter;
        }
        for (int i = 0; i < 4; i++){
            actions.pop_back();
            cube.up_turn(false);
        }
    }

    void third_step () {
        bool match = true;
        int stepcounter = 0;
        while (match) {
            stepcounter++;
            match = false;
            int counter = 0;
            while (counter < 4){
                vector<vector<vector<int>>> sid = cube.sides;
                if (sid[1][0][1] == Front_col && sid[5][2][1] == Left_col){
                    turn({11, 9, 10, 8, 10, 2, 11, 3});
                    counter = 0;
                    continue;
                }
                if (sid[2][0][1] == Right_col && sid[5][1][2] == Front_col){
                    turn({11, 3, 10, 2, 10, 4, 11, 5});
                    counter = 0;
                    continue;
                }
                if (sid[3][0][1] == Back_col && sid[5][0][1] == Right_col){
                    turn({11, 5, 10, 4, 10, 6, 11, 7});
                    counter = 0;
                    continue;
                }
                if (sid[4][0][1] == Left_col && sid[5][1][0] == Back_col){
                    turn({11, 7, 10, 6, 10, 8, 11, 9});
                    counter = 0;
                    continue;
                }
                if (sid[1][0][1] == Front_col && sid[5][2][1] == Right_col){
                    turn({10, 4, 11, 5, 11, 3, 10, 2});
                    counter = 0;
                    continue;
                }
                if (sid[4][0][1] == Left_col && sid[5][1][0] == Front_col){
                    turn({10, 2, 11, 3, 11, 9, 10, 8});
                    counter = 0;
                    continue;
                }
                if (sid[3][0][1] == Back_col && sid[5][0][1] == Left_col){
                    turn({10, 8, 11, 9, 11, 7, 10, 6});
                    counter = 0;
                    continue;
                }
                if (sid[2][0][1] == Right_col && sid[5][1][2] == Back_col){
                    turn({10, 6, 11, 7, 11, 5, 10, 4});
                    counter = 0;
                    continue;
                }
                cube.up_turn(true);
                actions.push_back(10);
                counter++;
            }
            if (stepcounter > 50) {
                break;
            }
            for (int i = 0; i < 4; i++){
                actions.pop_back();
                cube.up_turn(false);
            }
            if (cube.sides[1][1][2] != Front_col || cube.sides[2][1][0] != Right_col){
                turn({10, 4, 11, 5, 11, 3, 10, 2});
                match = true;
                continue;
            }
            if (cube.sides[1][1][0] != Front_col || cube.sides[4][1][2] != Left_col){
                turn({10, 2, 11, 3, 11, 9, 10, 8});
                match = true;
                continue;
            }
            if (cube.sides[3][1][2] != Back_col || cube.sides[4][1][0] != Left_col){
                turn({10, 8, 11, 9, 11, 7, 10, 6});
                match = true;
                continue;
            }
            if (cube.sides[3][1][0] != Back_col || cube.sides[2][1][2] != Right_col){
                turn({10, 6, 11, 7, 11, 5, 10, 4});
                match = true;
                continue;
            }
        }
    }

    void fourth_step () {
        vector<vector<vector<int>>> sid = cube.sides;
        if (sid[1][0][1] == Up_col && sid[2][0][1] == Up_col && sid[5][0][1] == Up_col && sid[5][1][0] == Up_col){
            turn({2, 10, 4, 11, 5, 3});
        }
        if (sid[1][0][1] == Up_col && sid[4][0][1] == Up_col && sid[5][0][1] == Up_col && sid[5][1][2] == Up_col){
            turn({8, 10, 2, 11, 3, 9});
        }
        if (sid[3][0][1] == Up_col && sid[2][0][1] == Up_col && sid[5][1][0] == Up_col && sid[5][2][1] == Up_col){
            turn({4, 10, 6, 11, 7, 5});
        }
        if (sid[3][0][1] == Up_col && sid[4][0][1] == Up_col && sid[5][1][2] == Up_col && sid[5][2][1] == Up_col){
            turn({6, 10, 8, 11, 9, 7});
        }
        if (sid[1][0][1] == Up_col && sid[3][0][1] == Up_col && sid[5][1][0] == Up_col && sid[5][1][2] == Up_col){
            turn({2, 4, 10, 5, 11, 3});
        }
        if (sid[4][0][1] == Up_col && sid[2][0][1] == Up_col && sid[5][0][1] == Up_col && sid[5][2][1] == Up_col){
            turn({4, 6, 10, 7, 11, 5});
        }
        if (sid[1][0][1] == Up_col && sid[2][0][1] == Up_col && sid[3][0][1] == Up_col && sid[4][0][1] == Up_col){
            turn({2, 10, 4, 11, 5, 3, 4, 6, 10, 7, 11, 5});
        }
    }

    void fifth_step () {
        if (cube.sides[2][0][1] == Front_col){
            turn({10, 9, 10, 10, 8, 10, 9, 10, 8});
        }
        if (cube.sides[4][0][1] == Front_col){
            turn({10, 7, 10, 10, 6, 10, 7, 10, 6});
        }
        if (cube.sides[3][0][1] == Front_col){
            turn({10, 5, 10, 10, 4, 10, 5, 10, 4, 10, 7, 10, 10, 6, 10, 7, 10, 6, 10, 5, 10, 10, 4, 10, 5, 10, 4});
        }
        if (cube.sides[3][0][1] == Right_col){
            turn({10, 3, 10, 10, 2, 10, 3, 10, 2});
        }
        if (cube.sides[4][0][1] == Right_col){
            turn({10, 7, 10, 10, 6, 10, 7, 10, 6, 10, 9, 10, 10, 8, 10, 9, 10, 8, 10, 7, 10, 10, 6, 10, 7, 10, 6});
        }
        if (cube.sides[4][0][1] == Back_col){
            turn({10, 5, 10, 10, 4, 10, 5, 10, 4});
        }
    }

    void sixth_step () {
        if ((cube.sides[1][0][0] == Right_col && cube.sides[5][2][0] == Up_col && cube.sides[4][0][2] == Front_col) ||
           (cube.sides[1][0][0] == Right_col && cube.sides[5][2][0] == Front_col && cube.sides[4][0][2] == Up_col) ||
           (cube.sides[1][0][0] == Front_col && cube.sides[5][2][0] == Up_col && cube.sides[4][0][2] == Right_col) ||
           (cube.sides[1][0][0] == Front_col && cube.sides[5][2][0] == Right_col && cube.sides[4][0][2] == Up_col) ||
           (cube.sides[1][0][0] == Up_col && cube.sides[5][2][0] == Right_col && cube.sides[4][0][2] == Front_col) ||
           (cube.sides[1][0][0] == Up_col && cube.sides[5][2][0] == Front_col && cube.sides[4][0][2] == Right_col)){
            turn({3, 9, 2, 5, 3, 8, 2, 4});
        }
        if ((cube.sides[2][0][2] == Front_col && cube.sides[5][0][2] == Up_col && cube.sides[3][0][0] == Right_col) ||
           (cube.sides[2][0][2] == Front_col && cube.sides[5][0][2] == Right_col && cube.sides[3][0][0] == Up_col) ||
           (cube.sides[2][0][2] == Right_col && cube.sides[5][0][2] == Up_col && cube.sides[3][0][0] == Front_col) ||
           (cube.sides[2][0][2] == Right_col && cube.sides[5][0][2] == Front_col && cube.sides[3][0][0] == Up_col) ||
           (cube.sides[2][0][2] == Up_col && cube.sides[5][0][2] == Front_col && cube.sides[3][0][0] == Right_col) ||
           (cube.sides[2][0][2] == Up_col && cube.sides[5][0][2] == Right_col && cube.sides[3][0][0] == Front_col)){
            turn({5, 3, 9, 2, 4, 3, 8, 2});
        }
        if ((cube.sides[3][0][2] == Front_col && cube.sides[5][0][0] == Up_col && cube.sides[4][0][0] == Right_col) ||
           (cube.sides[3][0][2] == Front_col && cube.sides[5][0][0] == Right_col && cube.sides[4][0][0] == Up_col) ||
           (cube.sides[3][0][2] == Right_col && cube.sides[5][0][0] == Front_col && cube.sides[4][0][0] == Up_col) ||
           (cube.sides[3][0][2] == Right_col && cube.sides[5][0][0] == Up_col && cube.sides[4][0][0] == Front_col) ||
           (cube.sides[3][0][2] == Up_col && cube.sides[5][0][0] == Right_col && cube.sides[4][0][0] == Front_col) ||
           (cube.sides[3][0][2] == Up_col && cube.sides[5][0][0] == Front_col && cube.sides[4][0][0] == Right_col)){
            turn({3, 9, 7, 8, 2, 9, 6, 8});
        }
        if ((cube.sides[4][0][2] == Right_col && cube.sides[5][2][0] == Up_col && cube.sides[1][0][0] == Back_col) ||
           (cube.sides[4][0][2] == Right_col && cube.sides[5][2][0] == Back_col && cube.sides[1][0][0] == Up_col) ||
           (cube.sides[4][0][2] == Up_col && cube.sides[5][2][0] == Right_col && cube.sides[1][0][0] == Back_col) ||
           (cube.sides[4][0][2] == Up_col && cube.sides[5][2][0] == Back_col && cube.sides[1][0][0] == Right_col) ||
           (cube.sides[4][0][2] == Back_col && cube.sides[5][2][0] == Up_col && cube.sides[1][0][0] == Right_col) ||
           (cube.sides[4][0][2] == Back_col && cube.sides[5][2][0] == Right_col && cube.sides[1][0][0] == Up_col)){
            turn({7, 5, 6, 9, 7, 4, 6, 8});
        }
        if ((cube.sides[3][0][2] == Right_col && cube.sides[5][0][0] == Up_col && cube.sides[4][0][0] == Back_col) ||
           (cube.sides[3][0][2] == Right_col && cube.sides[5][0][0] == Back_col && cube.sides[4][0][0] == Up_col) ||
           (cube.sides[3][0][2] == Up_col && cube.sides[5][0][0] == Right_col && cube.sides[4][0][0] == Back_col) ||
           (cube.sides[3][0][2] == Up_col && cube.sides[5][0][0] == Back_col && cube.sides[4][0][0] == Right_col) ||
           (cube.sides[3][0][2] == Back_col && cube.sides[5][0][0] == Up_col && cube.sides[4][0][0] == Right_col) ||
           (cube.sides[3][0][2] == Back_col && cube.sides[5][0][0] == Right_col && cube.sides[4][0][0] == Up_col)){
            turn({9, 7, 5, 6, 8, 7, 4, 6});
        }
    }

    void seventh_step () {
        if (cube.sides[2][0][0] == Up_col){
            turn({3, 4, 2, 5, 3, 4, 2, 5});
        }
        else {
            if (cube.sides[1][0][2] == Up_col){
                turn({4, 3, 5, 2, 4, 3, 5, 2});
            }
            else{
                cube.up_turn(true);
                actions.push_back(10);
            }
        }
        if (cube.sides[2][0][0] == Up_col){
            turn({3, 4, 2, 5, 3, 4, 2, 5});
        }
        else {
            if (cube.sides[1][0][2] == Up_col){
                turn({4, 3, 5, 2, 4, 3, 5, 2});
            }
        }
        cube.up_turn(true);
        actions.push_back(10);
        if (cube.sides[2][0][0] == Up_col){
            turn({3, 4, 2, 5, 3, 4, 2, 5});
        }
        else {
            if (cube.sides[1][0][2] == Up_col){
                turn({4, 3, 5, 2, 4, 3, 5, 2});
            }
        }
        cube.up_turn(true);
        actions.push_back(10);
        if (cube.sides[2][0][0] == Up_col){
            turn({3, 4, 2, 5, 3, 4, 2, 5});
        }
        else {
            if (cube.sides[1][0][2] == Up_col){
                turn({4, 3, 5, 2, 4, 3, 5, 2});
            }
        }
        cube.up_turn(true);
        actions.push_back(10);
        if (cube.sides[2][0][0] == Up_col){
            turn({3, 4, 2, 5, 3, 4, 2, 5});
        }
        else {
            if(cube.sides[1][0][2]==Up_col){
                turn({4, 3, 5, 2, 4, 3, 5, 2});
            }
        }
        int counter = 0;
        while(!cube.is_cube_solved() && counter < 5){
            cube.up_turn(true);
            actions.push_back(10);
            counter++;
        }
    }

    Cube Solving () {
        first_step();
        second_step();
        third_step();
        fourth_step();
        fifth_step();
        sixth_step();
        seventh_step();
        return this->cube;
    }
};
#endif //CUBE_H