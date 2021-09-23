//https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/

#include<bits/stdc++.h>

using namespace std;

vector<int> commomElements(vector<vector<int> >M){
    unordered_map<int, int> m;
    for(int i = 0; i < M[0].size(); i++){
        m[M[0][i]] = 1;
    }
    for(int i = 1; i < M.size(); i++){
        for(int j = 0; j < M[0].size(); j++){
            if(m[M[i][j]] == i){
                m[M[i][j]] = i + 1;
            }
        }
    }
    vector<int> ans;
    for(auto i = m.begin(); i != m.end(); i++){
        if(i->second == M.size()){
            ans.push_back(i->first);
        }
    }
    return ans;
}

int main(){
    vector<int> ans;
    vector<vector<int> > M;
    vector<int> temp;
    int n, m, x;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>x;
            temp.push_back(x);
        }
        M.push_back(temp);
        temp.clear();
    }
    ans = commomElements(M);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
