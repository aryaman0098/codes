//www.geeksforgeeks.org/count-number-triplets-product-equal-given-number/

#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int numTriplets(int arr[], int n, int m){
    unordered_map<int, int> u;
    for(int i = 0; i < n; i++){
        u[arr[i]] = i;
    }
    int count = 0;
    int x;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if((arr[j] * arr[j]) != 0 && (m % (arr[i] * arr[j])) == 0){
                int x = m / (arr[i] * arr[j]);
                if(u.find(x) != u.end() && x != arr[i] && x != arr[j] && u[x] > i && u[x] > j){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<x<<"\n";
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    int arr[] = {0,4,6,2,3,8};
    cout<<numTriplets(arr, 6, 18);
    return 0;
}
