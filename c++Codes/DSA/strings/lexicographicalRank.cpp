//www.geeksforgeeks.org/lexicographic-rank-of-a-string/

#include<bits/stdc++.h>

using namespace std;

int fact(int n){
    return (n <= 1) ? 1 : n * fact(n - 1);
}

int findMinRight(string str, int low, int high){
    int countRight = 0;
    for(int i = low + 1; i <= high; i++){
        if(str[i] < str[low]){
            countRight++;
        }
    }
    return countRight;
}

int lexicorgraphicRank(string str){
    int rank = 0;
    int minRight;
    for(int i = 0; i < str.length(); i++){
        minRight = findMinRight(str, i, str.length() - 1);
        rank += minRight * fact(str.length() - i - 1);
    }
    return (rank + 1);
}

int main(){

    cout<<lexicorgraphicRank("string");
    return 0;
}
