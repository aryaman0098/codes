//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices){
    bool bought = false;
    int profit = 0;
    if(prices.size() == 1)
        return profit;
    int buyingPrices;
    for(int i = 0; i < prices.size() - 1; i++){
        if(!bought){
            if(prices[i] < prices[i + 1]){
                buyingPrices = prices[i];
                bought = true;
            }
        }else{
            if(prices[i] > prices[i + 1]){
                profit += prices[i] - buyingPrices;
                bought = false;
            }
        }
    }
    if(bought){
        profit += prices[prices.size() - 1] - buyingPrices;
    }
    return profit;    
}

int main(){

    return 0;
}
