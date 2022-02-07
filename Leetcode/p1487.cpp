#include "bits/stdc++.h"

using namespace std;
vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string,int>m;
    vector<string>ret;
    for (int i = 0; i < names.size(); ++i) {
        if(!m.count(names[i])){
            ret.push_back(names[i]);
            m[names[i]]=0;

        }
        else{
            int index = m[names[i]]+1;
            string t = names[i]+"("+ to_string(index)+")";
            while (1){
                if(m.count(t)){
                    index++;
                    t = names[i]+"("+ to_string(index)+")";
                }
                else{
                    m[names[i]]=index;
                    break;
                }
            }
            ret.push_back(t);
            m[t] = 0;
        }
    }
    return ret;
}
int main() {
    vector<string>name = {"kaido","kaido(1)","kaido","kaido(1)"};
    auto ret = getFolderNames(name);
    return 0;
}