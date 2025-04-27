#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Check if the current cell is out of bounds or water ('0')
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        
        // Mark the current cell as visited by turning it into water ('0')
        grid[i][j] = '0';
        
        // Visit all the adjacent cells (up, down, left, right)
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;
        
        // Traverse the entire grid
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                // If we find a land ('1'), it's the start of a new island
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid, i, j); // Visit all cells of this island
                }
            }
        }
        
        return islandCount;
    }
};
