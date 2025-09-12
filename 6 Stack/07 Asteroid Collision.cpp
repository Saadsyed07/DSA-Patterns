#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;

      for(int asteroid : asteroids){
        if(asteroid > 0){
            s.push(asteroid);
        }else{
            while(!s.empty() && s.top() > 0 && s.top()< -asteroid){
                s.pop();
            }
            if(s.empty() || s.top() < 0){
                s.push(asteroid);
            }
            if(!s.empty() && s.top() == -asteroid){
                s.pop();
            }
        }
      }

      vector<int> ans (s.size());
      int i = s.size() -1;
      while(!s.empty()){
        ans[i--] = s.top();
        s.pop();
      }

      return ans;
    }
};
int main(){
Solution s;
vector<int> asteroids = {5,10,-5};
vector<int> ans = s.asteroidCollision(asteroids);
for(int num : ans){
    cout<<num<<" ";
}

return 0;
}