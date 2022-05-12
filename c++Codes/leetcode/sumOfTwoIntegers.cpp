//https://leetcode.com/problems/sum-of-two-integers/

#include<bits/stdc++.h>

using namespace std;

int getSum(int a, int b){
    unsigned carry;
    while(b != 0){
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }    
    return a;
}

int main(){

    return 0;
}
