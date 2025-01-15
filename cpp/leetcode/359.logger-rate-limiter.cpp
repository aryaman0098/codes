/*
 * @lc app=leetcode id=359 lang=cpp
 *
 * [359] Logger Rate Limiter
 */

#include<bits/stdc++.h>

using namespace std;

// @lc code=start
class Logger {
private:
    
    unordered_map<string, bool> messages;
    queue<pair<string, int>> messageTime;

    void updateQueue(int timestamp) {
        while(!messageTime.empty() && messageTime.front().second + 10 <= timestamp) {
            messages.erase(messageTime.front().first);
            messageTime.pop();
        }
    }

public:
    
    Logger() {
        messages = {};
        messageTime = {};
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        updateQueue(timestamp);
        if(messages.find(message) != messages.end()) return false;
        else {
            messageTime.push({message, timestamp});
            messages[message] = true;
        }
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
// @lc code=end

