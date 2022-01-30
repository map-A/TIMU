#include "bits/stdc++.h"

using namespace std;
map<vector<int>,int>m;
vector<int>pr;
vector<vector<int>>new_special;
int dfs(vector<int>& needs){
    int n = pr.size();
    if(!m.count(needs)){
        int min_price = 0;
        //不购买任何礼包
        for (int i = 0; i < n; ++i) {
            min_price+=needs[i]* pr[i];
        }
        //如果要购买礼包
        m[needs] = min_price;
        for(auto &i:new_special){
            int special_price = i.back();
            //检查礼包是否可以购买
            int j=0;
            for (;j< needs.size(); ++j) {
                if(i[j]>needs[j]) break;//表示不能购买
            }
            if(j==needs.size()){
                //表示可以购买
                vector<int>new_needs;
                for (int k = 0; k < needs.size(); ++k) {
                    new_needs.push_back(needs[k]-i[k]);
                }
                min_price = min(min_price, dfs(new_needs)+special_price);
            }
            m[needs] = min_price;
        }

    }
    return m[needs];

}
int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    int n = price.size();
    pr = price;
    for (auto &i:special) {
        int sum=0;
        for (int j = 0; j < i.size()-1; ++j) {
            sum+=i[j]*price[j];
        }
        if(sum>=i.back()){
            new_special.push_back(i);
        }
    }
    return dfs(needs);
}
int main() {
    vector<int>price = {1,5};
    vector<vector<int>>special = {{0,1,8},{1,0,9}};
    vector<int> needs = {7,10};
    auto ret = shoppingOffers(price,special,needs);
    return 0;
}