#include <bits/stdc++.h>
using namespace std;

vector<int> subStringWithConcat(string s, vector<string>& words) {
    vector<int> ans;
    if (words.empty() || s.empty()) return ans;

    int wordLen = words[0].size();
    int wordCount = words.size();
    int windowSize = wordLen * wordCount;

    // Store word frequencies
    unordered_map<string, int> wordFreq;
    for (auto& w : words) wordFreq[w]++;

    for (int i = 0; i < wordLen; i++) {
        int left = i, count = 0;
        unordered_map<string, int> seen;

        for (int j = i; j + wordLen <= s.size(); j += wordLen) {
            string word = s.substr(j, wordLen);

            if (wordFreq.find(word) != wordFreq.end()) {
                seen[word]++;
                count++;

                // If word occurs more than needed, shrink window
                while (seen[word] > wordFreq[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }

                // If all words matched
                if (count == wordCount) {
                    ans.push_back(left);
                }
            } else {
                // Reset window if word not in list
                seen.clear();
                count = 0;
                left = j + wordLen;
            }
        }
    }
    return ans;
}

int main() {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> ans = subStringWithConcat(s, words);
    for (int el : ans) {
        cout << el << " ";
    }
    return 0;
}
