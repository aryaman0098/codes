//https://leetcode.com/problems/sum-of-square-numbers/

#include<bits/stdc++.h>

using namespace std;

bool judgeSquareSum(int c) {
    int i = 0, j = sqrt(c);
    long long a, b;
    while(i <= j){
        a = pow(i , 2);
        b = pow(j, 2);
        if(a + b == c)
            return true;
        else if(a + b > c)
            j--;
        else
            i++;
    }    
    return false;
}

int main(){

    return 0;
}
