#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n,0);
        vector<int> left(n,0);
        stack<int>s;
        //right smaller neares element or right boundry
        for(int i= n-1; i>= 0;i--){
            while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // removing all elements from stack for next loop
        while(!s.empty()){
            s.pop();
        }

        //left nearset smallest element or left boundry
        for(int i = 0 ; i<n; i++){
            while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            left[i] = s.empty() ? -1:s.top();
            s.push(i);
        }

        //calculating actual answer

        int ans = 0;
        for(int i = 0; i<n; i++){
            int width = (right[i] - left[i] - 1);
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        } 
        return ans;
        
    }
};
int main(){
    Solution s;
    vector<int> heights = {2,1,5,6,2,3}; //10
    cout<<s.largestRectangleArea(heights);
return 0;
}