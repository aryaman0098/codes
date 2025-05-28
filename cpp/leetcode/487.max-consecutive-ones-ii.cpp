#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, r = 0, maxLength = 0, currLength = 0, oneFreq = 0;
        while(r < nums.size()) {
            if(nums[r] == 1) oneFreq++;
            currLength = r - l + 1;
            if(currLength - oneFreq <= 1) maxLength = max(maxLength, currLength);
            else {
                while(currLength - oneFreq > 1) {
                    if(nums[l] == 1) oneFreq--;
                    l++;
                    currLength = r - l + 1;
                }
            }
            r++;
        }
        return maxLength;
    }
};