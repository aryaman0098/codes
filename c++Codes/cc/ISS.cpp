#include<bits/stdc++.h>

using namespace std;

int gcd(int x, int y){
    if(y == 0){
        return x;
    }
    return gcd(y, x % y);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int k;
    int sum;
    while(t--){
        cin>>k;
        sum = 0;
        for(int i = 1; i <= 2*k; i++){
            sum += gcd(k + i*i, k + (i + 1)*(i + 1));
        }
        cout<<sum<<"\n";
    }
}