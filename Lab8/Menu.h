#ifndef MENU_H
#define MENU_H
#include <fstream>
#include <string>
#include <random>

using namespace std;

class User {
public:
    Cube cube;
    User() {
        cube = Cube();
        Menu();
    }
    void Menu () {
        while (true) {
            cout << "1. Получить кубик Рубика из файла" << '\n';
            cout << "2. Получить текущее состояние кубика Рубика" << '\n';
            cout << "3. Повернуть кубик Рубика" << '\n';
            cout << "4. Сгенерировать случайный кубик Рубика" << '\n';
            cout << "5. Найти решение для текущего кубика Рубика" << '\n';
            cout << "0. Выход из меню" << '\n';
            int com;
            cout << "Введите команду: ";
            cin >> com;
            cout << '\n';
            if (com == 1) {
                Get_Cube_From_file ();
            }
            else if (com == 2) {
                Get_Current_Cube ();
            }
            else if (com == 3) {
                Turn_Cube ();
            }
            else if (com == 4) {
                Get_Random_Cube ();
            }
            else if (com == 5) {
                Get_Solve ();
            }
            else if (com == 0) {
                break;
            }
            else cout << "Неверная команда! Попробуйте еще раз" << '\n';
        }
    }

    void Get_Cube_From_file () {
        string name;
        cout << "Введите название файла: ";
        cin >> name;
        cout << '\n';
        ifstream fcube (name);
        Cube cube_;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    int col;
                    fcube >> col;
                    cube_.sides[i][j][k] = col;
                }
            }
        }
        cube.sides = cube_.sides;
    }

    void Get_Current_Cube () {
        vector<char> cols = {'O', 'W', 'G', 'Y', 'R', 'B'};
        for (int i = 0; i < 3; i++) {
            cout << "      | ";
            for (int j = 0; j < 3; j++) {
                cout << cols[cube.sides[0][i][j]] << ' ';
            }
            cout << "|\n";
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << cols[cube.sides[1][i][j]] << ' ';
            }
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << cols[cube.sides[2][i][j]] << ' ';
            }
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << cols[cube.sides[3][i][j]] << ' ';
            }
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << cols[cube.sides[4][i][j]] << ' ';
            }
            cout << '\n';
        }
        for (int i = 0; i < 3; i++) {
            cout << "      | ";
            for (int j = 0; j < 3; j++) {
                cout << cols[cube.sides[5][i][j]] << ' ';
            }
            cout << "|\n";
        }
        cout << '\n';
    }

    void Turn_Cube () {
        while (true) {
            cout << "Список поворотов:" << '\n';
            cout << "Нижнюю грань по часовой - D" << '\n';
            cout << "Нижнюю грань против часовой - D'" << '\n';
            cout << "Переднюю грань по часовой - F" << '\n';
            cout << "Переднюю грань против часовой - F'" << '\n';
            cout << "Правую грань по часовой - R" << '\n';
            cout << "Правую грань против часовой - R'" << '\n';
            cout << "Заднюю грань по часовой - B" << '\n';
            cout << "Заднюю грань против часовой - B'" << '\n';
            cout << "Левую грань по часовой - L" << '\n';
            cout << "Левую грань против часовой - L'" << '\n';
            cout << "Верхнюю грань по часовой - U" << '\n';
            cout << "Верхнюю грань против часовой - U'" << '\n';
            cout << "Введите необходимый поворот (для выхода - введите 0): ";
            string com;
            cin >> com;
            cout << '\n' << '\n';
            if (com == "D") {
                cube.down_turn(true);
            }
            else if (com == "D'") {
                cube.down_turn(false);
            }
            else if (com == "F") {
                cube.front_turn(true);
            }
            else if (com == "F'") {
                cube.front_turn(false);
            }
            else if (com == "R") {
                cube.right_turn(true);
            }
            else if (com == "R'") {
                cube.right_turn(false);
            }
            else if (com == "B") {
                cube.back_turn(true);
            }
            else if (com == "B'") {
                cube.back_turn(false);
            }
            else if (com == "L") {
                cube.left_turn(true);
            }
            else if (com == "L'") {
                cube.left_turn(false);
            }
            else if (com == "U") {
                cube.up_turn(true);
            }
            else if (com == "U'") {
                cube.up_turn(false);
            }
            else if (com == "0") {
                break;
            }
            else cout << "Неверная команда! Попробуйте еще раз" << '\n';
        }
    }

    void Get_Random_Cube () {
        cube = Cube();
        random_device rd;
        mt19937 gen(rd());
        for (int i = 0; i < 54; i++) {
            int turn = (int) (gen() % 12);
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
        }
    }

    void Get_Solve () {
        cout << "Список поворотов:" << '\n';
        cout << "Нижнюю грань по часовой - D" << '\n';
        cout << "Нижнюю грань против часовой - D'" << '\n';
        cout << "Переднюю грань по часовой - F" << '\n';
        cout << "Переднюю грань против часовой - F'" << '\n';
        cout << "Правую грань по часовой - R" << '\n';
        cout << "Правую грань против часовой - R'" << '\n';
        cout << "Заднюю грань по часовой - B" << '\n';
        cout << "Заднюю грань против часовой - B'" << '\n';
        cout << "Левую грань по часовой - L" << '\n';
        cout << "Левую грань против часовой - L'" << '\n';
        cout << "Верхнюю грань по часовой - U" << '\n';
        cout << "Верхнюю грань против часовой - U'" << '\n';
        cout << '\n';
        algorithm au = algorithm(cube);
        cube = au.Solving();
        if (cube.is_cube_solved()) {
            cout << "Текущие повороты:" << '\n';
            vector<int> oper = au.actions;
            for (int i = 0; i < oper.size(); i++) {
                if (oper[i] == 0) {
                    cout << "D ";
                }
                if (oper[i] == 1) {
                    cout << "D' ";
                }
                if (oper[i] == 2) {
                    cout << "F ";
                }
                if (oper[i] == 3) {
                    cout << "F' ";
                }
                if (oper[i] == 4) {
                    cout << "R ";
                }
                if (oper[i] == 5) {
                    cout << "R' ";
                }
                if (oper[i] == 6) {
                    cout << "B ";
                }
                if (oper[i] == 7) {
                    cout << "B' ";
                }
                if (oper[i] == 8) {
                    cout << "L ";
                }
                if (oper[i] == 9) {
                    cout << "L' ";
                }
                if (oper[i] == 10) {
                    cout << "U ";
                }
                if (oper[i] == 11) {
                    cout << "U' ";
                }
                if (i % 20 == 0 && i != 0) cout << '\n';
            }
        }
        else cout << "Не удалось собрать! Кубик не является корректным!";
        cout << '\n' << '\n';
    }
};
#endif //MENU_H