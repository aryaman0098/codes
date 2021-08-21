#include<bits/stdc++.h>

using namespace std;

tuple<int, int> maxMinInArray(int a[], int n){
    int max = a[0];
    int min = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }else if(a[i] < min){
            min = a[i];
        }
    }
    return make_tuple(min, max);
}

int main(){
    int a[] = {2,4,1,6,2,1,9,4,2,5};
    int min, max;
    tie(min, max) = maxMinInArray(a, 10);
    cout<<min<<" "<<max;

}