//https://practice.geeksforgeeks.org/problems/max-rectangle/1

#include<bits/stdc++.h>

using namespace std;

long long getMaxArea(long long arr[], int n){
    stack<long long> s;
    vector<long long> l, r;
    for(int i = 0; i<n; i++){
        if(s.empty()){
            l.push_back(0);
            s.push(i);
        }
        else{
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            l.push_back(s.empty() ? 0 : s.top() + 1);
            s.push(i);
        }
    }
    while(!s.empty()){
        s.pop();
    }
    for(int i = n - 1; i >= 0; i--){
        if(s.empty()){
            r.push_back(n - 1);
            s.push(i);
        }else{
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            r.push_back(s.empty() ? n - 1 : s.top() - 1);
            s.push(i);
        }
    }
    reverse(r.begin(), r.end());
    long long maxArea = 0;
    for(int i = 0; i < n; i++){
        maxArea = max(maxArea, arr[i] * (r[i] - l[i] + 1));
    }
    return maxArea;
}

int main(){

    return 0;
}
