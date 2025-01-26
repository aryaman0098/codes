#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        vector<int> values;
        int n = present.size();
        for (int i = 0; i < n; i++) {
            values.push_back(future[i] - present[i]);
        }
        vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int w = 0; w <= budget; w++) {
                int notTake = dp[i][w];
                int take = 0;
                if (present[i] <= w && values[i] > 0) {
                    take = values[i] + dp[i][w - present[i]]; 
                }
                dp[i+1][w] = max(notTake, take);
            }
        }

        return dp[n][budget];
    }   
};