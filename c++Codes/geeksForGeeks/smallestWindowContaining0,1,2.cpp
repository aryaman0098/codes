//https://practice.geeksforgeeks.org/problems/d6e88f06b273a60ae83992314ac514f71841a27d/1

#include<bits/stdc++.h>

using namespace std;

int smallestSubstring(string S) {
    unordered_map<char, int> u;
    int l = 0, r = 0;
    int min = INT_MAX;
    int temp;
    u['0'] = 0;
    u['1'] = 0;
    u['2'] = 0;
    while(r <= S.length()){
        if(u['0'] != 0 && u['1'] != 0 && u['2'] != 0){
            temp = u['0'] + u['1'] + u['2'];
            if(temp < min) 
                min = temp;
            u[S[l]]--;
            l++;
            continue;
        }    
        u[S[r]]++;
        r++;
    }
    return (min == INT_MAX) ? -1 : min;
}

int main(){

    return 0;
}
