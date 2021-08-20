//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int findPlatform(int arr[], int dep[], int n){
    unordered_map<int, int> m;
    vector< vector<int> > compTrains;
    vector<int> temp;
    int counter = 0; 
    temp.push_back(counter);
    m[counter] = 1;
    while(m.size() != n){
        for(int i = 1; i < n; i++){
            if(m.find(i) == m.end()){
                counter = i;
                if(temp.size() == 0){
                    temp.push_back(counter);
                }
                break;
            }
        }
        while(counter < n){
            if(dep[temp.size() - 1] < arr[counter] && m.find(counter) == m.end()){
                temp.push_back(counter);
                m[counter] = 1;
            }
            counter++;
        }
        compTrains.push_back(temp);
        temp.clear();
    }
    return compTrains.size();
}

int main(){
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<findPlatform(arr, dep, 6);
}