//https://practice.geeksforgeeks.org/problems/d35adfbe367861ec1e67bea6e0efebe0a0ee3550/1

#include<bits/stdc++.h>

using namespace std;

string moveRobots(string s1, string s2){
    if(s1.length() != s2.length())
        return "No";
    int n = s1.length();
    int i = 0, j = 0;
    while(i < n && j < n){
        while(s1[i] == '#')
            i++;
        while(s2[j] == '#')
            j++;
        if(s1[i] != s2[j])
            return "No";
        else if(s1[i] == 'B' && i > j)
            return "No";
        else if(s1[i] == 'A' && i < j)
            return "No";
        i++;
        j++;
    }
    return "Yes";
}

int main(){

    return 0;
}
