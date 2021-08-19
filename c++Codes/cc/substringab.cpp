#include <bits/stdc++.h>
#include <string.h>

using namespace std;


string concat(string a, int n){
    if (n == 1){
        return a;
    }else{
        return (a + concat (a, n-1));
    }
}

int isSubstring(string a, string b){
    
    for (int i  = 0; i <= b.length(); i++){
        string s = b.substr(i, 0);
        bool check = false;
        for(int j = 0; j <= a.length(); j++){
            if (a.substr(j ,0) == s){
                check  = true;
            }
        }
        if (check == false){
            return -1;
        }
    }


    int n = a.length();
    int m = b.length();

    for(int i = 1; i <= n*m; i++){
        string s = concat(a, i);
        if (s.length() > m){
            for(int j = 0; j < s.length()-m; j++){
                string r  = s.substr(j, m);
                if (r == b){
                    return i;
                }
            }
        }  
    }
    return -1;
}


int main(){
    int n = isSubstring("abcdef", "defabcdefabcdefabcdefabc");
    cout<<n;
}