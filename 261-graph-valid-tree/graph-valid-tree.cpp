class Solution {
public:
    int find(int x, vector<int>& parents) { //function to find the parent of an element
        if (parents[x] != x) parents[x] = find(parents[x], parents);
        return parents[x]; //because parents[x] == x
    };

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parents(n);
        iota(parents.begin(), parents.end(), 0);

        for(auto& edge : edges) {
            int root1 = find(edge[0], parents);
            int root2 = find(edge[1], parents);

            if (root1 == root2) {
                return false; //found a cycle
            }

            parents[root1] = root2; //connect components;
            n--;
        }

        return n == 1;

    }
};


// 0   1 2  3  4  
//[0, 0, 0, 0, 1]