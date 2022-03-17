#include "bits/stdc++.h"

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };
bool isPalindrome(ListNode* head) {
    vector<int>tmp;
    ListNode* p = head;
    while (p){
        tmp.push_back(p->val);
        p = p->next;
    }
    int flag = 0;
    int left = 0,right = tmp.size()-1;
    while (left<right){
        if(flag>1) return false;
        if(tmp[left]==tmp[right]){
            left++;
            right--;
        }
        else if(tmp[left+1]==tmp[right]){
            //表示可以删除left
            flag++;
            left+=2;
            right-=1;
        }
        else if(tmp[left]==tmp[right-1]){
            flag++;
            right-=2;
            left++;
        }
        else{
            return false;
        }
    }
    if(flag>1) return false;
    return true;
}
int main() {

    return 0;
}