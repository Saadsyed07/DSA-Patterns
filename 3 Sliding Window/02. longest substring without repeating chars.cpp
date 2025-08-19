#include<bits/stdc++.h>
using namespace std;
  
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;

        if (!s.length())
            return 0;
        int i = 0, j = 0, cnt = 0;

        while (j < s.length()) {
            char c = s[j];

            if (st.find(c) != st.end()) {
                st.erase(s[i]);
                i++;
            } else {
                st.insert(s[j]);
                cnt = max(cnt, j - i + 1);
                j++;
            }
        }
        return cnt;
    }
int main(){

    string s = "abcabcbb";
    cout<<"longest substring without repeating chars : "<<lengthOfLongestSubstring(s);
return 0;
}