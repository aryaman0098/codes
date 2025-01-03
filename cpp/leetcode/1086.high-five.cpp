/*
 * @lc app=leetcode id=1086 lang=cpp
 *
 * [1086] High Five
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int, vector<int>, less<int>>> studentScoresMap;
        for(auto c: items) {
          if(studentScoresMap.find(c[0]) == studentScoresMap.end()) {
            studentScoresMap[c[0]] = {};
          }
          studentScoresMap[c[0]].push(c[1]);
        }
        vector<int> studentIds;
        for(auto c: studentScoresMap) {
          studentIds.push_back(c.first);
        }
        sort(studentIds.begin(), studentIds.end());
        vector<vector<int>> ans;
        for(auto c: studentIds) {
          int studentId = c;
          int counter = 0, sum = 0;
          while(counter < 5 && !studentScoresMap[c].empty()) {
            counter++;
            sum += studentScoresMap[c].top();
            studentScoresMap[c].pop();
          }
          int average = sum / counter;
          ans.push_back({studentId, average});
        }
        return ans;
    }
};
// @lc code=end

