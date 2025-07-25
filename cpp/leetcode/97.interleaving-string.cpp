/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3)
            return false;
        vector<vector<int>> c(n1 + 1, vector<int>(n2 + 1, -1));
        function<bool(int, int)> isPossible = [&](int index1, int index2) {
            if (index1 == n1 && index2 == n2)
                return true;
            if (c[index1][index2] != -1)
                return c[index1][index2] == 1;
            int k = index1 + index2;
            bool res = false;
            if (index1 < n1 && s1[index1] == s3[k]) {
                res = res || isPossible(index1 + 1, index2);
            }
            if (index2 < n2 && s2[index2] == s3[k]) {
                res = res || isPossible(index1, index2 + 1);
            }
            c[index1][index2] = res;
            return res;
        };
        return isPossible(0, 0);
    }
};
// @lc code=end

