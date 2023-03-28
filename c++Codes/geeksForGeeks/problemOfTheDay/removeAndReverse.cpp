//https://practice.geeksforgeeks.org/problems/1e2f365be6114b671b915e145ec7dbcfdc432910/1

#include<bits/stdc++.h>

using namespace std;

string removeReverse(string S) {
    unordered_map<char, int> u;
    for(auto c : S) {
        u[c]++;
    }
    for(int i = 0; i < S.length(); i++) {
        if(u[S[i]] > 1) {
            S = S.substr(i + 1, S.length() - i - 1);
            reverse(S.begin(), S.end());
        } 
    }
    return S;
}

int main() {

}