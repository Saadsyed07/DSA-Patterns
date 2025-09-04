#include <bits/stdc++.h>
using namespace std;


int BAD_VERSION = 4;  // for testing
bool isBadVersion(int version) {
    return version >= BAD_VERSION;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n, mid;

        while (start <= end) {
            mid = start + (end - start) / 2;
            if (isBadVersion(mid)) 
                end = mid - 1; 
            else 
                start = mid + 1;
        }
        return start;
    }
};

int main() {
    Solution sol;
    int n = 10; // total versions
    cout << "First bad version: " << sol.firstBadVersion(n) << endl;
    return 0;
}
