//https://leetcode.com/problems/climbing-stairs/submissions/

#include<bits/stdc++.h>

using namespace std;

unordered_map<int, int> u;

int climbStairs(int n){
    if(n == 1){
        return 1;
    }else if(n == 2){
        return 2;
    }else{
        if(u.find(n) == u.end()){
            u[n] = climbStairs(n - 1) + climbStairs(n - 2);
        }
        return u[n];
    }
}

int main(){
    cout<<climbStairs(3)<<"\n";
    return 0;
}
