#include<bits/stdc++.h>
using namespace std;

int len = 1;
int sum[100001] = {0,1};
bool cmp(pair<int,int> &a,pair<int,int>&b){
    return a.first * a.second < b.first * b.second;
}
void multiple(long long x){
    for(int i = 1;i <= len; i++){
        sum[i] *= x;
    }
    for(int i = 1;i <= len; i++){
        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
    }
    len++;
    while(sum[len] / 10){
        sum[len + 1] = sum[len] / 10;
        sum[len] %= 10;
        len++;
    }
    if(sum[len] == 0)
        len--;
}
void solve(vector<pair<int,int>>&m,int n){
    for(int i = 0;i < n; i++){
        multiple(m[i].first);
    }
    for(int i = len; i >= 1; i--){
        sum[i - 1] += (sum[i] % m[n].second * 10);
        sum[i] /= m[n].second;
    }
    while(!sum[len]){
        len--;
    }
    if(len == 0) cout << "1" << endl;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>>m(1002);
    cin >> m[0].first >> m[0].second;
    for(int i = 1;i <= n; i++){
        cin >> m[i].first >> m[i].second;
    }
    sort(m.begin()+1, m.begin() + 1 + n, cmp);
    solve(m,n);
    for(int i = len; i >= 1; i--){
        cout << sum[i];
    }
}
