#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int N;
        cin>>N;
        long long int A[N], sum = 0;
        long long int a = sum, min = -1, index = 0;
        for(int i = 0; i<N; i++)
        {
            cin>>A[i];
            sum += A[i];
            a += sum; 
        }
        for(int i = 0; i<N; i++)
        {    
            if ((min < 0) || (min > (a+A[i])))
            {
                min = a+A[i];
                index = i;
            }
        }
        cout<<(index+1)<<endl;
    }
}

    
