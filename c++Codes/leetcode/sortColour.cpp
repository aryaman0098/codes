//https://leetcode.com/problems/sort-colors/

#include<bits/stdc++.h>

using namespace std;

void sortColors(vector<int>& nums) {
    int z = 0, o = 0, t= 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] == 0)
            z++;
        else if(nums[i] == 1)
            o++;
        else
            t++;
    }   
    int counter = 0;
    while(z--){
        nums[counter] = 0;
        counter++;
    }
    while(o--){
        nums[counter] = 1;
        counter++;
    }
    while(t--){
        nums[counter] = 2;
        counter++;
    }
}

int main(){

    return 0;
}
