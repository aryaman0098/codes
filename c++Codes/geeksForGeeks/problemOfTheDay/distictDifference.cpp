#include <bits/stdc++.h>

using namespace std;

vector<int> getDistinctDifference(int N, vector<int> &A) {
    map<int , int> leftMap, rightMap;
    for(int i = 0; i < N; i++) {
        rightMap[A[i]]++;
    }    
    vector<int> ans;
    for(int i = 0; i < N; i++) {
        rightMap[A[i]]--;
        if(rightMap[A[i]] == 0) {
            rightMap.erase(A[i]);
        }
        ans.push_back(leftMap.size() - rightMap.size());
        leftMap[A[i]]++;
    }
    return ans;
}

int main() {

    return 0;
}