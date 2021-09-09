//https://leetcode.com/problems/find-the-duplicate-number/

#include<bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        if(nums[abs(nums[i])] > 0){
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        }else{
            return abs(nums[i]);
        }
    }
}

int main(){

    return 0;
}
