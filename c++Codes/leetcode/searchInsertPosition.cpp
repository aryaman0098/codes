//https://leetcode.com/problems/search-insert-position/

#include<bits/stdc++.h>

using namespace std;

int binarySearch(int l, int r, vector<int> nums, int target){
    if(l > r)
        return l;
    
    int mid = (l + r) / 2;
    if(nums[mid] == target)
        return mid;
    else if(nums[mid] > target)
        return binarySearch(l, mid - 1, nums, target);
    else
        return binarySearch(mid + 1, r, nums, target);
}

int searchInsert(vector<int>& nums, int target) {
    return binarySearch(0, nums.size() - 1, nums, target);    
}

int main(){

    return 0;
}
