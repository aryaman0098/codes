#include<bits/stdc++.h>

using namespace std;

int minMovesToMakePalindrome(string s) {
    int count = 0;
    int n = s.length();
    for(int i = 0 ; i < n / 2; i++){
        int l = i;
        int r = n - i - 1;
        while(l < r){
            if(s[l] == s[r])
                break;
            r--;
        }
        for(int j = r; j < n - i - 1; j++){
            swap(s[j], s[j + 1]);
            count++;
        }
    }
    return count;
}

int main(){

    return 0;
}
