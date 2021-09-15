//https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

#include<bits/stdc++.h>

using namespace std;

 int findLongestConseqSubseq(int arr[], int N){
    map<int, int> m;
    int count = 0;
    int max = INT_MIN;
    for(int i = 0; i < N; i++){
        m[arr[i]]++;
    }
    int previous = m.begin()->first;
    for(auto i = m.begin(); i != m.end(); i++){
        if(previous == i->first){
            continue;
        }
        else if(i->first - previous == 1){
            count++;
        }else{
            if(count > max){
                max = count;
            }
            count = 0;
        }
        previous = i->first;
    }
    if(count > max){
        max = count;
    }
    return (max == INT_MIN) ? 1 : max;
 }

int main(){

    return 0;
}
