//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include<bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2){
        return n;
    }
    int l = 0, count = 1;
    int c;
    for(int i = 0; i < n;){
        c = nums[i];
        i++;
        while(i < n && c == nums[i]){
            count++;
            i++;
        }
        if(count == 1)
            nums[l++] = c;
        else{
            nums[l++] = c;
            nums[l++] = c;
        }
        count = 1;
    }
    return l;
}

int main(){

    return 0;
}
