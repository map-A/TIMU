//
// Created by mm on 2021/6/15 0015.
//
#include "bits/stdc++.h"
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        //TODO: to finish
    }
};
int main(){
    auto sol = new Solution;
    Node root = Node(100,NULL,NULL);
    cout<<sol->treeToDoublyList(root);
    delete sol;
    return 0;
}
