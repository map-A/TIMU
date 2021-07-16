#include "bits/stdc++.h"

using namespace std;

ListNode *reverseList(ListNode *head) {
    if (!head) return NULL;
    ListNode *p = head->next;
    ListNode *temp;
    ListNode *q = head;
    while (p) {
        temp = p->next;
        p->next = head;
        q->next = temp;
        head = p;
        p = temp;
    }
    return head;
}


ListNode *addInList(ListNode *head1, ListNode *head2) {
    ListNode *head = new ListNode(-1);
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    ListNode *l1 = head1;
    ListNode *l2 = head2;
    ListNode *p = head;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        int newsum = sum % 10;
        ListNode *tem = new ListNode(newsum);
        p->next = tem;
        p = p->next;
    }
    ListNode *ret = reverseList(head->next);
    return ret;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}