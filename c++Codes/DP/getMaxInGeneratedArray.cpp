//https://leetcode.com/problems/get-maximum-in-generated-array/

#include<bits/stdc++.h>

using namespace std;

int getMaximumGenerated(int n) {
    vector<int> nums;
    if (n == 0) return 0;
    nums.push_back(0);
    nums.push_back(1);
    int max = 1;
    for(int i = 2; i <= n; i++){
        if(i % 2 == 0){
            nums.push_back(nums[i / 2]);
            if(max < nums[i]) max = nums[i];
        }else{
            int x = (int)(i / 2);
            nums.push_back(nums[x] + nums[x + 1]);
            if(max < nums[i]) max = nums[i];
        }
    }
    return max; 
}

int main(){
    return 0;
}
