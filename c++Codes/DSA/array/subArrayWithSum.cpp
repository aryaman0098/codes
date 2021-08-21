//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#

#include<bits/stdc++.h>

using namespace std;

vector<int> subArraySum(int arr[], int n, int s){
    int p1 = 0;
    vector<int> indices;
    while(arr[p1] > s){
        if(arr[p1] == s){
            indices.push_back(p1 + 1);
            indices.push_back(p1 + 1);
            return indices;
        }
        p1++;
    }
    int p2 = p1;
    int sum = arr[p1];
    while(p2 < n){
        if(sum < s){
            p2++;
            sum = sum + arr[p2];
        }else if(sum > s){
            p1++;
            sum = sum - arr[p1 - 1];
        }else{
            indices.push_back(p1 + 1);
            indices.push_back(p2 + 1);
            return indices;
        }
    }
    indices.push_back(-1);
    return indices;
}

int main(){
    int n, s;
    cin>>n;
    cin>>s;
    int* arr = new int(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    vector<int> indices = subArraySum(arr, n, s);
    for(int i = 0; i < 2; i++){
        cout<<indices[i]<<" ";
    }
    cout<<"\n";
}