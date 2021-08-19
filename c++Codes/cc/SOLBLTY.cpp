#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int X,A,B;
    int ans;
    while(t--){
        cin>>X>>A>>B;
        ans = 10*(A + (100 - X)*B);
        cout<<ans<<"\n";
    }
}