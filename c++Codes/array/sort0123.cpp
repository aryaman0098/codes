#include<bits/stdc++.h>

using namespace std;

tuple<int, int, int> sort123(int a[], int n){
    int zeros = 0, ones = 0, twos = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            zeros++;
        }else if(a[i] == 1){
            ones++;
        }else if(a[i] == 2){
            twos++;
        }
    }
    return make_tuple(zeros, ones, twos);
}

int main(){
    int a[] = {0, 2, 1, 2, 0};
    int zeros, ones, twos;
    tie(zeros, ones, twos) = sort123(a, 5);

    int* b = new int[5];
    
    int i = 0;
    
    for(int k = 1; k <= zeros; k++){
        b[i] = 0;
        i++;
    }
    for(int k = 1; k <= ones; k++){
        b[i] = 1;
        i++;
    }
    for(int k = 1; k <= twos; k++){
        b[i] = 2;
        i++;
    }

    for(int i = 0; i < 5; i++){
        cout<<b[i]<<" ";
    }
}