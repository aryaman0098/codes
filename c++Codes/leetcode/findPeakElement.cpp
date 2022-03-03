//https://leetcode.com/problems/find-peak-element/

#include<bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size() - 1;
    int l = 0, r = n;
    int mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(nums[mid] < nums[mid] + 1)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int main(){

    return 0;
}
