/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }
        sort(numStrings.begin(), numStrings.end(),
             [](string &a, string &b) { return a + b > b + a; });
        if (numStrings[0] == "0") return "0";
        string largestNum;
        for (string &numStr : numStrings) {
            largestNum += numStr;
        }

        return largestNum;
    }
};
// @lc code=end

