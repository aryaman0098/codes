//https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include<bits/stdc++.h>

using namespace std;

int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> u;
    int n = nums.size();
    int counter = 0;
    for(auto m : nums)
        u[k + m]++;
    if(k == 0){
        for(auto m : u){
            if(m.second > 1)
                counter++;
        }
        return counter;
    }
    for(auto m : nums){
        if(u.find(m) != u.end() && u[m] != - 1){
            counter++;
            u[m] = -1;
        }
    }    
    return counter;
}

int main(){

    return 0;
}
