#include "bits/stdc++.h"

using namespace std;

bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color) {
    //横方向，左边

    vector<vector<int>> directs = {{-1, 0},
                                   {1,  0},
                                   {0,  -1},
                                   {0,  1},
                                   {-1, -1},
                                   {1,  -1},
                                   {-1, 1},
                                   {1,  1}};

    //左，右，上，下，左上，右上，左下，右下
    for (auto direct :directs) {
        int x = rMove, y = cMove;
        int flag = false;
        while (x + direct[1] >= 0 && x + direct[1] < 8 && y + direct[0] >= 0 && y + direct[0] < 8) {
            x = x + direct[1];
            y = y + direct[0];
            if (board[x][y] != color && board[x][y] != '.') {
                flag = true;
            } else if (board[x][y] == color && flag) {
                return true;
            } else {
                break;
            }
        }
    }
    return false;
}


int main() {
    vector<vector<char>> board = {{'.', '.', '.', 'B', '.', '.', '.', '.'},
                                  {'.', '.', '.', 'W', '.', '.', '.', '.'},
                                  {'.', '.', '.', 'W', '.', '.', '.', '.'},
                                  {'.', '.', '.', 'W', '.', '.', '.', '.'},
                                  {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
                                  {'.', '.', '.', 'B', '.', '.', '.', '.'},
                                  {'.', '.', '.', 'B', '.', '.', '.', '.'},
                                  {'.', '.', '.', 'W', '.', '.', '.', '.'}};
    int rMove = 4, cMove = 3;
    char color = 'B';
    bool ret = checkMove(board, rMove, cMove, color);
    return 0;
}