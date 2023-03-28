//https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int counter1 = 0, counter2 = 0, firstVecElements = 0;
    while(counter2 < n) {
        if(firstVecElements >= m) {
            nums1[counter1] = nums2[counter2];
            counter1++;
            counter2++;
        } else{
            if(nums1[counter1] <= nums2[counter2]) {
                firstVecElements++;
                counter1++;
            } else {
                nums1.insert(nums1.begin() + counter1, nums2[counter2]);
                counter1++;
                counter2++;
            }
        }
    }
    int counter3 = nums1.size() - 1;
    while(nums1.size() != m + n) {
        nums1.erase(nums1.begin() + counter3);
        counter3--;
    }
}

int main() {

}