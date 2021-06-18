//
// Created by mm on 2021/6/15 0015.
//
#include "bits/stdc++.h"

using namespace std;

bool isValidSudoku(vector<vector<char>> &board) {
    vector<int> vis(9, 0);
    for (int i = 0; i < 9; ++i) {
        std::fill(vis.begin(), vis.end(), 0);
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                if (vis[board[i][j] - '0' - 1] == 0) {
                    vis[board[i][j] - '0' - 1] = 1;
                } else {
                    return false;
                }
            }
        }
    }
    for (int j = 0; j < 9; ++j) {
        std::fill(vis.begin(), vis.end(), 0);
        for (int i = 0; i < 9; ++i) {
            if (board[i][j] != '.') {
                if (vis[board[i][j] - '0' - 1] == 0) {
                    vis[board[i][j] - '0' - 1] = 1;
                } else {
                    return false;
                }
            }
        }
    }
    //判断3*3的小格子
    for(int m=0;m<9;m+=3){
        for(int k=0;k<9;k+=3){
            fill(vis.begin(),vis.end(),0);
            for(int i=k;i<3+k;++i){
                for(int j=m;j<3+m;++j){
                    if (board[i][j] != '.') {
                        if (vis[board[i][j] - '0' - 1] == 0) {
                            vis[board[i][j] - '0' - 1] = 1;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;

}

int main() {
    vector<vector<char>>board = {
            {'.','.','.','.','5','.','.','1','.'},
            {'.','4','.','3','.','.','.','.','.'},
            {'.','.','.','.','.','3','.','.','1'},
            {'8','.','.','.','.','.','.','2','.'},
            {'.','.','2','.','7','.','.','.','.'},
            {'.','1','5','.','.','.','.','.','.'},
            {'.','.','.','.','.','2','.','.','.'},
            {'.','2','.','9','.','.','.','.','.'},
            {'.','.','4','.','.','.','.','.','.'}};
    cout<<isValidSudoku(board);
    return 0;
}
