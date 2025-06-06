/*
 * @lc app=leetcode id=2305 lang=cpp
 *
 * [2305] Fair Distribution of Cookies
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size(), ans = INT_MAX;
        vector<int> d(n, 0);
        function<void(int)> backtrack = [&](int pos) {
            if (pos == n) {
                ans = min(ans, *max_element(d.begin(), d.end()));
                return;
            }
            for (int i = 0; i < k; i++) {
                d[i] += cookies[pos];
                backtrack(pos + 1);
                d[i] -= cookies[pos];
                if (d[i] == 0)
                    break;
            }
        };
        backtrack(0);
        return ans;
    }
};
// @lc code=end

