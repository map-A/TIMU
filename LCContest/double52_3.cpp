#include "bits/stdc++.h"

using namespace std;
vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int m = box.size(),n = box[0].size();
    vector<vector<char>>ret(n,vector<char>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ret[j][m-1-i] = box[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int j=n-1,k=j-1;
        //从每个竖行的底部检查，如果当前是空位，检测上方是否有石头
        while(k>=-0&&j>=0){
            if(ret[j][i]=='.'&&ret[k][i]=='#'){
                swap(ret[k][i],ret[j][i]);
                j--;
                k--;
            }
            else if(ret[j][i]=='.'&&ret[k][i]=='.'){
                k--;
            }
            else{
                j=k;
                cout<<j;
                k--;
            }
        }
    }
    return ret;
}
int main() {
    vector<vector<char>>box ={{'#','#','#','.','#','.'}};
    auto ret = rotateTheBox(box);
    return 0;
}