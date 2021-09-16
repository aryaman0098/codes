//https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include<bits/stdc++.h>

using namespace std;

long long trappingWater(int arr[], int n){
    long long amount = 0;
    vector<pair<int, int> > m;
    m.push_back(make_pair(0, n - 1));
    int maxTillNow = arr[n - 1];
    int index = n - 1;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i + 1] >= maxTillNow){
            maxTillNow = arr[i + 1];
            index = i + 1;
        }
        m.push_back(make_pair(maxTillNow, index));
    }
    reverse(m.begin(), m.end());
    int ht;
    int width;
    int flag = 1;
    int i;
    for(i = 0; i < n; i++){
        if(arr[i + 1] < arr[i]){
            break;
        }
    }
    for(; i < n; i++){
        if(flag == 1){
            ht = min(arr[i], m[i].first);
            if(ht == 0){
                break;
            }
            width = m[i].second - i - 1;
            amount += width * ht;
            flag = 0;
            index = m[i].second;
        }else{
            if(i == index){
                flag = 1;
                i--;
            }else{
                amount -= arr[i];
            }
        }
    }
    return amount;
}

int main(){ 
    int arr[] = {2,1,6,8,5};
    cout<<trappingWater(arr, 5);
    return 0;
}
