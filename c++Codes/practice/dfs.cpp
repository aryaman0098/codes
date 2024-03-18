#include<bits/stdc++.h>

using namespace std;

vector<int> breadthFirstSearch(vector<vector<int>> al) {
  vector<int> v;
  stack<int> q;
  q.push(0);
  while(!q.empty()) {
    int currNode = q.top();
    q.pop();    
    if(count(v.begin(), v.end(), currNode) == 0) {
      v.push_back(currNode);
      for(int i = al[currNode].size() - 1; i >=0; i--) {
        q.push(al[currNode][i]);
      }
    }
  }
  return v;
}

int main(){
  vector<vector<int>> adjacencyList;
  adjacencyList.push_back(vector<int>{2, 3, 1});
  adjacencyList.push_back(vector<int>{0});
  adjacencyList.push_back(vector<int>{0, 4});
  adjacencyList.push_back(vector<int>{0});
  adjacencyList.push_back(vector<int>{2});

  vector<int> dfs = breadthFirstSearch(adjacencyList);

  for(auto c: dfs) {
    cout<<c<<" ";
  }
  cout<<endl;
  return 0;
}
