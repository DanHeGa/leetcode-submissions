class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList(n); //Space O(E + V) number of nodes
        for(auto &time : times) { //time O(E) for number of times 
            pair<int, int> neighbor = {time[2], time[1]}; //(cost, destiny)
            adjList[time[0]].push_back(neighbor);
        }

        vector<int> dist(n + 1, INT_MAX); //space O(V)
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap; //space O(E) an origin node could have all the rest of the nodes as direct neighbors
        pair<int, int> startNodePair = {0, k};
        minheap.push(startNodePair); //time O(logV)
        unordered_set<int> visited;

        while(!minheap.empty()) { //time O(E)
            pair<int, int> currNodePair = minheap.top();
            minheap.pop();
            int currNode = currNodePair.second;

            if (visited.count(currNode)) continue;

            visited.insert(currNode);
            
            for(auto &neigh : adjList[currNode]) {//O(E logV)
                int neighCurrCost = neigh.first;
                int neighNode = neigh.second;

                if (dist[neighNode] > (dist[currNode] + neighCurrCost)) {
                    dist[neighNode] = dist[currNode] + neighCurrCost;
                    minheap.push({dist[neighNode], neigh.second});
                }
            }
        }

        int minTime = 0;
        for (int i = 1; i <= n; i++) { //time O(V)
            if (dist[i] != INT_MAX) {
                minTime = max(minTime, dist[i]);
            } else {
                return -1;
            }
        }

        return minTime;

    }
};
