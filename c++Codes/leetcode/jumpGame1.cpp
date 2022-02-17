//https://leetcode.com/problems/jump-game/

#include<bits/stdc++.h>

using namespace std;

bool canJump(vector<int>& nums){
    if(nums.size() == 1){
        return true;
    }
    int canReach = nums[0];
    int n = nums.size();
    for(int i = 1; i <= canReach; i++){
        canReach = max(i + nums[i], canReach);
        if(canReach >= n - 1){
            return true;
        }
    }
    return false;
}

int main(){

    return 0;
}
