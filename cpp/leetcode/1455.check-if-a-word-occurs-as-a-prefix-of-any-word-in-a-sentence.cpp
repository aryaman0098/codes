/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> tokenizedArray;
        string temp = "";
        for(auto c: sentence) {
            if(c == ' ') {
                tokenizedArray.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }   
        tokenizedArray.push_back(temp);
        int size = searchWord.length();
        for(int i = 0; i < tokenizedArray.size(), i++) {
          if(tokenizedArray[i].substr(0, size) == searchWord) {
            return i + 1;
          }
        }
        return -1;
    }
};
// @lc code=end

