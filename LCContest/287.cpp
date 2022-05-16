#include "bits/stdc++.h"

using namespace std;
int convertTime(string current, string correct) {
    int start_hour = stoi(current.substr(0,2));
    int start_min = stoi(current.substr(3,2));
    int end_hour = stoi(correct.substr(0,2));
    int end_min = stoi(correct.substr(3,2));

    int diff_min = (end_hour-start_hour)*60+(end_min-start_min);

    int ret= 0;
    while (diff_min>0){
        if(diff_min>=60){
            diff_min-=60;
        }
        else if(diff_min>=15){
            diff_min-=15;
        }
        else if(diff_min>=5){
            diff_min-=5;
        }
        else if(diff_min>=1){
            diff_min-=1;
        }
        ret++;
    }
    return ret;

}

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    vector<pair<int,int>>t(1e5+1,{0,0});
    for (int i = 0; i < matches.size(); ++i) {
        t[matches[i][0]]= make_pair(t[matches[i][0]].first+1,t[matches[i][0]].second);
        t[matches[i][1]]= make_pair(t[matches[i][1]].first,t[matches[i][1]].second+1);
    }
    vector<int>ans1;
    vector<int>ans2;
    for (int i = 1; i < t.size(); ++i) {
        if(t[i].first>0&&t[i].second==0){
            //全胜
            ans1.push_back(i);
        }
        else if(t[i].second==1){
            ans2.push_back(i);
        }
    }
    return {ans1,ans2};
}

bool check(vector<int>&candies,long long k,int mid){
    int i=0;
    while (k>0&&i<candies.size()){
        k-=candies[i]/mid;
        i++;
    }
    return k<=0;
}
int maximumCandies(vector<int>& candies, long long k) {
    std::sort(candies.begin(), candies.end());
    int l = 1;
    long long sum = (long long)std::accumulate(candies.begin(), candies.end(), 0LL);
    long long r = sum/k;
    // cout<<r;
    long long ret = 0;
    if(r<=1||check(candies,k,r)) return r;
    long long  mid =0;
    while (l<r){
        mid = (r-l)/2+l;

        if(check(candies,k,mid)){
            ret = mid;
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    return ret;
}


class Encrypter {
private:
    unordered_map<char, string> enc;
    unordered_map<string, int> dec_count;

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n = keys.size();
        for (int i = 0; i < n; ++i) {
            //enc 将key和value组成pair
            enc[keys[i]] = values[i];
        }

        for (const string& word: dictionary) {
            // 给dictionary 每个word 加密，并且统计
            string result = encrypt(word);
            if (result != "") {
                ++dec_count[result];
            }
        }
    }

    string encrypt(string word1) {
        string result;

        for (char ch: word1) {
            if (enc.count(ch)) {
                result += enc[ch];
            }
            else {
                return "";
            }
        }
        return result;
    }

    int decrypt(string word2) {
        return dec_count.count(word2) ? dec_count[word2] : 0;
    }
};

int main() {
    string a = "11:00";
    string b = "11:01";
    int ret = convertTime(a,b);
    return 0;
}