//https://leetcode.com/problems/find-the-duplicate-number/

#include<bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        if(nums[abs(nums[i]) - 1] > 0) {
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        } else {
            return nums[i];
        }
    }
    return 0;
}

int main() {

    return 0;
}