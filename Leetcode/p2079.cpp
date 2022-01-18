#include "bits/stdc++.h"

using namespace std;
int wateringPlants(vector<int>& plants, int capacity) {
    int ret = 0;
    int water = capacity;
    for (int i = 0; i < plants.size();) {
        if(water>=plants[i]){
            water-=plants[i];
            i++;
            ret+=1;
        }
        else{
            water = capacity;
            ret+=2*i;
        }
    }
    return ret;
}
int main() {
    vector<int>plants = {2,2,3,3};
    int capacity = 5;
    auto ret = wateringPlants(plants,capacity);
    return 0;
}