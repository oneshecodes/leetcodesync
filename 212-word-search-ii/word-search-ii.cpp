#include <vector>
#include <unordered_set>
#include <string>
#include <unordered_map>

using namespace std;

class Trie {
public:
    unordered_map<char, Trie*> children;
    string word = "";
};

class Solution {
private:
    Trie* root;
    vector<vector<char>> board;
    unordered_set<string> result;
    int m, n;

    // Directions: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Helper function for DFS
    void dfs(int i, int j, Trie* node) {
        char c = board[i][j];
        if (c == '#' || node->children.find(c) == node->children.end()) return;

        Trie* nextNode = node->children[c];
        if (!nextNode->word.empty()) {
            result.insert(nextNode->word);
            nextNode->word = "";  // To prevent duplicate results
        }

        // Mark the current cell as visited
        board[i][j] = '#';

        // Explore neighbors
        for (auto& dir : directions) {
            int x = i + dir.first, y = j + dir.second;
            if (x >= 0 && x < m && y >= 0 && y < n) {
                dfs(x, y, nextNode);
            }
        }

        // Unmark the current cell
        board[i][j] = c;
    }

    // Build the Trie
    void buildTrie(vector<string>& words) {
        root = new Trie();
        for (const string& word : words) {
            Trie* node = root;
            for (char c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new Trie();
                }
                node = node->children[c];
            }
            node->word = word;
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board = board;
        m = board.size();
        n = board[0].size();

        buildTrie(words);

        // Start DFS from every cell in the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, root);
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};
