#include "bits/stdc++.h"

using namespace std;
vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
    sort(input.begin(),input.end());
    return vector<int>(input.begin(),input.begin()+k);
}
vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
    if (k == 0 || k>input.size()) {
        return input;
    }
    priority_queue<int> q;
    for (int i = 0; i < k; ++i) {
        q.push(input[i]);
    }
    for (int i = k; i < input.size(); ++i) {
        if (q.top() > input[i]) {
            q.pop();
            q.push(input[i]);
        }
    }
    vector<int>ret(k,0);
    for(int i=0;i<k;i++) {
        ret[i] = q.top();
        q.pop();
    }
    return ret;

}


int partition(vector<int>& input, int l, int r) {
    int pivot = input[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; ++j) {
        if (input[j] <= pivot) {
            i = i + 1;
            swap(input[i], input[j]);
        }
    }
    swap(input[i + 1], input[r]);
    return i + 1;
}

void selected(vector<int>& input, int l, int r, int k) {
    if (l >= r) {
        return;
    }
    int pos = partition(input, l, r);
    int num = pos - l + 1;
    if (k == num) {
        return;
    } else if (k < num) {
        selected(input, l, pos - 1, k);
    } else {
        selected(input, pos + 1, r, k - num);
    }
}

vector<int>  GetLeastNumbers_Solution(vector<int>& input, int k) {
    if(k==0||k>input.size()){
        return  {};
    }
    selected(input, 0, (int)input.size() - 1, k);
    vector<int> ret;
    return vector<int>(input.begin(),input.begin()+k);
}

int main() {
    vector<int>input = {4,5,1,6,2,7,3,8};
    int k =4;
    vector<int> ret = GetLeastNumbers_Solution(input,k);
    return 0;
}