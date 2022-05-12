//https://leetcode.com/problems/integer-replacement/

#include<bits/stdc++.h>

using namespace std;

unordered_map<int, int> u;

int integerReplacement(int n) {
    if(n == INT_MAX)
        return 32;
    if(n == 1)
        return 0;
    else if(n == 2)
        return 1;
    else{
        if(u.find(n) == u.end()){
            if(n % 2 == 0){
                u[n] =  1 + integerReplacement(n / 2);              
        }
            else{
                u[n] = 1 + min(
                    integerReplacement(n - 1), 
                    integerReplacement(n + 1)
                );
            }
        }
        return u[n];
    }
}

int main(){

    return 0;
}
