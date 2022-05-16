#include "bits/stdc++.h"

using namespace std;
long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    int t2 = total/cost2;
    long long ret =0;
    for (int i = 0; i <=t2; ++i) {
        ret+=(total-i*cost2)/cost1+1;
    }
    return ret;
}


class ATM {
public:
    vector<long long>m;
    ATM() {
        m.resize(5,0);
    }

    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<banknotesCount.size();i++){
            m[i]+=banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        //尝试取
        int five_h = m[4]>=amount/500?amount/500:m[4];

        int two_h = m[3]>=(amount-five_h*500)/200?(amount-five_h*500)/200:m[3];

        int one_h = m[2]>=(amount-five_h*500-two_h*200)/100?(amount-five_h*500-two_h*200)/100:m[2];
        int five_t = m[1]>=(amount-five_h*500-two_h*200-one_h*100)/50?(amount-five_h*500-two_h*200-one_h*100)/50:m[1];
        // cout<<m[2]<<one_h<<endl;
        int two_t = m[0]>=(amount-five_h*500-two_h*200-one_h*100-five_t*50)/50?(amount-five_h*500-two_h*200-one_h*100-five_t*50)/20:m[0];

        if(amount==five_h*500+two_h*200+one_h*100+five_t*50+two_t*20){
            m[4]-=five_h;
            m[3]-=two_h;
            m[2]-=one_h;
            m[1]-=five_t;
            m[0]-=two_t;
            return {two_t,five_t,one_h,two_h,five_h};
        }
        return {-1};

    }
};



int main() {

    return 0;
}