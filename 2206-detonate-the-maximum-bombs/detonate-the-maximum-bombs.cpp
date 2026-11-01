class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        //construct adjlist based on detonable bombs for each bomb (using distance and radio of affectance)
        int n = bombs.size();
        int m = bombs[0].size();
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long radius1 = bombs[i][2];
            for (int j = i + 1; j < n; j++) {
                long x2 = bombs[j][0];
                long y2 = bombs[j][1];
                long long radius2 = bombs[j][2];
                long long dist = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
                if (dist <= radius1 * radius1) {
                    adjList[i].push_back(j);
                }
                if (dist <= radius2 * radius2) {
                    adjList[j].push_back(i);
                }
            }
        }

        //for each bomb, check its neighbors and so on (keeping visited)
        //handle local and global maximum
        int maxDetonations = 0;
        for (int i = 0; i < n; i++) {
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(i);
            visited[i] = true;
            int localDetonations = 0;

            while(!q.empty()) {
                int startPt = q.front();
                q.pop();
                localDetonations++;

                for (auto neigh : adjList[startPt]) {
                    if (!visited[neigh]) {
                        q.push(neigh);
                        visited[neigh] = true;
                    }
                }
            }

            maxDetonations = max(maxDetonations, localDetonations);
        }

        return maxDetonations;
    }
};