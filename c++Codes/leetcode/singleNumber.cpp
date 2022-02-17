//https://leetcode.com/problems/single-number/

#include<bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums){
    // unordered_map<int, int> u;
    // for(int i = 0; i < nums.size(); i++){
    //     u[nums[i]]++;
    // }
    // for(auto i : u){
    //     if(i.second == 1){
    //         return i.first;
    //     }
    // }
    int ans = nums[0];
    for(int i = 1; i < nums.size(); i++){
        ans ^= nums[i];
    }
    return ans;
}

int main(){

    return 0;
}
