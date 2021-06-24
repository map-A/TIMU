#include "bits/stdc++.h"

using namespace std;
bool check(vector<vector<char>>&board,char c){
    int N = board.size();
    for(int i=0;i<N;i++){
        int j=0;
        for(j;j<N;j++){
            if(board[i][j]==c) {
                continue;
            }
            else{
                break;
            }
        }
        if(j==N) return true;
    }

    for(int i=0;i<N;i++){
        int j=0;
        for(j;j<N;j++){
            if(board[j][i]==c) {
                continue;
            }
            else{
                break;
            }
        }
        if(j==N) return true;
    }
    int i=0;
    for(i;i<N;i++){
        if(board[i][i]==c) {
            continue;
        }
        else{
            break;
        }
    }
    if(i==N) return true;
    for(i=0;i<N;i++){
        if(board[i][N-1-i]==c) {
            continue;
        }
        else{
            break;
        }
    }
    if(i==N) return true;
    return false;


}
string tictactoe(vector<string>& board) {
    int N = board.size();
    vector<vector<char>>tmp(N,vector<char>(N,' '));
    int count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]!=' ')count++;
            tmp[i][j]=board[i][j];
        }
    }
    if(check(tmp,'O')){
        return "O";
    }
    if(check(tmp,'X')){
        return "X";
    }
    if(count==N*N) return "Draw";
    else return "Pending";


}
int main() {
    vector<string>board =  {" O    X"," O     ","     O ","XXXXXXX","  O    "," O   O ","O  X OO"};
    auto ret = tictactoe(board);
    return 0;
}