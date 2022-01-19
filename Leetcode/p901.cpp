#include "bits/stdc++.h"

using namespace std;
class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner() {

    }

    int next(int price) {
        if(s.empty()||price<s.top().first){
            s.push({price,1});
            return 1;
        }
        int ret = 1;
        while (!s.empty()&&s.top().first<=price){
            //如果前一天的价格大于今天的价格，那么今天再往前的价格也都没意义了
            ret+=s.top().second;
            s.pop();
        }
        s.push({price,ret});
        return ret;
    }
};
int main() {

    return 0;
}