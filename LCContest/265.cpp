#include "bits/stdc++.h"

using namespace std;
int smallestEqual(vector<int>& nums) {
    for(int i=0;i<nums.size();i++){
        if(i%10==nums[i]) return i;
    }
    return -1;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int>tmp;
    ListNode* p = head;
    while (p){
        tmp.push_back(p->val);
        p = p->next;
    }
    vector<int>pos;
    for(int i=1;i<tmp.size()-1;i++){
        if(tmp[i]>tmp[i-1]&&tmp[i]>tmp[i+1]){
            pos.push_back(i);
        }
        if(tmp[i]<tmp[i-1]&&tmp[i]<tmp[i+1]){
            pos.push_back(i);
        }
    }
    if(pos.size()<2) return {-1,-1};

    int max_ele = pos.back()-*pos.begin();
    int min_ele = INT_MAX;
    for(int i=0;i<pos.size()-1;i++){
        min_ele = min(min_ele,pos[i+1]-pos[i]);
    }
    return {min_ele,max_ele};
}



int main() {

    return 0;
}