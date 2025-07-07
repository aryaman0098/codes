#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPotholes(string road, int budget) {
        vector<int> potholeSizes;
        int n = road.length();
        for (int i = 0; i < n; i++) {
            int count = 0;
            while (i < n && road[i] == 'x') {
                count++;
                i++;
            }
            if (count > 0) {
                potholeSizes.push_back(count);
                i--;
            }
        }
        sort(potholeSizes.begin(), potholeSizes.end(), greater<int>());
        int ans = 0;
        for (auto c : potholeSizes) {
            if(budget >= c + 1) {
                ans += c;
                budget -= c + 1;
            } else {
                if(budget > 0) {
                    ans += budget - 1;
                    break;
                }
            }
        }
        return ans;
    }
};