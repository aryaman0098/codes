#include<bits/stdc++.h>

using namespace std;

int binarySearch(
  vector<int> v, 
  int ele, 
  int l, 
  int r
) {
  int mid = (l + r) / 2;
  if(v[mid] == ele) return mid;
  else if(v[mid] < ele) return binarySearch(v, ele, mid + 1, r);
  else return binarySearch(v, ele, l, mid - 1);
}

int main(){
  vector v = {1,2,3,4,5,6,7,8,9};
  for(int i = 1; i <= 9; i++) {
    cout<<binarySearch(v, i, 0, 8)<<endl;;
  }
  return 0;
}
