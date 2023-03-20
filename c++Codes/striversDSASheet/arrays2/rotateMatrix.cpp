//https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>

using namespace std;

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void rotate(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i = 1; i < rows; i++) {
        for(int j = 0; j < i; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }

    int midCol = cols / 2;

    for(int j = 0; j <= midCol; j++) {
        for(int i = 0; i < rows; i++) {
            swap(&matrix[i][j], &matrix[i][cols - j - 1]);
        }
    }
}

int main() {

    return 0;
}