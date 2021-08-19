#include<bits/stdc++.h>

using namespace std;

int check(string arr[], string s){
    string c1 = string(1, arr[0].at(0)) + string(1, arr[1].at(0)) + string(1, arr[2].at(0));
    string c2 = string(1, arr[0].at(1)) + string(1, arr[1].at(1)) + string(1, arr[2].at(1));
    string c3 = string(1, arr[0].at(2)) + string(1, arr[1].at(2)) + string(1, arr[2].at(2));
    string d1 = string(1, arr[0].at(0)) + string(1, arr[1].at(1)) + string(1, arr[2].at(2));
    string d2 = string(1, arr[0].at(2)) + string(1, arr[1].at(1)) + string(1, arr[2].at(0));
    if(arr[0] == s || arr[1] == s || arr[2] == s || c1 == s || c2 == s || c3 == s || d1 == s || d2 == s){
        return 1;
    }else{
        return 0;
    }
}

int count(string arr[], string s){
    int counter = 0;
    for(int i = 0; i < 3; i++){
        for(char c : arr[i]){
            if(string(1, c) == s){
                counter++;
            } 
        }
    }
    return counter;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    string arr[3];
    while(t--){
        for(int i = 0; i < 3; i++){
            cin>>arr[i];
        }
        if((check(arr, "XXX") == 1 && check(arr, "OOO") == 0 && (count(arr, "X") - count(arr, "O") == 1)) || (check(arr, "XXX") == 0 && check(arr, "OOO") == 1 && (count(arr, "O") - count(arr, "X") == 0))){
            cout<<1<<"\n";
        }else if(check(arr, "XXX") == 0 && check(arr, "OOO") == 0 && count(arr, "X") == 5 && count(arr, "O") == 4){
            cout<<1<<"\n";
        }else if(check(arr, "XXX") == 0 && check(arr, "OOO") == 0 && count(arr, "X") < 5 && count(arr, "O") <= 4 && (0 <= count(arr, "X") - count(arr, "O")) && (count(arr, "X") - count(arr, "O") <= 1)){
            cout<<2<<"\n";
        }else{
            cout<<3<<"\n";
        }
    }
}