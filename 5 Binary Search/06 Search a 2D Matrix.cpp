#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool searchInRow(vector<vector<int>> &mat, int target, int row){
        int n = mat[0].size();
        int st = 0, end = n - 1;
        while (st <= end){
            int mid = st + (end - st) / 2;
            if (mat[row][mid] == target){
                return true;
            }
            else if (mat[row][mid] > target){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &mat, int target){

        int m = mat.size(), n = mat[0].size();
        int sr = 0, er = m - 1;
        while (sr <= er){
            int midr = sr + (er - sr) / 2;
            if (mat[midr][0] <= target && target <= mat[midr][n - 1]){
                return searchInRow(mat, target, midr);
            }
            else if (mat[midr][0] < target){
                sr = midr + 1;
            }
            else{
                er = midr - 1;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 7;
    cout << (s.searchMatrix(mat, target) ? "Found" : "Not Found") << endl;
    return 0;
}