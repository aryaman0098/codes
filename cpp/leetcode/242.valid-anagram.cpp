/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> v(26, 0);
        for(int i = 0; i < s.length(); i++) {
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }
        for(auto c: v) if(c != 0) return false;
        return true;
    }
};
// @lc code=end

