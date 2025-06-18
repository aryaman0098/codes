/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class MyCalendar {
private:
  vector<vector<int>> events;
public:
    MyCalendar() {
      events = {};
    }
    
    bool book(int startTime, int endTime) {
        int i = 0, n = events.size();
        while (i < n && events[i][1] <= startTime)
            i++;
        if (i == n) {
            events.push_back({startTime, endTime});
            return true;
        } else {
            if (endTime <= events[i][0]) {
                events.insert(events.begin() + i, {startTime, endTime});
                return true;
            } else {
                return false;
            }
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
// @lc code=end

