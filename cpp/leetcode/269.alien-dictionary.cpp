#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        for (string& word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
                return "";
            }
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    if (!graph[w1[j]].count(w2[j])) {
                        graph[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }
        queue<char> q;
        for (auto& entry : indegree) {
            if (entry.second == 0) {
                q.push(entry.first);
            }
        }
        string result;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            result += c;
            for (char neighbor : graph[c]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return result.size() == indegree.size() ? result : "";
    }
};