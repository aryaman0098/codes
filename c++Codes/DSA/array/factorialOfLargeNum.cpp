//https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

#include<bits/stdc++.h>

using namespace std;

vector<int> factorial(int N){
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < ans.size(); j++){
            int product = ans[j] * i + carry;
            ans[j] = product % 10;
            carry = product / 10; 
        }
        while(carry > 0){
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    return 0;
}
