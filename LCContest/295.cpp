//
// Created by mm on 2022/7/26 0026.
//

#include "bits/stdc++.h"
#include <sstream>
using namespace std;

int rearrangeCharacters(string s, string target) {
    map<char,int>m;
    map<char,int>m1;
    for(auto &i:s){
        m[i]++;
    }
    for(auto &i:target){
        m1[i]++;
    }
    int ret = INT_MAX;
    for(auto i:m1){

        ret = min(ret,m[i.first]/i.second);
    }
    return ret;
}



long long is_price(string price){

    if(price[0]=='$'&&price.size()>1){
        for (int i = 1; i < price.size(); ++i) {
            if(isdigit(price[i])){
                continue;
            }
            else{
                return -1;
            }
        }
        return stoll(price.substr(1));
    }
    return -1;
}
string discountPrices(string sentence, int discount) {
    vector<string>v;
    int start = 0;
    for (int i = 0; i < sentence.size(); ++i) {
        if(sentence[i]==' '){
            v.push_back(sentence.substr(start,i-start));
            start = i+1;
        }
    }
    v.push_back(sentence.substr(start,sentence.size()-start));
    for (int i = 0; i < v.size(); ++i) {
        if(is_price(v[i])!=-1){
            double new_price = (1.0*(100-discount)* is_price(v[i])+0.005)/100;
            printf("%f\n",new_price);
            auto str = std::to_string(new_price);

            v[i] = "$"+ str.substr(0, str.find(".") +3);
        }
    }
    string ret = "";
    for (int i = 0; i < v.size()-1; ++i) {
        ret+=v[i];
        ret+=" ";
    }
    ret+=v.back();
    return ret;
}



int totalSteps(vector<int> &nums) {
    int ret = 0;
    stack<pair<int, int>> st;
    for (int num : nums) {
        int maxT = 0;
        while (!st.empty() && st.top().first <= num) {
            maxT = max(maxT, st.top().second);
            st.pop();
        }
        maxT = st.empty() ? 0 : maxT + 1;
        ret = max(ret, maxT);
        st.emplace(num, maxT);
    }
    return ret;
}


static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int minimumObstacles(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int dis[m][n];
    memset(dis, 0x3f, sizeof(dis));
    dis[0][0] = 0;
    deque<pair<int, int>> q;
    q.emplace_front(0, 0);
    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop_front();
        for (auto &[dx, dy]: dirs) {
            int nx = x + dx, ny = y + dy;
            if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                int g = grid[nx][ny];
                if (dis[x][y] + g < dis[nx][ny]) {
                    dis[nx][ny] = dis[x][y] + g;
                    g == 0 ? q.emplace_front(nx, ny) : q.emplace_back(nx, ny);
                }
            }
        }
    }
    return dis[m - 1][n - 1];
}



int main(void){

    string sentence = "$2$3 $10 $100 $1 200 $33 33$ $$ $99 $99999 $9999999999";
    int discount = 5;
    cout<<discountPrices(sentence,discount);
}