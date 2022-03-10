//https://leetcode.com/problems/expressive-words/

#include<bits/stdc++.h>

using namespace std;

int expressiveWords(string s, vector<string>& words) {
    int i, j, flag;
    char c;
    int count1, count2, ans = 0;
    int n, m = s.length();
    for(auto w : words){
        i = 0, j = 0, flag = 1;
        n = w.length();
        while(i < m && j < n){
            count1 = 0, count2 = 0;
            if(s[i] != w[j]){
                flag = 0;
                break;
            }
            c = s[i];
            while(s[i] == c){
                i++;
                count1++;
            }
            while(w[j] == c){
                j++;
                count2++;
            }
            if((count1 < count2) || 
                (count1 == 2 && count2 != 2)){
                flag = 0;
                break;
            }
        }
        if(flag == 1 && i == m && j == n){
            ans += 1;
        }
    }
    return ans;
}

int main(){
    string s = "zzzzzyyyy";
    vector<string> w;
    w.push_back("zzyy");
    w.push_back("zy");
    w.push_back("zyy");
    cout<<expressiveWords(s, w)<<endl;
    return 0;
}
