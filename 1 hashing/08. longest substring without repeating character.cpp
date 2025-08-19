#include<bits/stdc++.h>
using namespace std;

    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex; 
        int longest = 0;
        int start = 0; 

        for (int end = 0; end < s.length(); end++) {
            char c = s[end];
            if (lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= start) {
                start = lastIndex[c] + 1; 
            }
            lastIndex[c] = end;
            longest = max(longest, end - start + 1);
        }
        return longest;
    }


int main(){
    string s = "abcabcbb";
    cout<<lengthOfLongestSubstring(s);

return 0;
}