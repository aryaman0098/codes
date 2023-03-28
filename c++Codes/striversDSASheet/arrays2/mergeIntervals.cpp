//https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>

using namespace std;

bool sortRule(const vector<int> v1, const vector<int> v2) {
    return v1[0] < v2[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), sortRule);
    vector<vector<int>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);
    int counter = 1, size = intervals.size(), currCounter;
    while(counter < size) {
        if(mergedIntervals.back()[1] < intervals[counter][0]) {
            mergedIntervals.push_back(intervals[counter]);
            counter++;
        } else {
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[counter][1]);
        }
    }
    return mergedIntervals;
}

int main() {

}