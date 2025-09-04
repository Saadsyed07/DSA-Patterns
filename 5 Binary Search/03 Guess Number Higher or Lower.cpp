#include <bits/stdc++.h>
using namespace std;

// Mock API 
int PICK = 6; 
int guess(int num) {
    if (num == PICK) return 0;  
    else if (num < PICK) return 1; 
    else return -1;           
}

class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n, mid;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == 1)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1; 
    }
};

int main() {
    Solution sol;
    int n = 10; 
    cout << "Guessed number: " << sol.guessNumber(n) << endl;
    return 0;
}
