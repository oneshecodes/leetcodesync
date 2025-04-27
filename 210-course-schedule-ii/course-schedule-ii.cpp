class Solution {
public:
    vector<int> topoSortBFS(int numCourses, unordered_map<int, list<int>> &adjList) {
        unordered_map<int, int> indegree;
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            indegree[i] = 0;
        }

        for (auto it1 : adjList) {
            for (auto it2 : it1.second) {
                indegree[it2]++;
            }
        }

        queue<int> q;

        for (auto it : indegree) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }

        while(!q.empty()) {
            int frontNode = q.front();
            ans.push_back(frontNode);
            q.pop();

            for (auto nbr : adjList[frontNode]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        if (ans.size() == numCourses)
            return ans;
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;

        for (auto it : prerequisites) {
            adjList[it[1]].push_back(it[0]);
        }
        return topoSortBFS(numCourses, adjList);
    }
};