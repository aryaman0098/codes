/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int maximiseCharacter(string answerKey, char c, int k) {
        int n = answerKey.length(), currLen = 0, freq = 0, maxLen = 0, l = 0,
            r = 0;
        while (r < n) {
            if (answerKey[r] == c)
                freq++;
            currLen = r - l + 1;
            if (currLen - freq <= k)
                maxLen = max(currLen, maxLen);
            while (currLen - freq > k) {
                if (answerKey[l] == c)
                    freq--;
                l++;
                currLen = r - l + 1;
            }
            r++;
        }
        return maxLen;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maximiseCharacter(answerKey, 'T', k),
                   maximiseCharacter(answerKey, 'F', k));
    }
};
// @lc code=end

