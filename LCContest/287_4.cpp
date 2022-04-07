#include "bits/stdc++.h"

using namespace std;
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

    return 0;
}