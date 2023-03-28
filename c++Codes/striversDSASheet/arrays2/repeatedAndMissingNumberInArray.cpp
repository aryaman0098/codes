//https://www.interviewbit.com/problems/repeat-and-missing-number-array/

#include <bits/stdc++.h>

using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    int n = A.size();
    long long sumOfFirstN = (n * (n + 1)) / 2;
    long long sumOfFirstNSquares = (n * (n + 1) * (2 * n + 1)) /6;
    int a, b;
    long long sum = 0, sumOfSquares = 0;
    for(int i = 0; i < n; i++) {
        sum += A[i];
        sumOfSquares += pow(A[i], 2);
    }
    int X = abs(sumOfFirstN - sum);
    int Y = abs(sumOfFirstNSquares - sumOfSquares);
    a = (Y / X + X) / 2;
    b = a - X;
    cout<<a<<" "<<b<<endl;
    return {a, b};
}


int main() {
    repeatedNumber({2,2});
    return 0;
}