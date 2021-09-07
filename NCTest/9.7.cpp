#include "bits/stdc++.h"

using namespace std;

int findBestMan(std::vector<std::string>Real_Matrix) {
    vector<vector<int>>matrix(Real_Matrix.size());
    for (int i = 0; i < Real_Matrix.size(); i++) {
        std::stringstream ss(Real_Matrix[i]);
        string temp;
        while (getline(ss, temp, ',')) {
            matrix[i].push_back(stoi(temp));
        }
    }

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[i].size(); j++) {
            matrix[0][i] += matrix[j][i];
        }
    }
    int ret = max_element(matrix[0].begin(), matrix[0].end())-matrix[0].begin();

    return ret;
}
static bool cmp(std::pair<int,std::string>a,std::pair<int,std::string>b){
    return a.first>b.first;
}

std::vector<std::string>scoresort(std::vector<std::string>&names,std::vector<std::string>&scores){
    vector<std::pair<int,std::string>>st;         m,. ,.,.m.,,.m.,.,,.mm,.m,.m,...,m.m,./
    string temp;
    for(int i=0;i<names.size();i++){
        std::stringstream ss(scores[i]);
        int score = 0;
        while (getline(ss, temp, ',')) {
            score+=stoi(temp);
        }
        std::pair<int,std::string>t = {score,names[i]};
        st.push_back(t);
    }
    sort(st.begin(),st.end(),cmp);
    vector<std::string>ret;
    for(int i=0;i<st.size();i++){
        ret.push_back(st[i].second);
    }
    return ret;
}
int main()
{
    vector<std::string>name = {"aa","bb","cc"};
    vector<std::string>scores = {"89,92,95,88,91","92,96,81,90,82","89,91,91,78,97"};
    auto ret = scoresort(name,scores);
    return 0;
}