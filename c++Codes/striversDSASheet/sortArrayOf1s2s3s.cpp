//https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y) {
  int temp = &x;
  *x = *y;
  *y = temp;
}


void sortColors(vector<int>& nums) {
    int n = nums.size();

    int low = 0, mid = 0, high = n - 1;

    while(mid <= high) {

      if(nums[mid] == 0) {
        swap(*nums[low], *nums[mid]);
        low++;
        mid++;
      } else if(nums[mid] == 1) {
        mid++;
      } else {
        swap(*nums[mid], *nums[high]);
        high--;
      }
    }
}

int main() {

  return 0;
}