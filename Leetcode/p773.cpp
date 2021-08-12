#include "bits/stdc++.h"

using namespace std;

vector<vector<int>>neigbors = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
int slidingPuzzle(vector<vector<int>>& board) {

    auto get = [&](string &status)->vector<string>{
        //lambda表达式，get用以调用 ->表示返回的 ，()里表示参数{}里为匿名参数的函数体[]里面表示捕获块
//        [] 不捕获任何变量。
//        [&] 捕获外部作用域中所有变量，并作为引用在函数体中使用（按引用捕获）。
//        [=] 捕获外部作用域中所有变量，并作为副本在函数体中使用（按值捕获）。
//        [=，&foo] 按值捕获外部作用域中所有变量，并按引用捕获 foo 变量。
//        [bar] 按值捕获 bar 变量，同时不捕获其他变量。
//        [this] 捕获当前类中的 this 指针，让 lambda 表达式拥有和当前类成员函数同样的访问权限。如果已经使用了 & 或者 =，就默认添加此选项。捕获 this 的目的是可以在 lamda 中使用当前类的成员函数和成员变量。
        vector<string>ret;
        int x = status.find('0');
        for(int y:neigbors[x]){
            swap(status[x],status[y]);
            ret.push_back(status);
            swap(status[x],status[y]);
        }
        return ret;
    };
    string initial;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            initial+=board[i][j];
        }
    }
    queue<pair<string,int>>q;//string 表示状态，int表示到达这个statu花了几步
    q.push({initial,0});
    unordered_set<string>seen = {initial};
    while (!q.empty()){
        auto [status,step] = q.front();
        q.pop();
        for(auto &&next_status:get(status)){
            if(next_status=="123450"){
                return step+1;
            }
            if(!seen.count(next_status)){
                q.push({next_status,step+1});
                seen.insert(next_status);
            }
        }
    }
    return -1;
}
int main() {

    return 0;
}