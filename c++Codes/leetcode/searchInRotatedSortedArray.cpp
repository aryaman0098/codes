//https://leetcode.com/problems/search-in-rotated-sorted-array/

#include<bits/stdc++.h>

using namespace std;

int binarySearch(int l, int r, vector<int> nums, int target){
    if(l > r)
        return -1;

    int mid = (l + r) / 2;
    if(nums[mid] == target)
        return mid;
    else if(nums[mid] > target)
        return binarySearch(l, mid - 1, nums, target);
    else
        return binarySearch(mid + 1, r, nums, target);
}


int search(vector<int>& nums, int target) {
    int i;
    if(nums.size() == 1){
        if(nums[0] == target) return 0;
        return - 1;
    }
    int l = 0, h = nums.size() - 1, mid;
    while(l < h){
        mid = l + (h - l) / 2;
        if(nums[mid] > nums[h]) l = mid + 1;
        else h = mid;
    }
    i = l;
    if(i == 0){
        return binarySearch(0, nums.size() - 1, nums, target);
    }
    if(nums[0] > target){
        int l = i, r = nums.size() - 1;
        return binarySearch(l, r, nums, target);
    }else{
        int l = 0, r = i - 1;
        return binarySearch(l, i - 1, nums, target);
    }
    return -1;
}

int main(){

    return 0;
}


