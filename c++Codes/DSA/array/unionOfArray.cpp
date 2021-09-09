#include<bits/stdc++.h>

using namespace std;

int doUnion(int a[], int n, int b[], int m){
    unordered_map<int, int> m1;
    for(int i = 0; i < n; i++){
        m1[a[i]] = 1;
    }
    for(int i = 0; i < m; i++){
        m1[b[i]] = 1;
    }
}

int doIntersection(int a[], int n, int b[], int m){
    unordered_map<int, int>m1;
    vector<int> intersect;
    for(int i = 0; i < n; i++){
        m1[a[i]] = 1;
    }
    for(int i = 0; i < m; i++){
        if(m1.find(b[i]) != m1.end()){
            intersect.push_back(b[i]);
        }
    }
    return intersect.size();
}

int main(){
    int a[] = {1,2,3,4,5};
    int b[] = {4,5,10,11};
    int m = doIntersection(a, 5, b, 4);
    cout<<m;
}