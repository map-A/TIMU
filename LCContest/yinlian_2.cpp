#include "bits/stdc++.h"

using namespace std;
class DiscountSystem {
public:

    vector<vector<int>>activity;
    vector<vector<int>>usrLimits;
    DiscountSystem() {
        activity.resize(1001,vector<int>(3,0));
        usrLimits.resize(1001,vector<int>(1001,0));
    }

    void addActivity(int actId, int priceLimit, int discount, int number, int userLimit) {
        activity[actId] = {priceLimit,discount,number};
        for (int i = 0; i < usrLimits.size(); ++i) {
            usrLimits[actId][i] = userLimit;
        }

    }

    void removeActivity(int actId) {
        activity[actId].assign(3,0);
        usrLimits[actId].assign(1001,0);
    }

    int consume(int userId, int cost) {
        // 找到一个discount
        int discount_index=-1;
        for (int i=0; i < activity.size(); ++i) {
            if(activity[i][0]<=cost&&activity[i][1]>0&&activity[i][2]>0&&usrLimits[i][userId]>0){
                //cout<<userId<<' '<<i<<endl;
                discount_index=i;
                break;
            }
        }
        if(discount_index==-1){
            return cost;
        }

        for (int j = discount_index+1; j < activity.size(); ++j) {
            if(activity[j][0]<=cost&&activity[j][1]>activity[discount_index][1]&&activity[j][2]>0&&usrLimits[j][userId]>0){
                discount_index  = j;
            }
        }
        if(discount_index!=-1){
            activity[discount_index][2]--;
            usrLimits[discount_index][userId]--;
            return cost-activity[discount_index][1];
        }

        return cost;
    }
};

int main() {

    return 0;
}