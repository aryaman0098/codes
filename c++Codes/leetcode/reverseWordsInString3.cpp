//https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include<bits/stdc++.h>

using namespace std;

void swap(char* x, char* y){
    char t = *x;
    *x = *y;
    *y = t;
}

string reverseWords(string s) {
    int l, r;
    int counter = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' ')
            counter++;
        else{
            r = i - 1;
            l = i - counter;
            while(l < r){
                swap(&s[l], &s[r]);
                l++;
                r--;
            }
            counter = 0;
        }
    }
    r = s.length() - 1;
    l = s.length() - counter;
    while(l < r){
        swap(&s[l], &s[r]);
        l++;
        r--;
    }    
    return s;
}

int main(){
    cout<<reverseWords("Let's take LeetCode contest");
    return 0;
}
