#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n, i, d;
    cin>>n;
    cin>>i;
    cin>>d; 
    int cost=0;
    int Th_5=0;
    int Th_7=0;
    int Fv_7=0;
    vector<int> Storage;
    vector<int> Out;
    for(int x1=1;x1<=20;x1++){
        for(int x2=1;x2<=14;x2++){
            Th_5=int(pow(3,x1))+int(pow(5,x2));
            Th_7=int(pow(3,x1))+int(pow(7,x2));
            Fv_7=int(pow(5,x1))+int(pow(7,x2));
            
            if(Th_5<0 || Th_7<0 || Fv_7<0){
                break;
            }

            Storage.push_back(Th_5);
            Storage.push_back(Th_7);
            Storage.push_back(Fv_7);
        }
    }
    sort(Storage.begin(), Storage.end());
    if(n < Storage[0]){
        cout<<i * (Storage[0] - n);
    }else if(n > Storage[Storage.size() - 1]){
        cout<<d * (n - Storage[Storage.size() - 1]);
    }
    for(int i = 0; i < Storage.size(); i++){
        if(n = Storage[i]){
            cout<<0;
        }
        else if(Storage[i] < n && n < Storage[i + 1]){
            cout<<min(d * (n - Storage[i]), i * (Storage[i + 1] - n));
        }
    }
}
