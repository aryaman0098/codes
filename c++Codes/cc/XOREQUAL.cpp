#include<bits/stdc++.h>

using namespace std;

int power(long long x, unsigned int y, int p)
{
    int res = 1;
    x = x % p; 
    if (x == 0){
        return 0;
    } 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long int M = 1000000007;
    unsigned long long int t;
    unsigned long long int N;
    cin>>t;
    while(t--){
        cin>>N;
        cout<<power(2, N - 1, M)<<"\n";
    }
}
