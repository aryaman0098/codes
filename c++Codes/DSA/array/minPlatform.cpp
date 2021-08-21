//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int findPlatform(int arr[], int dep[], int n){
    sort(arr, arr + n);
    sort(dep, dep + n);
    int neededPlat = 0;
    int maxPlat = 0;
    int n1 = 0, n2 = 0;
    while(n1 < n && n2 < n){
        if (arr[n1] <= dep[n2]){
            neededPlat++;
            n1++;
        }else{
            neededPlat--;
            if(neededPlat < 0){
                neededPlat = 0;
            }
            n2++;
        }
        if(maxPlat < neededPlat){
            maxPlat = neededPlat;
        }
    }
    return maxPlat;
}

int main(){
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<findPlatform(arr, dep, 6);
}