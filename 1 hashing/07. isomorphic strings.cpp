#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string &s, string &t){
    unordered_map<char, int> sIndex;
    unordered_map<char, int> tIndex;

    for (int i = 0; i < s.length(); i++){
        if (!sIndex.count(s[i]))
            sIndex[s[i]] = i;
        if (!tIndex.count(t[i]))
            tIndex[t[i]] = i;
        if (sIndex[s[i]] != tIndex[t[i]])
            return false;
    }

    return true;
}

int main(){
    string s = "egg", t = "add";
    cout << (isIsomorphic(s, t) ? "True" : "False");
    return 0;
}