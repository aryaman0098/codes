//https://leetcode.com/problems/valid-triangle-number/

#include<bits/stdc++.h>

using namespace std;

int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int count = 0;
    int n = nums.size();
    int i, j, k;
    for(k = 2; k < n; k++){
        i = 0, j = k - 1;
        while(i < j){
            if(nums[i] + nums[j] > nums[k]){
                count += j - i;
                j--;
            }else{
                i++;
            }
        } 
    }
    return count;
}

int main(){

    return 0;
}
