//https://leetcode.com/problems/rotate-array/

#include<bits/stdc++.h>

using namespace std;

void rotate(vector<int>& nums, int k) {
    if(nums.size() == 1)
        return;
    while(nums.size() < k){
        k -= nums.size();
    }
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
}

int main(){

    return 0;
}
