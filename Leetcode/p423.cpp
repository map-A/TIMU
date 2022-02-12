#include "bits/stdc++.h"

using namespace std;
string originalDigits(string s) {
    map<char,int>m;
    vector<int>tmp(10,0);
    string ret = "";
    for (int i = 0; i < s.size(); ++i) {
        m[s[i]]++;
    }
    if(m.count('z')&&m['z']>0){
        tmp[0] = m['z'];
        m['e']-=m['z'];
        m['r']-=m['z'];
        m['o']-=m['z'];
        m.erase('z');
    }
    if(m.count('w')&&m['w']>0){
       tmp[2] = m['w'];
        m['t']-=m['w'];
        m['o']-=m['w'];
        m['w'] = 0;
    }
    if(m.count('u')&&m['u']>0){
       tmp[4]=m['u'];
        m['f']-=m['u'];
        m['o']-=m['u'];
        m['r']-=m['u'];
        m['u']=0;
    }
    if(m.count('f')&&m['f']>0){
        tmp[5] = m['f'];
        m['i']-=m['f'];
        m['v']-=m['f'];
        m['e']-=m['f'];
        m['f']=0;
    }
    if(m.count('o')&&m['o']>0){
        tmp[1] = m['o']-m['w']-m['u'];
        m['o'] = m['w']+m['u'];
        m['n'] -= m['o']-m['w']-m['u'];
        m['e'] -= m['o']-m['w']-m['u'];
    }

    if(m.count('x')&&m['x']>0){
        tmp[6] = m['x'];
        m['s']-=m['x'];
        m['i']-=m['x'];
        m['x']=0;
    }
    if(m.count('v')&&m['v']>0){
        tmp[7] = m['v'];
        m['s']-=m['v'];
        m['n']-=m['v'];
        m['e']-=2*m['v'];
        m['v'] = 0;
    }

    if(m.count('g')&&m['g']>0){
        tmp[8] = m['g'];
        m['e']-=m['g'];
        m['i']-=m['g'];
        m['h']-=m['g'];
        m['t'] -= m['g'];
        m['g'] = 0;
    }
    if(m.count('i')&&m['i']>0){
       tmp[9] = m['i'];
       m['e']-=m['i'];
    }

    if(m.count('t')&&m['t']>0){
        tmp[3] = m['t'];
        m['h']-=m['t'];
        m['r']-=m['t'];
        m['e']-=2*m['t'];
        m['t'] = 0;
    }
    for (int i = 0; i < 10; ++i) {
        ret+=string(tmp[i],'0'+i);
    }



    return ret;
}
int main() {
    string s = "egith";
    string ret = originalDigits(s);
    return 0;
}