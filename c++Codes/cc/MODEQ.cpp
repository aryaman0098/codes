#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        long count = 0;
        vector<long> x(N+1, 1);
        for(int a = 2; a <= N; a++){
            int k = M%a;
            count += x[k];
            for(int b = k; b <= N; b+=a){
                x[b]++;
            }
        }
        cout<<count<<"\n";
    }
