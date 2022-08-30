//
// Created by mm on 2022/8/15.
//
class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    struct cmp{
        bool operator()(pair<string,int>&a,pair<string,int>&b){
            if(a.second>b.second) return true;
            else if(a.second==b.second && a.first<b.first) return true;
            return false;
        }
    };
    vector<vector<string> > topKstrings(vector<string>& strings, int k) {
        // write code here
        vector<vector<string>>ret;
        map<string,int>m;
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp>pq;
        for(int i=0;i<strings.size();i++){
            m[strings[i]]++;
        }
        auto it = m.begin();
        for(int i=0;i<k;i++){
            pq.push({it->first,it->second});
            it++;
        }
        for(;it!=m.end();it++){
            if((pq.top().second<it->second)||(pq.top().second==it->second&&pq.top().first>it->first)){
                cout<<pq.top().first;
                pq.pop();
                pq.push({it->first,it->second});
            }
        }
        while(!pq.empty()){
            ret.push_back({pq.top().first,to_string(pq.top().second)});
            pq.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};