#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    int temp = INT_MIN;
    int maxProfitVal = INT_MIN;
    int n = prices.size();
    for(int i = n - 1; i >=0; i--) {
        if(prices[i] > temp) {
            temp = prices[i];
        }
        if((temp - prices[i]) > maxProfitVal) {
            maxProfitVal = temp - prices[i];
        }
    }
    return maxProfitVal;
}

int main() {

    return 0;
}