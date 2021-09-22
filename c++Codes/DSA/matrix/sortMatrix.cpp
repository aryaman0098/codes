//https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat){
    vector<int> aux;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            aux.push_back(Mat[i][j]);
        }
    }
    sort(aux.begin(), aux.end());
    for(int i = 0; i < N; i){
        for(int j = 0; j < N; j++){
            Mat[i][j] = aux[N * i + j];
        }
    }
    return Mat;
}

int main(){

    return 0;
}
