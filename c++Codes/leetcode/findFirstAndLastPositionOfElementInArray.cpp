//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<bits/stdc++.h>

using namespace std;

vector<int> binarySearch(vector<int> nums, int target, int l, int r){
    int mid = l + (r - l) / 2;
    if(nums[mid] == target){
        vector<int> ans;
        int i = mid, j = mid;
        while(i >= 0 && ans[i] == target)
            i--;
        while(j <= nums.size() - 1 && ans[j] == target)
            j++;
        ans.push_back(i + 1);
        ans.push_back(j - 1);
        return ans;
    }
    else if(nums[mid] > target)
        binarySearch(nums, target, l, mid - 1);
    else
        binarySearch(nums, target, mid + 1, r);
}

vector<int> searchRange(vector<int>& nums, int target) {
    return binarySearch(nums, target, 0, nums.size());
}

int main(){

    return 0;
}
