#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int trap(vector<int> &height){
        int left = 0;
        int right = height.size() - 1;
        int lmax = height[left], rmax = height[right];
        int water = 0;

        while (left < right){
            if (lmax < rmax){
                left++;
                lmax = max(lmax, height[left]);
                water += lmax - height[left];
            }
            else{
                right--;
                rmax = max(rmax, height[right]);
                water += rmax - height[right];
            }
        }
        return water;
    }
};
int main(){
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    cout << "traped water : " << s.trap(height);
    return 0;
}