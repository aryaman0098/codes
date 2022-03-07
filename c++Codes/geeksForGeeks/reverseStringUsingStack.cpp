//https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1

#include<bits/stdc++.h>

using namespace std;

char* reverse(char *S, int len){
    stack<char> s;
    for(int i = 0; i < len; i++)
        s.push(S[i]);
    int counter = 0;
    while(!s.empty()){
        S[counter] = s.top();
        s.pop();
        counter++;
    }
    S[counter] = '\0';
    return S;
}

int main(){

    return 0;
}
