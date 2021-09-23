//https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

#include<bits/stdc++.h>

using namespace std;

int isPalindrome(string S){
    int n = S.length();
    for(int i = 0; i < n / 2; i++){
        if(S[i] != S[n - i - 1]){
            return 0;
        }
    }
    return 1;
}

int main(){

    return 0;
}
