//https://leetcode.com/problems/next-permutation/

#include<bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums){
    int flag2 = 0;
    for(int k  = 0; k < nums.size() - 1; k++){
        if(nums[k] < nums[k + 1]){
            flag2 = 1;
            break;
        }
    }

    if(flag2 == 0){
        sort(nums.begin(), nums.end());
        return;
    }

    int i = nums.size() - 1;
    int min;
    int index;
    int flag = 0;
    for(; i >= 0; i--){
        if(nums[i] > nums[i  - 1]){
            i -= 1;
            for(int j = nums.size() - 1; j > i; j--){
                if(flag == 0){
                    if(nums[j] > nums[i]){
                        min = nums[j];
                        index = j;
                        flag = 1;
                    }
                }else{
                    if(nums[j] < min && nums[j] > nums[i]){
                        index = j;
                    }
                }
            }
            swap(nums[i], nums[index]);
            break;
        }
    }
    sort(nums.begin() + i + 1, nums.end());
}
int main(){
    vector<int> nums;
    int x;
    for(int i = 0; i < 3; i++){
        cin>>x;
        nums.push_back(x);
    }
    nextPermutation(nums);
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
