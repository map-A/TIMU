#include "bits/stdc++.h"

using namespace std;

struct KeyPressEvent{
    int deltatime;
    std::bitset<88>keyStatus;
};

void PrintKeyPressStatistics(KeyPressEvent eventArray[],int eventCount){
    vector<int>fre(88,0);
    vector<int>time(88,0);

    bitset<88>tmp = eventArray[0].keyStatus;
    for (int i = 0; i < eventCount; ++i) {
        tmp ^=eventArray[i].keyStatus;
        for (int j = 0; j < 88; ++j) {
            time[j] = eventArray[i].deltatime;
            fre[j]+=tmp[j];
        }
    }
    //
    std::cout<<(fre.begin()- max_element(fre.begin(),fre.end()));
    std::cout<<(fre.begin()- max_element(fre.begin(),fre.end()));

}



int main() {
    string line;
    vector<int> vec;
    string temp;
    getline(cin, line);
    stringstream ss(line);
    while(getline(ss, temp, '.')){
        vec.push_back(stoi(temp));
    }
    auto ret = func(vec);

    return 0;
}