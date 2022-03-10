//https://leetcode.com/problems/reverse-vowels-of-a-string/

#include<bits/stdc++.h>

using namespace std;

bool isVowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string reverseVowels(string s) {
    int i = 0, j = s.length() - 1;
    while(i < j){
        while(i < s.length() && !isVowel(s[i]))
            i++;
        while(j > 0 && !isVowel(s[j]))
            j--;
        if(i == s.length() || j == - 1)
            break;
        if(i < j){
            swap(s[i++], s[j--]);
        }
    }
    return s;
}

int main(){

    return 0;
}
