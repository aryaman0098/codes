/*
 * @lc app=leetcode id=1723 lang=cpp
 *
 * [1723] Find Minimum Time to Finish All Jobs
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size(), ans = INT_MAX;
        vector<int> d(k, 0);
        sort(jobs.rbegin(), jobs.rend());
        unordered_set<string> m;

        function<string(vector<int> v)> hashState = [&](vector<int> d) {
            sort(d.begin(), d.end());
            string key;
            for (int x : d)
                key += to_string(x);
            return key;
        };

        function<void(int)> backTrack = [&](int pos) {
            if (pos == n) {
                ans = min(ans, *max_element(d.begin(), d.end()));
                return;
            }

            string key = hashState(d);
            if (m.find(key) != m.end())
                return;
            m.insert(key);

            for (int i = 0; i < k; i++) {
                d[i] += jobs[pos];
                if (*max_element(d.begin(), d.end()) < ans)
                    backTrack(pos + 1);
                d[i] -= jobs[pos];
                if (d[i] == 0)
                    break;
            }
        };

        backTrack(0);
        return ans;
    }
};
// @lc code=end

