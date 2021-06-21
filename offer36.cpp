#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    Node *pre, *head;
    void dfs(Node* cur) {
        if(cur == nullptr) return;
        dfs(cur->left);
        if(pre != nullptr) pre->right = cur;
        else head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}