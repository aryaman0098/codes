//https://leetcode.com/problems/container-with-most-water/

#include<bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height){
    int h1, h2, x1, x2;
    h1 = height[0];
    h2 = height[height.size() - 1];
    x1 = 0;
    x2 = height.size() - 1;
    int maxArea = (h1 > h2 ? h2 : h1) * (x2 - x1);
    int area;
    while(x1 < x2){
        if(h1 < h2){
            x1++;
            h1 = height[x1];
        }else{
            x2--;
            h2 = height[x2];
        }
        area = (h1 > h2 ? h2 : h1) * (x2 - x1);
        if(area > maxArea){
            maxArea = area;
        }
    }
    return maxArea;
}

int main(){
    vector<int> height;
    int temp, n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>temp;
        height.push_back(temp);
    }
    cout<<maxArea(height);
}   