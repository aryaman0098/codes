//https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1

#include<bits/stdc++.h>

using namespace std;

string longestPalin (string S){
    int start = 0, end = 1;
    int l, h;
    for(int i = 0; i < S.length(); i++){
        
        //Checking for even length of characters
        l = i;
        h = i + 1;
        while(l >= 0 && h < S.length() && S[l] == S[h]){
            if(h - l + 1 > end){
                start = l;
                end = h - l + 1;
            }
            l--;
            h++;
        }

        //Checking for odd length of characters
        l = i;
        h = i + 2;
        while(l >= 0 && h < S.length() && S[l] == S[h]){
            if(h - l + 1 > end){
                start = l;
                end = h - l + 1;
            }
            l--;
            h++;
        }
    } 
    string ans = "";
    for(int i = 0; i < start + end - 1; i++){
        ans += S[i];
    }
    return ans;
}


int main(){

    return 0;
}
