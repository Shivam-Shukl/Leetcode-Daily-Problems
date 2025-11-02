#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 1)); // 1 = unguarded, 0 = guarded, 2 = wall, 3 = guard
        
        // Place walls
        for (auto &w : walls)
            grid[w[0]][w[1]] = 2;

        // Place guards
        for (auto &g : guards)
            grid[g[0]][g[1]] = 3;

        // Directions: up, down, left, right
        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        // Spread guards' vision
        for (auto &g : guards) {
            for (auto &d : dirs) {
                int i = g[0] + d.first;
                int j = g[1] + d.second;
                while (i >= 0 && i < m && j >= 0 && j < n) {
                    if (grid[i][j] == 2 || grid[i][j] == 3) break; // blocked
                    if (grid[i][j] == 1) grid[i][j] = 0; // mark as guarded
                    i += d.first;
                    j += d.second;
                }
            }
        }

        // Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) count++;

        return count;
    }
};
