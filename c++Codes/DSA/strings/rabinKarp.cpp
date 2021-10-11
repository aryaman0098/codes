//https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

#include<bits/stdc++.h>
#define d 256
#define q 101

using namespace std;

vector<vector<int> > rabinKarpMatching(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    int p = 0;
    int t = 0;
    int h;
    vector<vector<int> > ans;
    vector<int> temp;

    for (int i = 0; i < m - 1; i++){
        h = (h * d) % q;
    }


    for(int i = 0; i < m; i++){
        p = (d * p + s2[i]) % q;
        t = (d * t + s1[i]) % q;
    }

    for(int i = 0; i <= n - m; i++){
        if(p == t){
            for(int j = 0; j < m; j++){
                if(s1[i + j] != s2[j]){
                    break;
                }
            }
            temp.push_back(i);
            temp.push_back(i + m - 1);
            ans.push_back(temp);
            temp.clear();
        }
        if(i < n - m){
            t = (d * (t - s1[i] * h) + s1[i + m]) % q;
            if (t < 0){
                t = (t + q);
            }
        }
    }
    return ans;
}

int main(){

    string s1 = "Geeks for Geeks";
    string s2 = "Geeks";
    vector<vector<int> > ans;
    ans = rabinKarpMatching(s1, s2);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n"; 
    }
    return 0;
}
