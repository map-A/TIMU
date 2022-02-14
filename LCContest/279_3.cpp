#include "bits/stdc++.h"

using namespace std;
class Bitset {
public:
    vector<int>v1;
    vector<int>v2;
    int flag = 0;
    int count_v1;
    int count_v2;
    Bitset(int size) {
        v1.resize(size);
        v2.resize(size,1);
        count_v1 = 0;
        count_v2 = size;

    }

    void fix(int idx) {
        if(flag%2==0){
            //此时选择的是v1
            if(v1[idx]!=1){
                v1[idx]=1;
                count_v1++;
            }
            if(v2[idx]!=0){
                v2[idx] = 0;
                count_v2--;
            }
        }
        else{
            if(v2[idx]!=1){
                v2[idx] = 1;
                count_v2++;
            }
            if(v1[idx]!=0){
                v1[idx] = 0;
                count_v1--;
            }
        }


    }

    void unfix(int idx) {
        if(flag%2==0){
            if(v1[idx]!=0){
                v1[idx] = 0;
                count_v1--;
            }
            if(v2[idx]!=1){
                v2[idx] = 1;
                count_v2++;
            }
        }
        else{
            if(v2[idx]!=0){
                v2[idx] = 0;
                count_v2--;
            }
            if(v1[idx]!=1){
                v1[idx] = 1;
                count_v1++;
            }
        }
    }

    void flip() {
        flag++;
    }

    bool all() {
        if(flag%2==0){
            return count_v1==v1.size();
        }
        else{
            return count_v2==v2.size();
        }

    }

    bool one() {
        if(flag%2==0){
            return count_v1>0;
        }
        else{
            return count_v2>0;
        }

    }

    int count() {
        if(flag%2==0){
            return count_v1;
        }
        else{
            return count_v2;
        }
    }

    string toString() {
        string ret = "";
        if(flag%2==0){
            for (int i = 0; i < v1.size(); ++i) {
                ret+=('0'+v1[i]);
            }
            return ret;
        }
        else{
            for (int i = 0; i < v1.size(); ++i) {
                ret+=('0'+v2[i]);
            }
            return ret;
        }
    }
};
int main() {

    return 0;
}