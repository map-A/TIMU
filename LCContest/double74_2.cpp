#include "bits/stdc++.h"

using namespace std;
long long maximumSubsequenceCount(string text, string pattern) {
    long long sum=0;
    long long a=0;
    long long b=0;
    int len=text.size();
    if(pattern[0]==pattern[1])
    {
        for(int i=0;i<len;i++)
        {
            if(text[i]==pattern[0]) a++;
        }
        return (1+a)*a/2;
    }
    for(int i=0;i<len;i++)
    {
        if(text[i]==pattern[0])
        {
            a++;
        }
        else if(text[i]==pattern[1])
        {
            b++;
            sum=sum+a;//在pattern[1]之前有多少个a
        }
    }
    return sum+max(a,b);
}
int main() {

    return 0;
}