#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> u;
        int ans = 0;
        int l = 0, r = 0;
        while (r < s.length()) {
            u[s[r]]++;
            while (u.size() > 2) {
                u[s[l]]--;
                if (u[s[l]] == 0) u.erase(s[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};