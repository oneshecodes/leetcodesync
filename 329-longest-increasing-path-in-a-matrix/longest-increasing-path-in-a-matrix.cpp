class Solution {
public:
    int m, n;
    vector<vector<int>> matrix;
    vector<vector<bool>> visited;
    vector<vector<int>> LIP;

    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool isValidTile(int x, int y) {
        return (x >= 0 and y >= 0 and x < m and y < n);
    }

    void findLIP(int x, int y) {
        visited[x][y] = true;
        for (auto [dx, dy] : dirs) {
            if (not isValidTile(x + dx, y + dy)) 
                continue;
            if (matrix[x][y] < matrix[x + dx][y + dy]) {
                if (not visited[x + dx][y + dy])
                    findLIP(x + dx, y + dy);
                    
                LIP[x][y] = max(LIP[x][y], LIP[x + dx][y + dy] + 1);
            }
        }
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        this->matrix = matrix;
        visited = vector<vector<bool>> (m, vector<bool> (n, false));
        LIP = vector<vector<int>> (m, vector<int> (n, 1));

        int lip = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (not visited[i][j]) {
                    findLIP(i, j);
                }
                lip = max(lip, LIP[i][j]);
            }
        }

        return lip;
    }
};