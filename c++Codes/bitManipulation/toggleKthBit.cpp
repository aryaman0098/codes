//https://www.geeksforgeeks.org/toggling-k-th-bit-number/

#include<bits/stdc++.h>

using namespace std;

int toggleKthBit(int n, int k){
    int temp = 1 << (k - 1);
    return n ^ temp;
}

int main(){

    cout<<toggleKthBit(42, 6);
    return 0;
}
