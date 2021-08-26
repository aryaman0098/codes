//https://practice.geeksforgeeks.org/problems/finger-game1755/1

#include<bits/stdc++.h>

using namespace std;

int fingerCount(int N){
    if((N - 1) % 8 == 0){
        return 1;
    }else if((N - 5) % 8 == 0){
        return 5;
    }else if((N - 3) % 4 == 0){
        return 3;
    }else if(N % 8 == 2 || N % 8 == 0){
        return 2;
    }else{
        return 4;
    }
}

int main(){
    for(int i = 1; i < 31; i++){
        cout<<i<<" "<<fingerCount(i)<<"\n";
    }
}