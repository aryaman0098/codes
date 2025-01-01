/*
 * @lc app=leetcode id=1418 lang=cpp
 *
 * [1418] Display Table of Food Orders in a Restaurant
 */
#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map<string, int> foodItemMap;
        unordered_map<string, int> tableNumberMap;
        for (auto c : orders) {
            if (foodItemMap.find(c[2]) == foodItemMap.end())
                foodItemMap[c[2]] = 1;
            if (tableNumberMap.find(c[1]) == tableNumberMap.end())
                tableNumberMap[c[1]] = 1;
        }
        vector<string> foodItems;
        vector<int> tableNumber;
        for (auto c : foodItemMap) {
            foodItems.push_back(c.first);
        }
        for (auto c : tableNumberMap) {
            tableNumber.push_back(stoi(c.first));
        }
        sort(foodItems.begin(), foodItems.end());
        sort(tableNumber.begin(), tableNumber.end());
        unordered_map<string, int> feedIndex;
        unordered_map<string, int> tableIndex;
        vector<vector<string>> ans = {{}};
        ans[0].push_back("Table");
        for (int i = 0; i < foodItems.size(); i++) {
            ans[0].push_back(foodItems[i]);
            feedIndex[foodItems[i]] = i + 1;
        }
        for (int i = 0; i < tableNumber.size(); i++) {
            ans.push_back({to_string(tableNumber[i])});
            tableIndex[to_string(tableNumber[i])] = i + 1;
        }
        for (int i = 1; i < ans.size(); i++) {
            for (int j = 1; j < ans[0].size(); j++) {
                ans[i].push_back("0");
            }
        }
        for (auto c : orders) {
            int row = tableIndex[c[1]];
            int column = feedIndex[c[2]];
            ans[row][column] = to_string(stoi(ans[row][column]) + 1);
        }
        return ans;
    }
};
// @lc code=end

