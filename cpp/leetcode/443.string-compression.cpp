/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int l = 0, r = 0, n = chars.size();
        while (r < n) {
            int count = 1;
            char c = chars[r];
            while (r < n - 1 && chars[r] == chars[r + 1]) {
                count++;
                r++;
            }
            r++;
            chars[l] = c;
            l++;
            if(count > 1) {
                string sc = to_string(count);
                for (int i = 0; i < sc.length(); i++) {
                    chars[l] = sc[i];
                    l++;
                }
            }
        }
        return l;
    }
};
// @lc code=end

