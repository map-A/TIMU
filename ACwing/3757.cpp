#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

/*
 * L=(a1,a2,…,an−2,an−1,an)
 * L′=(a1,an,a2,an−1,a3,an−2…)
 * */

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
void solve() {

}

void reorderList(ListNode *head) {
    if (head == nullptr) {
        return;
    }
    vector<ListNode *> vec;
    ListNode *node = head;
    while (node != nullptr) {
        vec.emplace_back(node);
        node = node->next;
    }
    int i = 0, j = vec.size() - 1;
    while (i < j) {
        vec[i]->next = vec[j];
        i++;
        if (i == j) {
            break;
        }
        vec[j]->next = vec[i];
        j--;
    }
    vec[i]->next = nullptr;
}
int main() {
    return 0;
}
