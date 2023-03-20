// /https://leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascalsTriangle;
    
    if(numRows >= 1) {
        pascalsTriangle.push_back({1});
    }

    if(numRows >= 2) {
        pascalsTriangle.push_back({1,1});
    }

    int n = 3;
    vector<int> nthRow;
    while(n <= numRows) {
        nthRow.push_back(1);
        for(int i = 0; i < pascalsTriangle[n - 2].size() - 1; i++) {
            nthRow.push_back(pascalsTriangle[n - 2][i] + pascalsTriangle[n - 2][i + 1]);
        }
        nthRow.push_back(1);
        pascalsTriangle.push_back(nthRow);
        nthRow.clear();
        n++;
    }

    return pascalsTriangle;
}

int main() {

    return 0;
}