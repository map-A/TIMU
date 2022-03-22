// 进制转换
// 可以引入的库和版本相关请参考 “环境说明”
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <list>
using namespace std;

string pre_to_ten(string pre, string nums){ // 从pre进制转为10进制
    int res = 0;
    int p = stoi(pre);
    int n = stoi(nums);
    vector<int> temp;
    while(n){ // 先取出nums的每一位
        temp.push_back(n % 10);
        n /= 10;
    }
    for(int i = 0; i < temp.size(); i++){
        res += temp[i] * pow(p,i);
    }
    return to_string(res);
}

string ten_to_after(string after, string nums){ // 从10进制转为after进制
    int a = stoi(after);
    int n = stoi(nums);
    string ret;
    while(n){
        ret+= to_string(n%a);
        n /= a;
    }
    return ret;
}

// 请按你的实际需求修改参数和返回值类型
// pre为原进制数，nums为数值，after为要转换的进制数
string solution (string pre, string nums, string after) {
    // 在这⾥书写你的代码
    string res;
    res = pre_to_ten(pre, nums); // 先从pre进制转为10进制
    res = ten_to_after(after, res); // 再从10进制转为after进制
    return res;
}

int slove(int t,int n1,int n2,int n3,int n4,int left_people,int right_people,
          int left_money,int right_money){
    int tt = t*3;
    int ret = 0;
    int ans = INT_MAX;
    if(t>=left_people&&t<right_people){
        if(ret>=left_money&&ret<=right_money){
            ans = min(ans,(int)ret/t);
        }
        if(tt>=n1){
            ret+=n1*400;
            tt-=n1;
        }
        else{
            ret+=tt*400;
        }
        if(ret>=left_money&&ret<=right_money){

            ans = min(ans,(int)ret/t);
        }
        if(tt>=n2){
            ret+=n2*200;
            tt-=n2;
        }
        else{
            ret+=tt*200;
        }
        if(ret>=left_money&&ret<=right_money){
            ans = min(ans,(int)ret/t);
        }
        if(tt>=n3){
            ret+=n3*100;
            tt-=n3;
        }
        else{
            ret+=tt*100;
        }
        if(ret>=left_money&&ret<=right_money){

            ans = min(ans,(int)ret/t);
        }
        if(tt>=n4){
            ret+=n4*50;
            tt-=n4;
        }
        else{
            ret+=tt*50;
        }
        if(ret>=left_money&&ret<=right_money){
            ans = min(ans,(int)ret/t);
        }
    }
    return ans==INT_MAX?0:ans;
}

int slove_slove(int t,int n1,int n2,int n3,int n4){
    int t1 = slove(t,n1,n2,n3,n4,10,11,0,950);
    int t2 = slove(t,n1,n2,n3,n4,12,14,951,2250);
    int t3 = slove(t,n1,n2,n3,n4,15,19,2251,5550);
    int t4 = slove(t,n1,n2,n3,n4,20,24,5551,9550);
    int t5 = slove(t,n1,n2,n3,n4,25,29,9551,12550);
    int t6 = slove(t,n1,n2,n3,n4,30,INT_MAX,12551,INT_MAX);
    int ans = max({t1,t2,t3,t4,t5,t6});
    return ans;
}

int main(){
    int n1 = 3,n2=10,n3=50,n4=100;
    int ret = INT_MIN;// 1-(n1+n2+n3+n4)
    int n = (n1+n2+n3+n4)/3+1;
    for (int i = 0; i <= n; ++i) {
        ret = max(ret, slove_slove(i,n1,n2,n3,n4));
    }


    return 0;
}
