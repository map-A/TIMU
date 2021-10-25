#include "bits/stdc++.h"

using namespace std;
int countValidWords(string sentence) {
    stringstream ss(sentence);
    string temp;
    vector<string>word;
    while(getline(ss, temp, ' ')){
        if(temp!="")
        word.push_back(temp);
    }
    int ret = 0;

    for(auto i:word){
        int j;
        int isTrue = 0;
        for(j=0;j<i.size()-1;j++){
            if(isdigit(i[j])){

                break;
            }
            else if(i[j]=='!'||i[j]=='.'||i[j]==','){
                break;
            }
            else if(i[j]=='-'&&isTrue==0){
                if(j==0||(i[j-1]<'a'||i[j-1]>'z')||(i[j+1]<'a'||i[j+1]>'z')){
                    break;
                }
                else{
                    isTrue++;
                }
            }
            else if(i[j]=='-'&&isTrue>0){
                break;
            }
        }
        if(j==i.size()-1){
            if (i.back()=='-'||isdigit(i.back())){
                continue;
            }
            else{
                ret++;
            }
        }
    }
    return ret;

}
int main() {
    string a =  "q-,";
    int ret = countValidWords(a);
    return 0;
}