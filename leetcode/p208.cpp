#include "bits/stdc++.h"
#include "cstdio"
using namespace std;
class Trie {
    Trie *child[26];
    bool isWord;
public:
    /** Initialize your data structure here. */
    Trie() {
        isWord = false;
        for(int i=0;i<26;i++){
            child[i] = nullptr;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *t = this;
        for(char c: word){
            if(!t -> child[c-'a']){
                t->child[c-'a'] = new Trie();
            }
            t = t->child[c-'a'];
        }
        t->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *t = this;
        for(char c:word){
            if(!t -> child[c - 'a']){
                return false;
            }
            t = t->child[c - 'a'];
        }
        return t->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *t = this;
        for(char c:prefix){
            if(!t->child[c-'a']){
                return false;
            }
            t = t->child[c - 'a'];
        }
        return true;
    }
};
int main() {
    Trie* obj = new Trie();
    obj->insert("app");
    obj->insert("apple");
    obj->insert("apps");
    obj->insert("jam");
    obj->insert("rental");
    bool param_1 = obj->search("jan");
    bool param_2 = obj->search("app");
    bool param_3 = obj->startsWith("c");

    return 0;
}