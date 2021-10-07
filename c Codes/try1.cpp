#include<bits/stdc++.h>

using namespace std;

string reverse(string s){
    int len = s.length();
    for(int i = 0; i < len / 2; i++){
        swap(s[i], s[len - i - 1]);
    }
    return s;
}

int main(){
    string s = "Hello World";
    cout<<reverse(s)<<endl;
}