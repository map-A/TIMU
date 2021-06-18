#include "bits/stdc++.h"

using namespace std;
  struct ListNode {
          int val;
          ListNode  *next;
          ListNode() : val(0), next(nullptr) {}
          ListNode(int x) : val(x), next(nullptr) {}
          ListNode(int x, ListNode  *next) : val(x), next(next) {}
      };
class Solution {
public:
    ListNode* mergeInBetween(ListNode  *list1, int a, int b, ListNode  *list2) {
        ListNode* p = list1;
        int len_a = 0;
        while (p!=NULL){
            if(len_a<a-1) len_a++;
            else break;
            p = p->next;
        }
        ListNode* q = list1;
        int  len_b= 0;
        while (q!=NULL){
            if(len_b<=b) len_b++;
            else break;
            q = q->next;
        }
        p->next = list2;
        ListNode* m = list2;
        while(m&&m->next!=NULL){
            m = m->next;
        }
        m->next = q;
        return list1;
    }
};
int main() {
    Solution sol = *new Solution();
    return 0;
}