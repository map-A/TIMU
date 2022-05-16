#include "bits/stdc++.h"

using namespace std;
int countEven(int num) {
    int count = 0;
    for(int k = 2; k <= num; k++){
        int sum = 0, i = k;
        while(i > 0){
            sum += i % 10;
            i /= 10;
        }
        if((sum & 1) == 0){
            count++;
        }
    }
    return count;
}



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeNodes(ListNode* head) {
    ListNode *ret = new ListNode();
    ListNode *p = ret;
    ListNode *q = head;
    int sum = 0;
    while (q) {
        if (q->val != 0) {
            sum += q->val;
        } else {
            p->next = new ListNode(sum);
            sum = 0;
            p = p->next;
        }
        q = q->next;
    }
    return ret->next->next;
}

string repeatLimitedString(string s, int repeatLimit) {
    vector<int> cnt(26);
    for (char c: s){
        cnt[c - 'a'] += 1;
    }
    string t;
    int L = -1;
    while (true) {
        int done = 1;
        int mx = -1;
        for (int i = 25; i >= 0; i -= 1) {
            if (cnt[i] and mx == -1) mx = i;
            if (cnt[i] and i != L) {
                L = i;
                done = 0;
                break;
            }
        }
        if (done) break;
        int x = min(cnt[L], L == mx ? repeatLimit : 1);
        cnt[L] -= x;
        for (int j = 0; j < x; j += 1) t += 'a' + L;
    }
    return t;
}



int main() {

    return 0;
}