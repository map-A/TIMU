#include "bits/stdc++.h"

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int pairSum(ListNode* head) {
    int ret = 0;
    vector<int>t;
    ListNode* p = head;
    while (p){
        t.push_back(p->val);
        p =p->next;
    }
    for (int i = 0; i < t.size()/2; ++i) {
        ret=max(ret,t[i]+t[t.size()-i-1]);
    }
    return ret;
}

int main() {

    return 0;
}