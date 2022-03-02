//https://practice.geeksforgeeks.org/problems/2ac2f925b836b0625d848a0539ffd3d2d2995f92/1

#include<bits/stdc++.h>

using namespace std;

long long countStrings(string S){
    vector<long long> a(26, 0);
    long long ans = 0;
    for(int i = 0; i < S.length(); i++){
        a[S[i] - 'a'] += 1;
        if(a[S[i] - 'a'] > 1)
            ans = 1;
    }
    for(int i = 0; i < 25; i++){
        if(a[i] > 0){
            for(int j = i + 1; j < 26; j++){
                if(a[j] > 0)
                    ans += a[i] * a[j];
            }
        }
    }
    return ans;
}

int main(){

    return 0;
}
