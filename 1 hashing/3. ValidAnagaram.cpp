#include <bits/stdc++.h>
using namespace std;

bool checkAnagram(string &s, string &t){

    unordered_map<char, int> freq;

     if (s.length() != t.length())
        return false;

    for (char i : s) freq[i]++;

    for (char j : t){
        if(!freq.count(j)) return false;
        freq[j]--;
        if(freq[j] < 0) return false;
    }
    return true;
 
}
int main()
{
    string s = "anagram";
    string t = "nagaram";

    cout << (checkAnagram(s, t) ? "true" : "false") << endl;
    return 0;
}