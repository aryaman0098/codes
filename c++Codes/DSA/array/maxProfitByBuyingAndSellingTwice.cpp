//https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

#include<bits/stdc++.h>

using namespace std;

int maxProfit(int arr[], int n){
    int first_buy = INT_MIN;
    int first_sell = 0;
    int second_buy = INT_MIN;
    int second_sell = 0;
    
    for(int i = 0;i < n; i++) {
        
        first_buy = max(first_buy, -arr[i]);
        first_sell = max(first_sell, first_buy+arr[i]);
        second_buy = max(second_buy, first_sell-arr[i]);
        second_sell = max(second_sell, second_buy+arr[i]);
       
    }
     return second_sell;
}

int main(){

    int price[] = {10, 22, 5, 75, 65, 80};
    cout<<maxProfit(price, 6);
    return 0;
}
