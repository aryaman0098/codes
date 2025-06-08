#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        sort(jobs.begin(), jobs.end());
        sort(workers.begin(), workers.end());
        int ans = INT_MIN, n = workers.size();
        for (int i = 0; i < n; i++) {
            int x = (int)ceil((double)jobs[i] / (double)workers[i]);
            ans = max(ans, x);
        }
        return ans;
    }
};