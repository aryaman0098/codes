//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    int maxTillNow = INT_MIN;
    int maxProfitVal = INT_MIN;
    int n = prices.size();
    for(int i = n - 1; i >= 0; i--) {
        if(prices[i] > maxTillNow) {
            maxTillNow = prices[i];
        }
        if((maxTillNow - prices[i]) > maxProfitVal) {
            maxProfitVal = maxTillNow - prices[i];
        }
    }
    return maxProfitVal;
}

int main() {

    return 0;
}