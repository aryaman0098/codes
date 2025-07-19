/*
 * @lc app=leetcode id=2266 lang=cpp
 *
 * [2266] Count Number of Texts
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.length();
        vector<int> dp(n + 1);
        dp[n] = 1;
        unordered_map<int, int> numTimesMapping = {
            {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3},
            {7, 4}, {8, 3}, {9, 4}
        };
        for (int i = n - 1; i >= 0; --i) {
            char c = pressedKeys[i];
            int maxPress = numTimesMapping[c - '0'];
            long long ways = 0;

            for (int len = 1; len <= maxPress && i + len <= n; ++len) {
                if (pressedKeys[i + len - 1] != c)
                    break;
                ways += dp[i + len];
            }

            dp[i] = ways % MOD;
        }

        return dp[0];
    }
};

// class Solution {
// private:
//     const int MOD = 1e9 + 7;
// public:
//     int countTexts(string pressedKeys) {
//         int n = pressedKeys.length();
//         vector<int> v(n + 1, -1);
//         unordered_map<int, int> numTimesMapping = {
//             {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}, {7, 4}, {8, 3}, {9, 4}};

//         function<int(int)> numWays = [&](int index) {
//             if (index == n)
//                 return 1;
//             if (v[index] != -1)
//                 return v[index];

//             char c = pressedKeys[index];
//             long long ans = 0;
//             int maxPress = numTimesMapping[c - '0'];

//             for (int i = 1; i <= maxPress && index + i <= n; i++) {
//                 if (pressedKeys[index + i - 1] != c)
//                     break;
//                 ans += numWays(index + i);
//             }
//             ans %= MOD;
//             v[index] = ans;
//             return v[index];
//         };

//         return numWays(0);
//     }
// };

// @lc code=end

