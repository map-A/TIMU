#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteMiddle(ListNode *head) {
    if (head->next == nullptr) {
        return head->next;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *p = slow;
    while (fast && fast->next) {
        //cout<<fast->val;
        fast = fast->next->next;
        p = slow;
        slow = slow->next;
    }
    if (fast && fast->next) {
        p = slow->next;
        slow->next = slow->next->next;
        //free(p);
    } else {
        p->next = slow->next;
        //free(slow);
    }
    return head;
}

int main() {

    return 0;
}