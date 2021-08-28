#include<bits/stdc++.h>

using namespace std;

int wildCard(string pattern, string str){
    int counter1 = 0;
    int counter2 = 0;
    while(pattern.substr(counter1, 1) != "*" || pattern.substr(counter1, 1) != "?"){
        if(pattern.substr(counter1, 1) != str.substr(counter1)){
            return 0;
        }
        counter1++;
    }
}

int main(){

    return 0;
}
