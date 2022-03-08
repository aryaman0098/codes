//https://leetcode.com/problems/string-compression/

#include<bits/stdc++.h>

using namespace std;

int compress(vector<char>& chars) {
    int l = 0;
    int counter = 0;
    int n = chars.size();
    char c;
    string str;
    for(int i = 0; i < n; i++){
        c = chars[i];
        while(i < n && chars[i] == c){
            counter++;
            i++;
        }
        i--;
        chars[l++] = c;
        if(counter > 1){
            str = to_string(counter);
            for(auto ch : str)
                chars[l++] = ch;
        }
        counter = 0;
    }
    return l;
}

int main(){
    
}
