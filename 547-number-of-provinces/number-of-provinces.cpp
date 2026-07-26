class Solution {
public:
    int find(int x, vector<int> &parents) {
        if (parents[x] != x) {
            parents[x] = find(parents[x], parents);
        }

        return parents[x];
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cities = n;
        vector<int> parents (n);
        vector<int> rank(n, 0);
        iota(parents.begin(), parents.end(), 0);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    int parentI = find(i, parents);
                    int parentJ = find(j, parents);
                    if (parentI == parentJ) {
                        continue;
                    }

                    //union by rank
                    if (rank[parentI] > rank[parentJ]) {
                        parents[parentJ] = parentI;
                    } else if (rank[parentJ] > rank[parentI]) {
                        parents[parentI] = parentJ;
                    } else { //same rank
                        parents[parentJ] = parentI;
                        rank[parentI]++;
                    }

                    cities--;
                }
            }
        }

        return cities;
    }
};