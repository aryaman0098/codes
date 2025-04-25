/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> u;
        int l = wordList[0].size();
        for(int i = 0; i < wordList.size(); i++) {
            u[wordList[i]] = {};
            for(int j = 0; j < wordList.size(); j++) {
                int diffChars = 0;
                for(int k = 0; k < l; k++) {
                    if(wordList[i][k] != wordList[j][k]) diffChars++;
                }
                if(diffChars == 1 && wordList[j] != beginWord) {
                    u[wordList[i]].push_back(wordList[j]);
                } 
            }
        }
        if(u[beginWord].size() == 0) {
            u[beginWord] = {};
            for(int i = 0; i < wordList.size(); i++) {
                int diffCharge = 0;
                for(int k = 0; k < l; k++) {
                    if(beginWord[k] != wordList[i][k]) diffCharge++;
                }
                if(diffCharge == 1) {
                    u[beginWord].push_back(wordList[i]);
                }   
            }
        }
        for(auto c: u) {
            cout<<c.first<<": ";
            for(auto d: c.second) {
                cout<<d<<" ";
            }
            cout<<endl;
        }
        queue<pair<string, int>> q;
        unordered_map<string, bool> visited;
        int minChanges = INT_MAX;
        q.push({beginWord, 1});
        while(!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            if(p.first == endWord) {
                minChanges = min(minChanges, p.second);
                continue;
            }
            if(visited[p.first]) continue;
            visited[p.first] = true;
            for(auto c: u[p.first]) {
                q.push({c, p.second + 1});
            }
        }
        return (minChanges == INT_MAX) ? 0 : minChanges;
    }
};
// @lc code=end

