//https://www.geeksforgeeks.org/print-subsequences-string/

#include<bits/stdc++.h>

using namespace std;

void printAllSubSequnces(string input, string output){
    if(input.empty()){
        cout<<output<<"\n";
        return;
    }
    printAllSubSequnces(input.substr(1), output + input[0]);
    printAllSubSequnces(input.substr(1), output);
}

int main(){

    string output = "";
    string input = "abcde";
    printAllSubSequnces(input, output);
    return 0;
}
