#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i;
    for(i = n - 1; i > 0; i--) {
        if(nums[i] > nums[i - 1]) {
            int valToReplace = nums[i - 1];
            int valToReplaceWith = nums[i];
            int index = i;
            for(int k = n - 1; k >= i; k--) {
                if( nums[k] > valToReplace && nums[k] < valToReplaceWith) {
                    valToReplaceWith = nums[k];
                    index = k;
                }
            }
            swap(&nums[i - 1], &nums[index]);
            break;
        }
    }  
    sort(nums.begin() + i, nums.end());
}

int main() {

    return 0;
}