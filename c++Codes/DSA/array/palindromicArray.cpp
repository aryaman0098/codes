//https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1

#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(int n){
    string s = to_string(n);
    int m = s.length();
    for(int i = 0; i < m / 2; i++){
        if(s[i] != s[m - i - 1]){
            return false;
        }
    }
    return true;
}

int PalinArray(int a[], int n){
    for(int i = 0; i < n; i++){
        if(!isPalindrome(a[i])){
            return 0;
        }
    }
    return 1;
}

int main(){

    return 0;
}
