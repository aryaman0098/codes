//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include<bits/stdc++.h>

using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size() - 1;
    int l = 0, r = n;
    int mid;
    while( l < r){
        if(nums[l] < nums[r])
            return nums[l];
        mid = l + (r - l) / 2;
        if(nums[mid] >= nums[l])
            l = mid + 1;
        else
            r = mid;
    }
    return nums[l];
}

int main(){

    return 0;
}
