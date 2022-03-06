#include<bits/stdc++.h>

using namespace std;


int mostFrequent(vector<int>& nums, int key) {
    unordered_map<int, int> u;
    int n = nums.size();
    for(int i = 0; i < n - 1; i++){
        if(nums[i] == key)
            u[nums[i + 1]]++;
    }
    int max = INT_MIN;
    int ans;
    for(auto m : u){
        if(m.second > max){
            max = m.second;
            ans = m.first;
        }
    }
    return ans;
}


int main(){

    return 0;
}
