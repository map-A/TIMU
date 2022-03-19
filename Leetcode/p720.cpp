#include "bits/stdc++.h"

using namespace std;
class Trie {
public:
    Trie() {
        this->children = vector<Trie *>(26, nullptr);
        this->isEnd = false;
    }

    bool insert(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
        return true;
    }

    bool search(const string & word) {
        Trie * node = this;
        for (const auto & ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr || !node->children[index]->isEnd) {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEnd;
    }
private:
    vector<Trie *> children;
    bool isEnd;
};

string longestWord(vector<string>& words) {
    Trie trie;
    for (const auto & word : words) {
        trie.insert(word);
    }
    string longest = "";
    for (const auto & word : words) {
        if (trie.search(word)) {
            if (word.size() > longest.size() || (word.size() == longest.size() && word < longest)) {
                longest = word;
            }
        }
    }
    return longest;
}
int main() {
    vector<string>students;
    map<string,vector<int>>m;
    for (int i = 0; i < students.size(); ++i) {
        if(m.count(students[i])){
            //表示m中已经有这个名字le
            //这里只是想饶你知道map 的count 方法
            m[students[i]].push_back(i);
        }
        else{
            m[students[i]].push_back(i);
        }
    }

    // 重名的，m[student_name] 这个vector de size 肯定大于1
    char* p1 = new char[100];
    char p2[100];
    char* p3 = "hello";
    cout<< sizeof(p1)<<endl;
    cout<< sizeof(p2)<<endl;
    cout<< sizeof(p3)<<endl;
    return 0;
}



int gemstonesGame(vector<int>& gemstones){
    int n = gemstones.size();
    vector<int> sum(n + 1, 0);
    for(int i=0;i<n;i++){
        sum[i + 1] = sum[i] + gemstones[i];
    }
    vector<int> dp(n + 1, 0);
    int max_num = sum[n];
    for(int i=n-1;i>0;i--){
        dp[i] = max_num;
        max_num = max(max_num, sum[i] - dp[i]);
    }
    return dp[1];
}



















