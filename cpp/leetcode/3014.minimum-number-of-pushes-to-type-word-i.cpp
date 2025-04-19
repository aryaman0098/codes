/*
 * @lc app=leetcode id=3014 lang=cpp
 *
 * [3014] Minimum Number of Pushes to Type Word I
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, string> u = {
            {2, ""},
            {3, ""},
            {4, ""},
            {5, ""},
            {6, ""},
            {7, ""},
            {8, ""},
            {9, ""},
        };
        int ans = 0, count = 0, currNumber = 2;
        while(count < word.length()) {
            if(currNumber > 9) currNumber = 2;
            u[currNumber] += word[count];
            ans += u[currNumber].length();
            count++;
            currNumber++;
        }
        return ans;
    }
};
// @lc code=end

