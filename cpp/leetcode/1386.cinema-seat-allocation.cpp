/*
 * @lc app=leetcode id=1386 lang=cpp
 *
 * [1386] Cinema Seat Allocation
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:

    bool findInMap(int n, unordered_map<int, int> u) {
      return u.find(n) != u.end();
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
      unordered_map<int, unordered_map<int, int>> u;
      for(auto c: reservedSeats) {
        if(u.find(c[0]) == u.end()) {
          u[c[0]] = {};
        }
        u[c[0]][c[1]] = 1;
      }
      int count = 0;
      count += (n - u.size()) * 2;
      for(auto i: u) {
        if(findInMap(4, u[i.first]) || findInMap(5, u[i.first])) {
          if(findInMap(6, u[i.first]) || findInMap(7, u[i.first])) {
            continue;
          } else if(findInMap(8, u[i.first]) || findInMap(9, u[i.first])) {
            continue;
          } else {
            count += 1;
          }
        } else if(findInMap(6, u[i.first]) || findInMap(7, u[i.first])) {
          if(findInMap(4, u[i.first]) || findInMap(5, u[i.first])) {
            continue;
          } else if(findInMap(2, u[i.first]) || findInMap(3, u[i.first])) {
            continue;
          } else {
            count += 1;
          }
        } else if ((findInMap(2, u[i.first]) || findInMap(3, u[i.first])) && !findInMap(8, u[i.first]) && !findInMap(9, u[i.first])) {
          count += 1;
        } else if((findInMap(8, u[i.first]) || findInMap(9, u[i.first])) && !findInMap(2, u[i.first]) && !findInMap(3, u[i.first])) {
          count += 1;
        } else if((findInMap(2, u[i.first]) || findInMap(3, u[i.first])) && (findInMap(8, u[i.first]) || findInMap(9, u[i.first]))) {
          count += 1;
        } else {
          count += 2;
        }
      }   
      return count;
    }
};
// @lc code=end

