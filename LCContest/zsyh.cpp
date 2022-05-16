#include "bits/stdc++.h"

using namespace std;


//def deleteText(article: str, index: int) -> str:
//    a = article.split(" ")
//    start = 0
//    for i in range(len(a)):
//        if(start<=index<start+len(a[i])):
//            a.pop(i)
//            break
//        elif index== start+len(a[i]):
//            break
//        else:
//            start+=len(a[i])+1
//    ret = ""
//    for i in range(len(a)-1):
//        ret+=a[i]
//        ret+=" "
//    if(len(a)>0):
//        ret+=a[len(a)-1]
//    return ret


int numFlowers(vector<vector<int>>& roads) {
    int n  = roads.size();
vector<vector<int>>graph(n+1);
for (int i = 0; i < roads.size(); ++i) {
    graph[roads[i][0]].push_back(roads[i][1]);
graph[roads[i][1]].push_back(roads[i][0]);

}
int ret = 0;
for (int i = 0; i < graph.size(); ++i) {
    ret = max(ret,(int)graph[i].size());
}
return ret+1;
}

