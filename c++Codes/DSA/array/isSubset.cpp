//https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

#include<bits/stdc++.h>

using namespace std;

string isSubset(int a1[], int a2[], int n, int m){
    unordered_map<int, int> u;
    for(int i = 0; i < n; i++){
        u[a1[i]]++;
    }
    for(int i = 0; i < m; i++){
        if(u.find(a2[i]) == u.end()){
            return "No";
        }
        u[a2[i]]--;
    }
    for(auto i = u.begin(); i != u.end(); i++){
        if(i->second < 0){
            return "No";
        }
    }
    return "Yes";
}

int main(){
    
    return 0;
}
