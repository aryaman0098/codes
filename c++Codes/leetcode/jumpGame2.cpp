//https://leetcode.com/problems/jump-game-ii/

#include<bits/stdc++.h>

using namespace std;

unordered_map<int, int> u;

int dp(int index, vector<int> nums){
    if(index >= nums.size() - 1){
        return 0;
    }else if(u.find(index) == u.end()){
        u[index] = INT_MAX;
        for(int i = 1; i <= nums[index]; i++){
            u[index] = min(u[index], 1 + dp(index + i, nums));
        }
    }
    return u[index];
}

int jump(vector<int>& nums) {
    return dp(0, nums);
}

int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(4);
    cout<<jump(nums);
    return 0;
}
