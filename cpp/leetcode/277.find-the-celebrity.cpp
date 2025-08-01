#include<bits/stdc++.h>

using namespace std;

/* The knows API is defined for you.
      bool knows(int a, int b); */

bool knows(int a, int b);

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 0; i < n; i++) {
            if (candidate == i)
                continue;
            else if (knows(candidate, i)) {
                candidate = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (candidate == i)
                continue;
            else if (knows(candidate, i) || !knows(i, candidate))
                return -1;
        }
        return candidate;
    }
};