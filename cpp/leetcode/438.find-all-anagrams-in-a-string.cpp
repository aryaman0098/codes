/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        vector<int> ans;
        for(int i = 0; i < p.length(); i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }
        int l = 0, r = p.length() - 1;
        while(r - l + 1 == p.length()) {
            bool matching = true;
            for(int i = 0; i < 26; i++) {
                if(pCount[i] != sCount[i]) {
                    matching = false;
                    break;
                }
            }
            if(matching) ans.push_back(l);
            sCount[s[l] - 'a']--;
            l++;
            r++;
            if(r < s.length()) sCount[s[r] - 'a']++;
            else break;
        }
        return ans;
    }
};
// @lc code=end

