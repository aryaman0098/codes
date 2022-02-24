//https://leetcode.com/problems/move-zeroes/

#include<bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& nums){
    if(nums.size() == 0)
        return;
    int pos = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 1){
            nums[pos] = nums[i];
            pos++;
        }
    }
    while(pos < nums.size()){
        nums[pos] = 0;
        pos++;
    }
}

int main(){

    return 0;
}
