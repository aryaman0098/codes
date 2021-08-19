#include<bits/stdc++.h>

using namespace std;

int minimun =  - pow(2, 31);
int maximum = pow(2, 31) - 1;

bool checkRange(long n){
    if(minimun <= n && n <= maximum){
        return true;
    }else{
        return false;
    }
}

int numReverse(int x){
    int flag = 0;
    if (x < 0){
        x = abs(x);
        flag = 1;
    }
    long reverse = 0;
    while(x > 0){
        reverse = reverse * 10 + x %10;
        x /= 10;
    }
    if(flag == 1){
        reverse = -reverse;
    }
    bool check = checkRange(reverse);
    if(check){
        return reverse;
    }else{
        return 0;
    }
}

int main(){
    cout<<numReverse(153423469)<<"\n";
}