//https://practice.geeksforgeeks.org/problems/max-rectangle/1

#include<bits/stdc++.h>

using namespace std;

int getMaxArea(int arr[], int n){
    stack<int> s;
    vector<int> l, r;
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
    int maxArea = 0;
    for(int i = 0; i < n; i++){
        maxArea = max(maxArea, arr[i] * (r[i] - l[i] + 1));
    }
    return maxArea;
}

int maxArea(int M[MAX][MAX], int n, int m){
    int arr[n][m];
    for(int i = 0; i < m; i++){
        arr[0][i] = M[0][i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(M[i][j] != 0){
                arr[i][j] = arr[i - 1][j] + M[i][j];
            }else{
                arr[i][j] = 0;
            }
        }
    }
    int maxArea = INT_MIN;
    int area;
    for(int i = 0; i < n; i++){
        area = getMaxArea(arr[i], m);
        if(maxArea < area){
            maxArea = area;
        }
    }
    return maxArea;
}


int main(){

    return 0;
}
