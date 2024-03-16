#include<bits/stdc++.h>

using namespace std;

vector<int> breadthFirstSearch(vector<vector<int>> al) {
  vector<int> v;
  queue<int> q;
  q.push(0);
  while(!q.empty()) {
    int currNode = q.front();
    q.pop();    
    if(count(v.begin(), v.end(), currNode) == 0) {
      v.push_back(currNode);
      for(auto c: al[currNode]) {
        q.push(c);
      }
    }
  }
  return v;
}

int main(){
  vector<vector<int>> adjacencyList;
  adjacencyList.push_back(vector<int>({1, 2}));
  adjacencyList.push_back(vector<int>({0, 2, 3}));
  adjacencyList.push_back(vector<int>({0, 1, 4}));
  adjacencyList.push_back(vector<int>({1, 4}));
  adjacencyList.push_back(vector<int>({2, 3}));

  vector<int> bfs = breadthFirstSearch(adjacencyList);

  for(auto c: bfs) {
    cout<<c<<" ";
  }
  cout<<endl;
  return 0;
}

//   1-3
//  /| |
// 0 | |
//  \| |
//   2-4 