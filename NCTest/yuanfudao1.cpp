#include "bits/stdc++.h"

using namespace std;
typedef long long LL;

void solve() {
    string boxes;
    cin >> boxes;
    stack<string> s;
    for (int i = 0; i < boxes.size(); i++) {
        if (s.empty()) {
            string c(1, boxes[i]);
            s.push(c);
        } else if (boxes[i] == '[') {
            string c(1, boxes[i]);
            s.push(c);
        } else if (boxes[i] == ']') {
            int tmp = 0;
            while (!s.empty()) {
                string index = s.top();
                s.pop();
                if (index != "[") {
                    tmp += stoi(index);

                } else {
                    break;
                }
            }
            if (i + 1 < boxes.size() && boxes[i + 1] >= '2' && boxes[i + 1] <= '9') {
                s.push(to_string((tmp + 1) * (boxes[i + 1] - '0')));
            } else {
                s.push(to_string((tmp + 1)));
            }

        }
    }
    int ret = 0;
    while (!s.empty()) {
        ret += stoi(s.top());
        s.pop();
    }
    cout << ret;
}


int main() {

    set<int>s = {1,2,3,4};
    for(auto i:s){
        cout<<i;
    }
    
    //solve();
    return 0;
}
