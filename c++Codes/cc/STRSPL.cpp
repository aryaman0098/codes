#include<bits/stdc++.h>

using namespace std;

string flip(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            s = s.substr(0, i) + '1' + s.substr(i + 1);
        }else{
            s = s.substr(0, i) + '0' + s.substr(i + 1);
        }
    }
    return s;
}

string rev(string s){
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string s;
    vector<int> v1_S, v1_E, v2_S, v2_E;
    int k, m;
    while(t--){
        cin>>s;
        if(s == rev(s)){
            cout<<s.length()<<" "<<"0\n";
            for(int i = 1; i < s.length(); i++){
                cout<<i<<" ";
            }
            cout<<s.length()<<"\n";
            cout<<"\n";
        }else if(s == rev(flip(s))){
            cout<<"0 "<<s.length()<<"\n";
            cout<<"\n";
            for(int i = 1; i < s.length(); i++){
                cout<<i<<" ";
            }
            cout<<s.length()<<"\n";
        }else{
            for(int i = 0; i < s.length() / 2; i++){
                if(s[i] == s[s.length() - i - 1]){
                    v1_S.push_back(i + 1);
                    if(i >= (s.length() - i - 1)){
                        break;
                    }
                    v1_E.insert(v1_E.begin(), s.length() - i);
                }else{
                    v2_S.push_back(i + 1);
                    v2_E.insert(v2_E.begin(), s.length() - i);
                }
            }
            if(s.length() % 2 != 0){
                v1_S.push_back(s.length() / 2 + 1);
            }
            k = v1_S.size() + v1_E.size();
            m = v2_S.size() + v2_E.size();
            cout<<k<<" "<<m<<"\n";
            for(int i = 0; i < v1_S.size(); i++){
                cout<<v1_S[i]<<" ";
            }
            for(int i = 0; i < v1_E.size() - 1; i++){
                cout<<v1_E[i]<<" ";
            }
            cout<<v1_E[v1_E.size() - 1]<<"\n";
            for(int i = 0; i < v2_S.size(); i++){
                cout<<v2_S[i]<<" ";
            }
            for(int i = 0; i < v2_E.size() - 1; i++){
                cout<<v2_E[i]<<" ";
            }
            cout<<v2_E[v2_E.size() - 1]<<"\n";
        }
        v1_S.clear();
        v1_E.clear();
        v2_S.clear();
        v2_E.clear();
    }
}