//https://practice.geeksforgeeks.org/problems/4e75764f8f1638eb4f1c5478ca1986043e15e39a/1

#include<bits/stdc++.h>

using namespace std;

double slope(pair<int, int>p1, pair<int, int>p2){
    double x1 = p1.first;
    double x2 = p2.first;
    double y1 = p1.second;
    double y2 = p2.second;
    return (y2 - y1) / (x2 - x1);
}

int mostBalloons(int N, pair<int, int> arr[]) {
    int ans = INT_MIN;
    for(int i = 0; i < N - 1; i++){
        unordered_map<double, int> u;
        int count = 0;
        for(int j = i + 1; j < N; j++){
            if(arr[i] == arr[j])
                count++;
            else
                u[slope(arr[i], arr[j])]++;
        }
        for(auto l : u)
            ans = max(ans, l.second + count);
    }
    return ans + 1;
}

int main(){

    return 0;
}
