class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Step 1: Create adjacency list for the graph
        vector<vector<int>> adj(numCourses);
		for (int i=0;i<prerequisites.size();i++) {
            // prerequisites[i][0] depends on prerequisites[i][1]
			adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}

        // Step 2: Compute in-degree (number of incoming edges) for each node
		vector<int> indegree(numCourses,0);
		for (int i = 0; i < numCourses; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

        // Step 3: Initialize queue with all nodes having 0 in-degree
		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

        // Step 4: Perform BFS (Kahn's Algorithm for Topological Sort)
		vector<int> ans; // to store the topological ordering
		while (!q.empty()) { 
			int node = q.front();
			q.pop();
			ans.push_back(node);
			
            // Decrease in-degree of adjacent nodes
			for (auto it : adj[node]) {
				indegree[it]--;
                // If in-degree becomes 0, add to queue
				if (indegree[it] == 0) q.push(it);
			}
		}

        // Step 5: If all nodes are included in proper ordering, just return it
		if (ans.size() == numCourses) return ans;

    // Cycle detected or prerequisites is not in proper ordering     
	return {};   
    }
};