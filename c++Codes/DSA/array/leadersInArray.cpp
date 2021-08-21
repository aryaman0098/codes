//https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

#include<bits/stdc++.h>

using namespace std;

vector<int> leaders(int a[], int n){
    int highest = a[n - 1];
    vector<int> l;
    l.push_back(highest);
    for(int i = n -2; i >=0; i--){
        if(a[i] > highest){
            highest = a[i];
            l.push_back(highest);
        }
    }
}