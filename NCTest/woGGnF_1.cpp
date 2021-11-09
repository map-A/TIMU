#include "bits/stdc++.h"

using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };


class Solution {
public:
    ListNode* deleteListNode(ListNode* head) {
        ListNode* p = head;
        while (p&&p->next){
            ListNode* q = p->next;
            p->next = q->next;
            p = p->next;
        }
        return head;
    }
};
int main() {

    return 0;
}