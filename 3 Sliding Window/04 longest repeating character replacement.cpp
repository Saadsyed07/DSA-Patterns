#include<bits/stdc++.h>
using namespace std;

    int characterReplacement(string s, int k) {
        int ans = 0, left = 0, maxf = 0;
        unordered_map<char, int> mpp;

        for (int right = 0; right < s.length(); right++) {
            mpp[s[right]]++;
            maxf = max(maxf, mpp[s[right]]);

            if ((right - left + 1) - maxf > k) {
                mpp[s[left]]--;
                left++;
            } else {
                ans = max(ans, (right - left + 1));
            }
        }
        return ans;
    }

int main(){
string s = "AABABBA" ; int k = 2;
cout<<characterReplacement(s, k);
return 0;
}