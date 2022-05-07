//https://leetcode.com/problems/plus-one/

#include<bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for(int i = n - 1; i >= 0 ; i--){
        if(digits[i] == 9)
            digits[i] = 0;
        else{
            digits[i]++;
            return digits;
        }
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

int main(){

    vector<int> num;
    num.push_back(2);
    num.push_back(1);
    num.push_back(9);
    num.push_back(8);
    vector<int> ans = plusOne(num);
    for(auto m : ans)
        cout<<m<<" ";
    return 0;
}
