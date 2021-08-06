#include "bits/stdc++.h"

using namespace std;
vector<int> decode(vector<int>& encoded, int first) {
    vector<int>ret ={first};
    for(int i=0;i<encoded.size();i++){
        ret.push_back(encoded[i]^ret.back());
    }
    return ret;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}