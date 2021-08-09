#include "bits/stdc++.h"

using namespace std;

void backtrack(map<int, int> &m, vector<vector<int>> &ret, vector<int> &tmp, int n) {
    if (tmp.size() == n) {
        ret.push_back(tmp);//当最后生成的tmp string长度等于n即可添加到最后结果中，n指的是输入字符串长度，
    }
    for (auto &i:m) {
        if (i.second > 0) {//当i.second>0,表示有字符i.first可以被使用
            i.second--;//使用一次字符i.first,i.second--;
            tmp.push_back(i.first);//加到生成的字符串中
            backtrack(m, ret, tmp, n);//下一步生成tmp
            tmp.pop_back();
            i.second++;//上面回溯结束后，使用过的i.first拿出去，又可以被使用，因此tmp弹出最后一个元素，i.second++
        }
    }
}

vector<vector<int> > permuteUnique(vector<int> &num) {
    map<int, int> m;
    for (auto &i : num) {
        m[i]++;
    }
    vector<vector<int>> ret;
    vector<int> tmp;
    backtrack(m, ret, tmp, num.size());
    return ret;
}

bool next_Permutation_Of_Own(vector<int> &num) {
    int i = num.size() - 2;
    while (i >= 0 && num[i] >= num[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    int j = num.size() - 1;
    while (j >= 0 && num[i] >= num[j]) {
        j--;
    }
    swap(num[i], num[j]);
    reverse(num.begin() + i + 1, num.end());
    return true;
}

vector<vector<int>> permute(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int>> ret;
    ret.push_back(num);
    while (next_permutation(num.begin(), num.end())) {
        ret.emplace_back(num);
    };
    return ret;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}