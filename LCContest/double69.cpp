#include "bits/stdc++.h"

using namespace std;
string capitalizeTitle(string title) {
    string ret = "";
    bool flag = true;
    string tmp = "";
    for (int i = 0; i < title.size(); ++i) {
        if(title[i]==' '){
            if(tmp.size()>2){
                tmp[0] = toupper(tmp[0]);
            }
            ret+=tmp;
            tmp.clear();
            flag= true;
            ret+=' ';
        }
        else if(flag== true){
            tmp+= tolower(title[i]);
            flag = false;
        }
        else{
            tmp+= tolower(title[i]);
        }
    }
    if(tmp.size()>2){
        tmp[0] = toupper(tmp[0]);
    }
    ret+=tmp;
    return ret;
}



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int pairSum(ListNode* head) {
    int ret = 0;
    vector<int>t;
    ListNode* p = head;
    while (p){
        t.push_back(p->val);
        p =p->next;
    }
    for (int i = 0; i < t.size()/2; ++i) {
        ret=max(ret,t[i]+t[t.size()-i-1]);
    }
    return ret;
}


int longestPalindrome(vector<string> &words) {
    // a: 统计 形如 “ab”
    // b：统计 所有 形如 “aa” 出现的次数（包括 奇数次 和 偶数次）
    // c：统计 奇数次 “aa” 出现的个数
    int a = 0, b = 0, c = 0;
    unordered_map<string, int> m;
    for (int i = 0; i < words.size(); ++i)
        m[words[i]]++;
    for (auto &[str,num]:m) {
        if (str[0] == str[1]) {
            if (num& 1) {
                c++;
            }
            b += num;
        }
        else {
            string to = "";
            to += str[1];
            to += str[0];
            if (m.count(to)) {
                //对于“ab” 可以删除 “ba”减少遍历次数，但是要乘2
                a += 2 * min(m[to], num);
                m.erase(to);
            }
        }
    }
    return 2 * (b + a - (c <= 1 ? 0 : c - 1));
}



int main() {
    string title =  "i lOve leetcode";
    string ret = capitalizeTitle(title);
    return 0;
}