//https://leetcode.com/problems/divisor-game/

#include<bits/stdc++.h>

using namespace std;

bool divisorGame(int n){
    if (n % 2 == 0){
        return true;
    }else{
        return false;
    } 
    //DP SOLUTION
    // if(n == 1){
    //     return false;
    // }if(n == 2){
    //     return true;
    // }else{
    //     if(u.find(n) == u.end()){
    //         u[n] = false;
    //         for(int i = 1; i <= n / 2; i++){
    //             if(n % i == 0){
    //                 u[n] |= !divisorGame(n - i);   
    //             }   
    //         }
    //     }
    //     return u[n];
    // }
}

