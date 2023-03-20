//https://leetcode.com/problems/set-matrix-zeroes/

#include<bits/stdc++.h>

using namespace std;

struct hashFunction
{
  size_t operator()(const pair<int , int> &x) const {
    return x.first ^ x.second;
  }
};

void setZeroes(vector<vector<int>>& matrix) {
  int isFirstColZero = false;
  int rows = matrix.size();
  int cols = matrix[0].size();
  for(int i = 0; i < rows; i++) {
    if(matrix[i][0] == 0) {
      isFirstColZero = true;
    }
    for(int j = 1; j < cols; j++) {
      if(matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j]= 0;
      }
    }
  }
  for(int i = 1; i < rows; i++) {
    for(int j = 1; j < cols; j++) {
      if(matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  if(matrix[0][0] == 0) {
    for(int j = 0; j < cols; j++) {
      matrix[0][j] = 0;
    }
  }
  if(isFirstColZero) {
    for(int i = 0; i < rows; i++) {
      matrix[i][0] = 0;
    }
  }
}


int main() {

  return 0;
}