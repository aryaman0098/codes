//https://leetcode.com/problems/merge-intervals/submissions/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > merge(vector<vector<int> >& intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int> > newIntervals;
    newIntervals.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        if(newIntervals.back()[1] < intervals[i][0]){
            newIntervals.push_back(intervals[i]);
        }else{
                newIntervals.back()[1] = max(newIntervals.back()[1], intervals[i][1]);
        }
    }
    return newIntervals;
}

int main(){
    vector<vector<int> > intervals;
    vector<int> temp;
    int x, y;
    for(int i = 0; i < 4; i++){
        cin>>x>>y;
        temp.push_back(x);
        temp.push_back(y);
        intervals.push_back(temp);
        temp.clear();
    }
    vector<vector<int> > newIntervals;
    newIntervals = merge(intervals);
    for(int i = 0; i < newIntervals.size(); i++){
        cout<<newIntervals[i][0]<<" "<<newIntervals[i][1];
        cout<<"\n";
    }
    return 0;
}
