#include<bits/stdc++.h>
using namespace std;

    int maxArea(vector<int>& height) {
        
        int maxArea = 0, i = 0, j = height.size() - 1;
        while(i < j){
            int wdt = j - i;
            int ht = min(height[i] , height[j]);
            int area = wdt * ht;
            maxArea = max(maxArea, area);

            height[i] <= height[j] ? i++ : j--;
        }
        return maxArea;
    }

int main(){
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout<<"the area of a container that stores maximum water is :"<<maxArea(heights);
return 0;
}