//https://leetcode.com/problems/reverse-string/

#include<bits/stdc++.h>

using namespace std;

void swap(char* x, char* y){
    char t = *x;
    *x = *y;
    *y = t;
}

void reverseString(vector<char>& s) {
    int l = 0, r = s.size() - 1;
    while(l < r){
        swap(&s[l], &s[r]);
        l++;
        r--;
    }
}

int main(){

    return 0;
}
