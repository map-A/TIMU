#include "bits/stdc++.h"

using namespace std;
//TODO: 蓄水池抽样算法
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *tmp;
    Solution(ListNode *head) {
        this->tmp = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *point = tmp;
        int ret = point->val;
        point = point->next;
        int index = 1;
        while(point){
            index++;
            int randomNum = rand()%index;
            if(randomNum==0)
                ret = point->val;
            point = point->next;
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}