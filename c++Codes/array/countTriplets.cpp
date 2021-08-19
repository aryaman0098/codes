#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int countTriplets(int arr[], int n){
    sort(arr, arr + n);
    unordered_map<int, int> ump;
    int count = 0;
    for(int i = 0; i < n; i++){
        ump[arr[i]] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(ump.find(arr[i] + arr[j]) != ump.end()){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<countTriplets(arr, n);
}