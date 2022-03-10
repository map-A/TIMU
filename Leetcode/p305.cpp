#include "bits/stdc++.h"

using namespace std;
bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    //TODO:
    if(targetCapacity>jug1Capacity+jug2Capacity) return false;
    return false;
}
struct Node{
    int val;
    Node* next;
};
Node* help(Node* head,int n){
    if(!head) return head;
    Node* node = help(head->next,n);
    
}

int main() {
    int t = 1<<3;
    cout<<t;
    return 0;
}