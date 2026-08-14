// struct UnionFind {
//     vector<string> parents;

//     UnionFind(set<string> equations) {
//         for (string equationVar : equationsVars) {
//             parents.push_back(equationVar);
//         }
//     }

//     string find_(string node) {
//         while(parents[node] != node) {
//             parents[node] = find(parents[node]);
//         }

//         return parents[node];
//     }

//     void union_(string node1, string node2) {
//         string root1 = find(node1);
//         string root2 = find(node2);

//         if (root1 == root2) return; //already in same group

//         parents[root2] = root1;
//     }
// };

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<double, string>>> adjList; 
        set<string> eqUniqueVars;

        for (int i = 0; i < equations.size(); i++) {
            string numerator = equations[i][0];
            string denominator = equations[i][1];
            double eResult = values[i];
            adjList[numerator].push_back(make_pair(eResult, denominator));
            adjList[denominator].push_back(make_pair(1 / eResult, numerator));
            eqUniqueVars.insert(numerator);
            eqUniqueVars.insert(denominator);
        }

        //queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
        int res = -1;
        vector<double> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); i++) {
            string numerator = queries[i][0];
            string denominator = queries[i][1];
            if (!eqUniqueVars.contains(numerator) || !eqUniqueVars.contains(denominator)){
                ans[i] = -1; 
                continue;
            }

            if (numerator == denominator) {
                ans[i] = 1; 
                continue;
            }

            queue<pair<string, double>> q;
            set<string> visited;
            q.push({numerator, 1});
            visited.insert(numerator);
            
            while(!q.empty()) {
                pair<string, double> currNode = q.front();
                q.pop();
                double currWeight = currNode.second;

                for (pair<double, string> neigh : adjList[currNode.first]) {
                    double weight = neigh.first;
                    string neighNode = neigh.second;
                    if (!visited.contains(neighNode)) {
                        q.push({neighNode, currWeight * weight});
                        visited.insert(neighNode);
                        if (neighNode == denominator){
                            ans[i] = (currWeight * weight);
                            break;
                        }
                    }
                }
            }
        }

        return ans;
    }
};