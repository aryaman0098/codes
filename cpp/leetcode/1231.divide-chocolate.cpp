#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        function<int(int)> splits = [&](int ans) {
            int numSplits = 0, currSum = 0;
            for (auto c : sweetness) {
                currSum += c;
                if (currSum >= ans) {
                    numSplits++;
                    currSum = 0;
                }
            }
            return numSplits;
        };
        int l = INT_MAX, r = 0;
        for (auto c : sweetness) {
            r += c;
            l = min(l, c);
        }
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (splits(mid) >= k + 1)
                l = mid;
            else
                r = mid - 1;
        }
        return r;
    }
};