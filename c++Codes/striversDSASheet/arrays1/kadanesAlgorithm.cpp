#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxTillNow = 0;
    int maxSum = INT_MIN;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        maxTillNow += nums[i];
        if(maxTillNow > maxSum) {
            maxSum = maxTillNow;
        }
        if(maxTillNow < 0) {
            maxTillNow = 0;
        } 
    }
    return maxSum;
}

int main() {

    return 0;
}