//https://leetcode.com/problems/total-hamming-distance/


#include<bits/stdc++.h>

using namespace std;

int totalHammingDistance(vector<int>& nums) {
    int n1, n0, n = nums.size();
    int mx = *max_element(nums.begin(), nums.end());
    int mask = 1;
    int ans = 0;
    while (mask < mx)
        mask <<= 1;
    
    while(mask){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & mask)
                n1 += 1;
        }
        n0 = n - n1;
        ans += n1 * n0;
        mask >>= 1;
    }
    return ans;
}

int main(){

    return 0;
}
