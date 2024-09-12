/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 */

// @lc code=start

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
  vector<string> splitString(string s) {
    vector<string> splitString;
    string temp = "";
    for(int i = 0; i < s.length(); i++) {
      if(s[i] == ' ') {
        splitString.push_back(temp);
        temp = "";
        continue;
      }
      temp += s[i];
    } 
    splitString.push_back(temp);
    return splitString;
  }

  bool isNumber(string s) {
    for(auto c: s) {
      if(!(c >= 48 && c <= 57)) {
        return false;
      }
    }
    return true;
  }

  bool compareLetterLogs(string a, string b) {
    vector<string> splitStringa = splitString(a);
    vector<string> splitStringb = splitString(b);
    
    string aLogs = "", bLogs = "";
    for (int i = 1; i < splitStringa.size(); i++)   {aLogs += splitStringa[i] + " ";}
    for (int i = 1; i < splitStringb.size(); i++)   {bLogs += splitStringb[i] + " ";}

    aLogs = aLogs.substr(0, aLogs.length() - 1);
    bLogs = bLogs.substr(0, bLogs.length() - 1);

    if(string(aLogs) == string(bLogs)) {
      return string(splitStringa[0]) < string(splitStringb[0]);
    }

    return string(aLogs) < string(bLogs);
  }

  vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> letterLogs;
    vector<string> digitLogs;
    for(auto c: logs) {
      vector<string> splitStringFromLog = splitString(c);
      if(isNumber(splitStringFromLog[1])) {
        digitLogs.push_back(c);
      } else {
        letterLogs.push_back(c);
      }
    }

    sort(letterLogs.begin(), letterLogs.end(), [this](const string& a, const string& b) {
        return compareLetterLogs(a, b);
    });

    vector<string> updatedLogs;

    for(auto c: letterLogs) {
      updatedLogs.push_back(c);
    }
    for(auto c: digitLogs) {
      updatedLogs.push_back(c);
    }
  
    return updatedLogs;
  }
};
// @lc code=end

