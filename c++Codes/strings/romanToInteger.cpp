#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int romanToDecimal(string &str){
    int Nos = 0;
    unordered_map<string, int>val;
    val["I"] = 1;
    val["V"] = 5;
    val["X"] = 10;
    val["L"] = 50;
    val["C"] = 100;
    val["D"] = 500;
    val["M"] = 1000;
    for(int i = 0; i < str.length(); i++){
        if(i < str.length() - 1 && val[str.substr(i, 1)] < val[str.substr(i + 1, 1)]){
            Nos -= val[str.substr(i, 1)];
        }else{
            Nos += val[str.substr(i, 1)];
        }
    }
    return Nos;
}

int main(){
    string roman = "MCM";
    cout<<romanToDecimal(roman);
    return 0;
}
