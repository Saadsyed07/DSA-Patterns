#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagram(vector<string> &str){
    unordered_map<string, vector<string>> ans;

    for (string s : str){
        // Count frequency of each character in the word
        vector<int> freq(26, 0);
        for (char c : s){
            freq[c - 'a']++;
        }
        string key = "";
        for (int count : freq)
        {
            key += to_string(count) + "#";
        }

        ans[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &entry : ans)
    {
        result.push_back(entry.second);
    }
    return result;
}

int main()
{
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagram(str);
    for (auto ans : result)
    {
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}