#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<set<int>> p;
    queue<int> q;
    for(int i = 0; i <n; i++){
        p.push_back({ });
        q.push(i);
    }   
    while(!q.empty()){
        int source = q.front();
        q.pop();
        
    }
}

int main(){

    return 0;
}
