//https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

#include<bits/stdc++.h>

using namespace std;

bool areRotations(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }
    queue<char> q1, q2;
    int n = s1.length();
    for(int i = 0; i < n; i++){
        q1.push(s1[i]);
        q2.push(s2[i]);
    }
    char c;
    while(n--){
        c = q2.front();
        q2.pop();
        q2.push(c);
        if(q1 == q2){
            return true;
        }
    }
    return false;
}

int main(){

    string s1 = "abcd";
    string s2 = "cdba";
    cout<<areRotations(s1, s2);
    return 0;
}
