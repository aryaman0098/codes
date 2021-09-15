//https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

#include<bits/stdc++.h>

using namespace std;

vector<int> moreThanNbyK(int arr[], int n, int k){
    int x = n / k;
    map<int, int> m;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        m[arr[i]]++;
    }
    for(auto i = m.begin(); i != m.end(); i++){
        if(i->second > x){
            ans.push_back(i->first);
        }
    }
    return ans;
}


int main(){
    int arr[] = {3,1,2,2,2,1,4,3,3};
    vector<int> ans;
    ans = moreThanNbyK(arr, 9, 4);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
