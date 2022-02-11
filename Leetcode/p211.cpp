#include "bits/stdc++.h"

using namespace std;

//TODO: 全部通过但是超时了

struct Trie{
    Trie *child[26];
    bool isWord;
    Trie(){
        isWord = false;
        for(int i=0;i<26;i++){
            child[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    Trie *root;
    WordDictionary() {
       root = new Trie();
    }

    void addWord(string word) {
        Trie *t = root;
        for(char c: word){
            if(!t -> child[c-'a']){
                t->child[c-'a'] = new Trie();
            }
            t = t->child[c-'a'];
        }
        t->isWord = true;
    }

    bool search(string word) {
        return dfs(word,0, root);
    }
    bool dfs(string word,int index,Trie *t){
        if(!t) return false;
        if(index==word.size()){
            return t->isWord;
        }
        if(word[index]=='.'){
            for (int i = 0; i < 26; ++i) {
                if(dfs(word,index+1,t->child[i])){
                    return true;
                }
            }
        }
        else {
            return dfs(word,index+1,t->child[word[index]-'a']);
        }
        return false;
    }

};
int main() {

    return 0;
}