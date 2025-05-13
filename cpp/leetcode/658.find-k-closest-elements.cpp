/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        if(x < arr[0]) for(int i = 0; i < min(k, n); i++) ans.push_back(arr[i]);
        else if(x > arr[arr.size() - 1]) for(int i = n - 1; i >= max(n - k, 0); i--) ans.insert(ans.begin(), arr[i]);
        else {
            int l, r;
            for(int i = 0; i < n; i++) {
                if(arr[i] == x || (i < n - 1 && arr[i] < x && x < arr[i + 1] )) {
                    l = i;
                    r = i + 1;
                }
            }
            while(ans.size() < k) {
                if(l < 0 || (r < n && arr[r] - x < x - arr[l])) {
                    ans.push_back(arr[r]);
                    r++;
                } else if(r >= n || (l >=0 && x - arr[l] <= arr[r] - x)) {
                    ans.insert(ans.begin(), arr[l]);
                    l--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

