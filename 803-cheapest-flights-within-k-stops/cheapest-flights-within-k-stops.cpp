class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //build adjList
        vector<vector<pair<int, int>>> adjList(n);
        for (auto flight : flights) {
            adjList[flight[0]].push_back({flight[2], flight[1]}); //{price, destination}
        }

        vector<int> dist(n, INT_MAX); //dist from src to nth particular city
        queue<pair<int, int>> q;
        q.push({0, src});
        dist[src] = 0;
        int count = 0;
        //use BFS (Bellman Ford) to find min dist
        while(!q.empty() && count <= k) {
            int qSize = q.size();
            vector<int> tmpDist = dist;

            for (int i = 0; i < qSize; i++) {
                auto[currNodeCost, currNodeVal] = q.front();
                q.pop();

                for (auto [currNeighCost, currNeighVal] : adjList[currNodeVal]) {
                    if (tmpDist[currNeighVal] > currNodeCost + currNeighCost) {
                        tmpDist[currNeighVal] = currNodeCost + currNeighCost;
                        q.push({tmpDist[currNeighVal], currNeighVal});
                    }
                }
            }

            dist = tmpDist;
            count++;
        }
        //return minDist only if applicable (if we were able to reach dst)
        return dist[dst] != INT_MAX ? dist[dst] : -1;
    }
};