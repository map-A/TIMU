#include "bits/stdc++.h"

using namespace std;
int maximumDifference(vector<int>& nums) {
    int ret = -1;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            ret = max(nums[j]-nums[i],ret);
        }
    }
    return ret==0?-1:ret;
}

long long gridGame(vector<vector<int>>& grid) {
    int n = grid[0].size();
    vector<vector<long long>>pre_sum(2,vector<long long>(n+2,0));

    for(int i=0;i<n;i++){
        pre_sum[1][i+1] = pre_sum[1][i]+grid[1][i];
        pre_sum[0][n-i] =pre_sum[0][n-i+1]+grid[0][n-i-1];
    }
    long long max_2 = LONG_MAX;

    for(int i=1;i<=n;i++){ //找到机器人一的最大值
        max_2 = min(max(pre_sum[0][i+1],pre_sum[1][i-1]),max_2);
    }
    return max_2;

}

bool check(vector<vector<char>> &board, int i, int j, string word) {
    //i,j 可以当做起点
    //是否可以向右延展，保证在ij的左边没有空格和字符,为#
    if (j == 0 || (j - 1 >= 0 && board[i][j - 1] == '#')) {
        int len = 0;
        int k = j;
        for (; k < board[i].size(); k++) {
            if (board[i][k] == ' ' || (len<word.size()&&board[i][k] == word[len])) {
                len++;
            } else {
                break;
            }
        }
        if (len == word.size() && (k >= board[i].size() || board[i][k] == '#')) return true;
    }
    //是否可以向左延展，保证在ij的右边没有空格和字符,为#
    if (j + 1 == board[i].size() || (j + 1 < board[i].size() && board[i][j + 1] == '#')) {
        int len = 0;
        int k = j;
        for (; k >= 0; k--) {
            if (board[i][k] == ' ' ||(len<word.size()&& board[i][k] == word[len])) {
                len++;
            } else {
                break;
            }
        }
        if (len == word.size() && (k < 0 || board[i][k] == '#')) return true;

    }

    //是否可以向下延展，保证在ij的上边没有空格和字符,为#
    if (i == 0 || (i - 1 >= 0 && board[i - 1][j] == '#')) {
        int len = 0;
        int k = i;
        for (; k < board.size(); k++) {
            if (board[k][j] == ' ' || (len<word.size()&&board[k][j] == word[len])) {
                len++;
            } else {
                break;
            }
        }
        if (len == word.size() && (k >= board.size() || board[k][j] == '#')) return true;
    }
    //是否可以向上延展，保证在ij的下边没有空格和字符,为#
    if (i + 1 == board.size() || (i + 1 < board.size() && board[i + 1][j] == '#')) {
        int len = 0;
        int k = i;
        for (; k >= 0; k--) {
            if (board[k][j] == ' ' || (len<word.size()&&board[k][j] == word[len])) {
                len++;
            } else {
                break;
            }
        }
        if (len == word.size() && (k < 0 || board[k][j] == '#')) return true;
    }
    return false;
}

bool placeWordInCrossword(vector<vector<char>> &board, string word) {
    int n = word.size();
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            //check
            if (board[i][j] == ' ' || board[i][j] == word[0]) {
                if (check(board, i, j, word)) return true;
            }
        }
    }
    return false;
}

int main() {

    return 0;
}