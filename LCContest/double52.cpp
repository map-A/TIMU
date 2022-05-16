#include "bits/stdc++.h"

using namespace std;
string sortSentence(string s) {
    vector<pair<int, string>> q;
    for (int i = 0; i < s.size(); i ++ ) {
        int j = i;
        string word;
        while (j < s.size() && s[j] != ' ') word += s[j ++ ];
        i = j;
        q.push_back({word.back() - '0', word.substr(0, word.size() - 1)});
    }
    sort(q.begin(), q.end());
    string res;
    for (auto& p: q) res += p.second + ' ';
    res.pop_back();
    return res;
}


vector<int> memLeak(int memory1, int memory2) {
    int crashTime = 1;
    while(crashTime){
        bool flag = true;
        if(memory1>=memory2){
            if(memory1>=crashTime){
                memory1-=crashTime;
                flag = false;
            }
        }
        else{
            if(memory2>=crashTime){
                memory2-=crashTime;
                flag = false;
            }
        }
        if(flag) break;
        crashTime++;
    }
    return {crashTime,memory1,memory2};
}



int main() {

    return 0;
}