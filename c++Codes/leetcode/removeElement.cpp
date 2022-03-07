//https://leetcode.com/problems/remove-element/

#include<bits/stdc++.h>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int l = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] != val){
            nums[l] = nums[i];
            l++;
        }
    }
    return l;
}

int main(){

    return 0;
}
