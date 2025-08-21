#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2){
    if (s1.length() > s2.length())
        return false;

    unordered_map<char, int> countS1, countS2;

    for (int i = 0; i < s1.length(); i++){
        countS1[s1[i]]++;
        countS2[s2[i]]++;
    }
    if (countS1 == countS2)
        return true;

    int left = 0;
    for (int right = s1.length(); right < s2.length(); right++){

        countS2[s2[right]]++;
        countS2[s2[left]]--;

        if (countS2[s2[left]] == 0){
            countS2.erase(s2[left]);
        }

        left++;
        if (countS1 == countS2)
            return true;
    }

    return false;
}
int main(){
    string s1 = "ab", s2 = "eidbaooo";
    cout << (checkInclusion(s1, s2) == 0 ? "false" : "True");
    return 0;
}