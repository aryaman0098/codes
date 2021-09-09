//https://leetcode.com/problems/find-the-duplicate-number/

#include<bits/stdc++.h>

using namespace std;


int missingNumber(vector<int>& array, int n){
    int s = 0;
    for(int i = 0; i < n - 1; i++){
        s += array[i];
    }
    int sum = (n * (n + 1)) / 2;
    return (sum - s);
}


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
