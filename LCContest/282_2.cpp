#include "bits/stdc++.h"

using namespace std;

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
int main() {

    return 0;
}