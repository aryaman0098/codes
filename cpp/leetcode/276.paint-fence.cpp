#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 1) return k;
        int oneBack = k * k, twoBack = k, curr;
        for(int i = 2; i < n; i++) {
            curr = (k - 1) * (oneBack + twoBack);
            twoBack = oneBack;
            oneBack = curr;
        }
        return oneBack;
    }
};