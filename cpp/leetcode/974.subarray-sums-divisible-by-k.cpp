/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixMod(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            prefixMod[i] = (sum % k + k) % k;
        }
        cout<<endl;
        int ans = 0;
        unordered_map<int, int> u;
        for(int i = 0; i < n; i++) {
            if(prefixMod[i] == 0) {
                if(u.find(0) == u.end()) {
                    ans += 1;
                    u[0] = 1;
                } else {
                    ans += 1 + u[0];
                    u[0] += 1;
                }
            } else if(u.find(prefixMod[i]) != u.end()) {
                ans += u[prefixMod[i]];
                u[prefixMod[i]] += 1;
            } else {
                u[prefixMod[i]] = 1;
            }
        }
        return ans;
    }
};
// @lc code=end

