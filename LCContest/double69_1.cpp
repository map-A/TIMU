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
int main() {
    string title =  "i lOve leetcode";
    string ret = capitalizeTitle(title);
    return 0;
}