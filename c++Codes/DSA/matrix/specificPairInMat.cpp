//https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/

#include<bits/stdc++.h>

using namespace std;

int findMaxValues(vector<vector<int> > m){
    int n = m.size();
    int maxVal = m[n - 1][n - 1];
    int maxVals[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            maxVals[i][j] = 0;
        }
    }


    maxVals[n - 1][n -1] = maxVal;
    for(int i = n - 2; i >= 0; i--){
        if(m[i][n - 1] > maxVal){
            maxVal = m[i][n - 1];
        }
        maxVals[i][n - 1] = maxVal;
    }
    maxVal = m[n - 1][n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(m[n - 1][i] > maxVal){
            maxVal = m[n - 1][i];
        }
        maxVals[n - 1][i] = maxVal;
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
            if(maxVals[i + 1][j + 1] - m[i][j] > maxVal){
                maxVal = maxVals[i + 1][j + 1] - m[i][j];
            }
            maxVals[i][j] = max(m[i][j], max(maxVals[i][j + 1], maxVals[j + 1][i]));
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<maxVals[i][j]<<" ";
        }
        cout<<"\n";
    }

    return maxVal;
}

int main(){

    vector<vector<int> > m;
    vector<int> temp;
    int n;
    cin>>n;
    int x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>x;
            temp.push_back(x);  
        }
        m.push_back(temp);
        temp.clear();
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";

    cout<<findMaxValues(m);
    return 0;
}
