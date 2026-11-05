class UnionFind {
    private: 
        vector<int> parents;
        vector<int> rank;
    public:
        UnionFind(int n) {
            parents.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++) {
                parents[i] = i;
            }
        }

        int find(int x) {
            if (parents[x] != x) {
                parents[x] = find(parents[x]);
            }

            return parents[x];
        }

        bool unite(int a, int b) {
            //get roots
            int r1 = find(a);
            int r2 = find(b);

            //compare both to see if part of same group
            if (r1 == r2) return false;

            //union by rank, smaller trees are eaten by larger ones
            if (rank[r1] < rank[r2]) {
                parents[r1] = r2;
            } else if (rank[r2] < rank[r1]) {
                parents[r2] = r1;
            } else {
                parents[r2] = r1;
                rank[r1]++;
            }

            return true; //we were able to make a connection
        }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //make edge list
        int n = points.size(); //goal number of connections, u will see y
        vector<vector<int>> adjList;
        for (int i = 0; i < n; i++) {
            vector<int> point1 = points[i]; //points[i] = [xi, yi]
            for (int j = i + 1; j < n; j++) {
                vector<int> point2 = points[j];
                int manDist = abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
                adjList.push_back({manDist, i, j});
            }
        }

        //sort based on weight, minimum weight first
        sort(adjList.begin(), adjList.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        //make unions until we have all nodes connected, and keep updateing (adding) to the total minimum um
        int minCost = 0;
        int have = 0;
        UnionFind uf(n);
        for (int i = 0; i < adjList.size(); i++) {
            if (uf.unite(adjList[i][1], adjList[i][2])) {
                minCost += adjList[i][0];
                have++;
            }

            if (have == n) {
                return minCost;
            }
        }

        return minCost;
    }
};