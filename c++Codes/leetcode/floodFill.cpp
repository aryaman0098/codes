//https://leetcode.com/problems/flood-fill/

#include<bits/stdc++.h>

using namespace std;

void changeImage(vector<vector<int>>& image, int sr, int sc, int newColor, int n){
    if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != n)
        return;
    image[sr][sc] = newColor;
    changeImage(image, sr - 1, sc, newColor, n);
    changeImage(image, sr, sc - 1, newColor, n);
    changeImage(image, sr + 1, sc, newColor, n);
    changeImage(image, sr, sc + 1, newColor, n);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
    int n = image[sr][sc];
    if(n == newColor) return image;
    changeImage(image, sr, sc, newColor, n);
    return image;
}

int main(){

    return 0;
}
