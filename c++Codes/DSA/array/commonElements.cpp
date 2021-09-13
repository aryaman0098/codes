//https://practice.geeksforgeeks.org/problems/common-elements1132/1

#include<bits/stdc++.h>

using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3){
    unordered_map<int, int> u2;
    unordered_map<int, int> u3;
    unordered_map<int, int> counted;
    vector<int> ans;
    for(int i = 0; i < n2; i++){
        u2[B[i]] = 1;
    }
    for(int i = 0; i < n3; i++){
        u3[C[i]] = 1;
    }
    for(int i = 0; i < n1; i++){
        if(u2.find(A[i]) != u2.end() && u3.find(A[i]) != u3.end() && counted.find(A[i]) == counted.end()){
            ans.push_back(A[i]);
            counted[A[i]] = 1;
        }
    }
    if(ans.size() == 0){
        ans.push_back(-1);
        return ans;
    }
    
    return ans;
}

int main(){

    return 0;
}
