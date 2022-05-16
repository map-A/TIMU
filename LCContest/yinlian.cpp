#include "bits/stdc++.h"

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
bool isPalindrome(ListNode* head) {
    vector<int>tmp;
    ListNode* p = head;
    while (p){
        tmp.push_back(p->val);
        p = p->next;
    }
    int flag = 0;
    int left = 0,right = tmp.size()-1;
    while (left<right){
        if(flag>1) return false;
        if(tmp[left]==tmp[right]){
            left++;
            right--;
        }
        else if(tmp[left+1]==tmp[right]){
            //表示可以删除left
            flag++;
            left+=2;
            right-=1;
        }
        else if(tmp[left]==tmp[right-1]){
            flag++;
            right-=2;
            left++;
        }
        else{
            return false;
        }
    }
    if(flag>1) return false;
    return true;
}


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

typedef long long ll;
int maxInvestment(vector<int>& a, int limits) {
    a.push_back(0);
    sort(a.begin(),a.end(),greater<int>());

    int n=a.size(),ans=0,mod=1e9+7;
    for(int i=0;i+1<n;++i){
        if(a[i]==a[i+1])continue;
        ll x=1ll*(a[i]-a[i+1])*(i+1);
        if(x<=limits){
            ans=(ans+1ll*(a[i+1]+1+a[i])*(a[i]-a[i+1])/2%mod*(i+1)%mod)%mod;
            limits-=x;
        }
        else{
            int lb=a[i]-limits/(i+1),ex=limits%(i+1);
            ans=((ans+(1ll*(lb+1+a[i])*(a[i]-lb)/2)%mod*(i+1)%mod)%mod+1ll*ex*lb%mod)%mod;
            break;
        }
    }
    return ans;
}




int main() {

    return 0;
}