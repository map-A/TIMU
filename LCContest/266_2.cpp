#include "bits/stdc++.h"

using namespace std;
long long countVowels(string word) {
    long long ret = 0, n = word.size();
    for(int i = 0; i < n; ++i)
    {
        if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
        {
            ret += (i+1)*(n-i);
        }
    }
    return ret;
}
int main() {
    realloc()
    auto r = countVowels("sasa");
    return 0;
}