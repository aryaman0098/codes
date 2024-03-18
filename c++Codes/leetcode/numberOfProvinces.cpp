//https://leetcode.com/problems/number-of-provinces/description/

#include<bits/stdc++.h>

using namespace std;

int findCircleNum(vector<vector<int>>& isConnected) {
  vector<bool> v(isConnected.size());
  stack<int> s;
  int numProvinces = 0;
  for(int i = 0; i < isConnected.size(); i++) {
      if(!v[i]) {
          numProvinces++;
          s.push(i);
          while(!s.empty()) {
              int currCity = s.top();
              v[currCity] = true;
              s.pop();
              for(int j = 0; j < isConnected[currCity].size(); j++) {
                  if(
                      isConnected[currCity][j] == 1 && 
                      !v[j]
                  ) {
                      s.push(j);
                  }
              }
          }
      }
  }
  return numProvinces;
}

int main(){

  return 0;
}
