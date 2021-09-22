//https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

#include<bits/stdc++.h>

using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m){
    if(m == 1){
        int i = 0;
        while(i < n){
            if(arr[i][0] == 1){
                return i;
            }
            i++;
        }
        return - 1;
    }
    int ans = -1;
    int maxOnes = 0;
    int currOnes = 0;
    int i = 0, j = m - 1;
    while(i < n){
        for(int x = j; x >= 0; i--){
            if(arr[i][x] == 0){
                j = x;
                break;
            }else if(arr[i][x] == 1){
                if(x == 0){
                    return i;
                }
                currOnes++;
            }
            if(maxOnes < currOnes){
                maxOnes = currOnes;
                ans = i;
            }
        }
        i++;
    }
    return ans;
}

int main(){

    return 0;
}
