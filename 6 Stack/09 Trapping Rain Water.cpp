#include<bits/stdc++.h>
using namespace std;
  
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st; // stores indices
        int water = 0;

        for (int i = 0; i < n; i++) {
            // While current bar is taller than the bar at stack top
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty()) break; // no left boundary

                int distance = i - st.top() - 1; // width
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                water += distance * boundedHeight;
            }
            st.push(i);
        }

        return water;
    }
};

int main() {
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(height) << endl;  // Expected output: 6
    return 0;
}
