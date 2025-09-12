#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top() - i;
            }
            s.push(i);
        }
        return ans;
    }
};  
int main(){
    Solution s;
    vector<int> temperetures = {73,74,75,71,69,72,76,73},ans;
// Output: [1,1,4,2,1,1,0,0]
     ans = s.dailyTemperatures(temperetures);
     for(int el : ans){
        cout<<el<<" ";
     }

return 0;
}