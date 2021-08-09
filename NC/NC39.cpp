#include "bits/stdc++.h"

using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n) {
    for (int i = 0; i < n; i++)
        if (board[row][i] == 'Q') return false;

    for (int i = 0; i < n; i++)
        if (board[i][col] == 'Q') return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 'Q') return false;

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    for (int i = row, j = col; i < n && j < n; i++, j++)
        if (board[i][j] == 'Q') return false;
    return true;

}

int cnt = 0;
bool NPQ(vector<string> &board, int row, int n) {
    if (row == n) {
        cnt++;
        return true;
    }
    bool ret = false;;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, row, i, n)) {
            board[row][i] = 'Q';//当前试探是安全的，可以添加
            ret = NPQ(board, row + 1, n) || ret;
            board[row][i] = '.'; // 不安全，只能返回原有状态
        }
    }
    return ret;
}



int Nqueen(int n) {
    string s(n, '.');
    vector<string> board(n, s);
    NPQ(board, 0, n);
    return cnt;
}

int main() {

    return 0;
}