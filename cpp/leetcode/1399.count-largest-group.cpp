/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        function<int(int)> sumOfDigits = [&](int n) {
            int count = 0;
            int ans = 0;
            while (n > 0) {
                ans += n % 10;
                n /= 10;
            }
            return ans;
        };
        unordered_map<int, vector<int>> u1;
        unordered_map<int, int> u2;
        for (int i = 1; i <= n; i++) {
            int x = sumOfDigits(i);
            u1[x].push_back(i);
        }
        int maxSize = INT_MIN;
        for (auto c : u1) {
            u2[c.second.size()]++;
            maxSize = max(maxSize, (int)c.second.size());
        }
        return u2[maxSize];
    }
};
// @lc code=end

