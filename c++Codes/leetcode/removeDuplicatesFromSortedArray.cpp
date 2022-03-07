//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    for(int i = 1; i < n; i++){
        if(nums[i] != nums[i-1]){
            l++;
            nums[l] = nums[i];
        }
    }    
    return l + 1;
}

int main(){

    return 0;
}
