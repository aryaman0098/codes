#include<bits/stdc++.h>

using namespace std;

static bool cmp(pair<int, int>& a, pair<int, int>& b){
    return a.second < b.second;
}

vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<pair<int, int>> p;
    int n, counter, x;
    for(int i = 0; i < nums.size(); i++){
        int x = nums[i];
        n = 0;
        counter = 0;
        if(x == 0){
            p.push_back({ nums[i], mapping[nums[i]] });
        }else{
            while(x > 0){
            n = n + mapping[x % 10] * int(pow(10, counter));
            counter++;
            x /= 10;
            }
            p.push_back({ nums[i], n });   
        }
    }
    sort(p.begin(), p.end(), cmp);
    vector<int> ans;
    for(auto m : p)
        ans.push_back(m.first);
    return ans;
}

int main(){

    return 0;
}
