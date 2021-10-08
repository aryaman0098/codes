//https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

#include<bits/stdc++.h>

using namespace std;

bool ispar(string x){
    stack<char> s;
    char temp;
    for(int i = 0; i < x.size(); i++){
        if(x[i] == '{' || x[i] == '(' || x[i] == '['){
            s.push(x[i]);
        }else{
            if(x[i] == '}') temp = '{';
            if(x[i] == ')') temp = '(';
            if(x[i] == ']') temp = '[';
            
            if(s.empty() || s.top() != temp){
                return false;
            }
            s.pop();
        }
    
    }
    if(s.empty()){
        return true;
    }
    return false;
}


int main(){
    
    return 0;
}
