//https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/

#include<bits/stdc++.h>

using namespace std;

void rotateClockwise90(vector<vector<int> >& mat){
    int n = mat.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(int i = 0; i < n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main(){

    vector<vector<int> > mat;
    vector<int> temp;
    int x;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>x;
            temp.push_back(x);
        }
        mat.push_back(temp);
        temp.clear();
    }

    rotateClockwise90(mat);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
