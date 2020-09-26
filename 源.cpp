#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>r_max, c_max;
        for (int i = 0; i < grid.size(); i++)
            r_max.push_back(*max_element(grid[i].begin(), grid[i].end()));
        for (int i = 0; i < grid[0].size(); i++) {
            int temp = INT_MIN;
            for (int j = 0; j < grid.size(); j++)
                temp = max(temp, grid[j][i]);
            c_max.push_back(temp);
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                ans += min(r_max[i], c_max[j]) - grid[i][j];
        return ans;
    }
};