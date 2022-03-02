//https://leetcode.com/problems/search-a-2d-matrix/

#include<bits/stdc++.h>

using namespace std;

int binarySearch(int l, int r, vector<int> nums, int target){
    if(l > r)
        return -1;

    int mid = (l + r) / 2;
    if(nums[mid] == target)
        return mid;
    else if(nums[mid] > target)
        return binarySearch(l, mid - 1, nums, target);
    else
        return binarySearch(mid + 1, r, nums, target);
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0; i < m; i++){
        if(matrix[i][0] <= target && target <= matrix[i][n - 1]){
            (binarySearch(0, n - 1, matrix[i], target) == -1) ? false : true;
        }
    }
    return false;
}

int main(){

    return 0;
}
