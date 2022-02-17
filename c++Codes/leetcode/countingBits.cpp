//https://leetcode.com/problems/counting-bits/

#include<bits/stdc++.h>

using namespace std;

vector<int> countBits(int n) {
    vector<int> ans;
    ans.push_back(0);
    if(n == 0) return ans;
    ans.push_back(1);
    for(int i = 2; i <= n; i++){
        if(i % 2 == 0){
            ans.push_back(ans[int(i / 2)]);
        }else{
            ans.push_back(ans[int(i / 2)] + 1);
        }
    }   
    return ans;
}
int main(){
    return 0;
}
