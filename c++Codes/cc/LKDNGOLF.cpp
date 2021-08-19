#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int N,x,k;
    cin>>t;
    while(t--){
        cin>>N>>x>>k;
        if(x % k == 0){
            cout<<"YES\n";
        }else if((N + 1 - x) % k == 0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}