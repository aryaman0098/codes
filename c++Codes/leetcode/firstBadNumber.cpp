//https://leetcode.com/problems/first-bad-version/

#include<bits/stdc++.h>

using namespace std;

//The function isBadVersion is already provided.


int binarySearch(int l, int r){
    if(l > r)
        return -1;
    
    int mid = l + (r - l) / 2;
    if(isBadVersion(mid) && !isBadVersion(mid - 1))
        return mid;
    else if(isBadVersion(mid) && isBadVersion(mid - 1))
        return binarySearch(l, mid - 1);
    else
        return binarySearch(mid + 1, r);
}

int firstBadVersion(int n) {
    return binarySearch(0, n);
}

int main(){

    return 0;
}
