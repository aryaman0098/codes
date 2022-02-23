//https://leetcode.com/problems/squares-of-a-sorted-array/
#include<bits/stdc++.h>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    vector<int> ans;
    int counter = nums.size() - 1;
    while(l <= r){
        if(pow(nums[l],2) < pow(nums[r],2)){
            ans.push_back(pow(nums[r], 2));
            r--;
        }else{
            ans.push_back(pow(nums[l], 2));
            l++;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    return 0;
}
