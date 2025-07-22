#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length(), m = t.length();
        if (abs(n - m) > 1 || s == t)
            return false;
        int p1 = 0, p2 = 0;
        int numDiff = 0;
        while (p1 < n && p2 < m) {
            if (s[p1] != t[p2]) {
                numDiff++;
                if (numDiff > 1)
                    return false;
                if (n == m) {
                    p1++;
                    p2++;
                } else if (n > m) {
                    p1++;
                } else {
                    p2++;
                }
            } else {
                p1++;
                p2++;
            }
        }
        return true;
    }
};