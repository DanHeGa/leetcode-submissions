class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0}; 
        }

        //make graph representation
        vector<vector<int>> adjList(n); 
        vector<int> degree(n); //number of connections

        for (vector<int> edge : edges) {
            //undirected graph; therefore, connections go both ways
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);

            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.clear();
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int currNode = q.front();
                q.pop();
                ans.push_back(currNode);
                for (int neigh : adjList[currNode]) {
                    degree[neigh]--;
                    if (degree[neigh] == 1) {
                        q.push(neigh);
                    }
                }
            }
        }

        return ans;
    }
};