//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices){
    vector<int> aux(prices.size());
    int max = INT_MIN;
    for(int i  = prices.size(); i >= 0; i--){
        if(prices[i] > max){
            max = prices[i];
        }
        aux[i] = max;
    }
    int profit = INT_MIN;
    int temp;
    for(int i = 0; i < prices.size(); i++){
        temp = aux[i] - prices[i];
        if(temp > profit){
            profit = temp;
        }
    }
    return (profit >= 0) ? profit : 0;
}

int main(){

    return 0;
}
