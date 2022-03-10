//https://leetcode.com/problems/string-to-integer-atoi/

#include<bits/stdc++.h>

using namespace std;

int myAtoi(string s) {
    int l, counter = 0;
    int flag = 0;
    while(s[counter] == ' ')
        counter++;
    if(s[counter] == '-'){
        flag = 1;
        l = counter + 1;
    }else if(s[counter] == '+' || (48 <= int(s[counter]) && int(s[counter]) <= 57))
        l = (s[counter] == '+') ? counter + 1 : counter;
    else
        return 0;
    counter = l;
    while(counter <= s.length() - 1 && 
            (48 <= int(s[counter]) && int(s[counter]) <= 57)){
        counter++;
    }
    if(counter == l) return 0;
    s = s.substr(l, counter - l);
    int n = s.length() - 1;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(INT_MIN > ans + (s[i] - '0') * pow(10, n - i) || 
            INT_MAX < ans + (s[i] - '0') * pow(10, n - i)){
            return (flag == 1) ? INT_MIN : INT_MAX;
        }
        ans += (s[i] - '0') * pow(10, n - i);
    }
    return (flag == 1) ? -ans : ans;
}

int main(){
    cout<<myAtoi("    130232123   ")<<"\n";
    return 0;
}
