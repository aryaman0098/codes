#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, n, m, pos;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> soldiers(n, 0);
        vector<int> max(n, INT_MIN);
        while(m--){
            cin>>pos;
            soldiers[pos] = 0;
            for(int i = pos - 1; i >= 0; i--){
                soldiers[i] = soldiers[i + 1] + 1;
                if(max[pos] < soldiers[pos]) max[pos] = soldiers[pos]; 
            }
            for(int i = pos + 1; i < n; i++){
                soldiers[i] = soldiers[i - 1] + 1;
                if(max[pos] < soldiers[pos]) max[pos] = soldiers[pos]; 
            }
        }
        for(auto m : max)
            cout<<m<<" ";
        cout<<"\n";
    }
    return 0;
}
