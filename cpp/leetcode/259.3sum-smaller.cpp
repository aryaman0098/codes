#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      int sum = 0;
      function<int(int)> count = [&](int i) {
        int t = target - nums[i], j = i + 1, k = n - 1, sum = 0;
        while(j < k) {
          if(nums[j] + nums[k] < t) { 
            sum += k - j;
            j++;
          } else {
            k--;
          }
        }
        return sum; 
      };       
      for(int i = 0; i < n; i++) {
        sum += count(i);
      }
      return sum;
    }
};