//https://leetcode.com/problems/path-crossing/

#include<bits/stdc++.h>
#include <unordered_map>

using namespace std;

bool isPathCrossing(string path){
    unordered_map<string, int> h;
    int x = 0;
    int y = 0;
    h[to_string(x) + to_string(y)] = 1;
    for(auto &c : path){
        if(c == 'N'){
            y += 1;
        }else if(c == 'S'){
            y -= 1;
        }else if(c == 'E'){
            x += 1;
        }else if(c == 'W'){
            x -= 1;
        }
        if(h.find(to_string(x) + to_string(y)) == h.end()){
            h[to_string(x) + to_string(y)] = 1;
        }else{
            return true;
        }
    }      
    return false;
}

int main(){
    string path = "NESWW";
    cout<<isPathCrossing(path);
}