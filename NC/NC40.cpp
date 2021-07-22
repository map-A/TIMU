#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    if(!head) return NULL;
    ListNode* p = head->next;
    ListNode*temp;
    ListNode*q = head;
    while (p){
        temp = p->next;
        p->next = head;
        q->next = temp;
        head = p;
        p = temp;
    }
    return head;
}


ListNode *addTwoNumbersCore(ListNode *head1, ListNode *head2, int carry) {
    if (!head1 && !head2 && carry == 0) {
        // 当输入的节点均为null且无需处理进位时，结束
        return nullptr;
    }
    int val = carry + (head1 ? head1->val : 0) + (head2 ? head2->val : 0); // 计算当前的和
    auto ret = new ListNode(val % 10);
    ret->next = addTwoNumbersCore((head1 ? head1->next : nullptr), (head2 ? head2->next : nullptr), val / 10);
    return ret;
}

ListNode *addTwoNumbers(ListNode *head1, ListNode *head2) {
    return addTwoNumbersCore(head1, head2, 0);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}