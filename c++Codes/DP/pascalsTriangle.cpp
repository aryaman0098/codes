//https://leetcode.com/problems/pascals-triangle/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ans;
    vector<int> temp1, temp2;
    temp1.push_back(1);
    temp2.push_back(1);
    temp2.push_back(1);
    ans.push_back(temp1);
    if(numRows == 1) return ans;
    ans.push_back(temp2);
    if(numRows == 2) return ans;
    for(int i = 2; i <= numRows - 1; i++){
        vector<int> temp;
        temp.push_back(1);
        for(int j = 1; j < i; j++){
            temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
        temp.push_back(1);
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    vector<vector<int> > ans;
    ans = generate(5);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j <= i; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
