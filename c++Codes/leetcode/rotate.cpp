#include<bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int> >& matrix){
    vector<int> temp;
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            temp.push_back(matrix[j][i]);
        }
        matrix.push_back(temp);
        temp.clear();
    }
    
    for(int i = 0; i < n; i++){
        matrix.erase(matrix.begin());
    }
}

void print(vector<vector<int> > matrix){
    int n = matrix.size(); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    vector<vector<int> > matrix;
    vector<int> temp;
    int x;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
        temp.clear();
    }
    print(matrix);
    cout<<"\n";
    rotate(matrix);
    print(matrix);
}