//https://leetcode.com/problems/single-number-ii/
#include<bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums){
    unordered_map<int, int> u;
    int ans = 0;
    for(auto c : nums){
        u[c]++;
        if(u[c] == 3)
            continue;
        ans ^= c;
    }
    return ans;
}

int main(){

    return 0;
}
