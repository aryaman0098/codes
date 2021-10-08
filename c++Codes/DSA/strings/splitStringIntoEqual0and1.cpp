//https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/

#include<bits/stdc++.h>

using namespace std;

int maxSubStr(string str, int n){
    int num = 0;
    int curr0 = 0;
    int curr1 = 0;
    for(auto &ch : str){
        if(ch == '0'){
            curr0 += 1;
        }else{
            curr1 += 1;
        }
        if(curr0 == curr1){
            num++;
        }
    }
    if(num == 0){
        return -1;
    }
    return num;
}

int main(){
    
    return 0;
}
