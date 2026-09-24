class UnionFind {
    public:
        unordered_map<int, int> parents;
        unordered_map<int, int> sizes;
        int maxSize = 1;

        UnionFind(vector<int>& nums) {
            for (int num : nums) {
                parents[num] = num;
                sizes[num] = 1;
            }
        }

        int find(int node) {
            if (parents[node] != node) { //not using path compression
                parents[node] = find(parents[node]);
            }

            return parents[node]; //or node, which would be the same
        }

        void _union(int node1, int node2) {
            int p1 = find(node1);
            int p2 = find(node2);

            if (p1 == p2) {
                return;
            }
            if (sizes[p2] > sizes[p1]) {
                parents[p1] = p2;
                sizes[p2] += sizes[p1];
                maxSize = max(maxSize, sizes[p2]);
            } else {
                parents[p2] = p1;
                sizes[p1] += sizes[p2];
                maxSize = max(maxSize, sizes[p1]);
            }
        }
};



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        UnionFind u(nums);

        for (int num : nums) {
            if (u.parents.contains(num + 1)) {
                u._union(num, num + 1);
            }
        }

        return u.maxSize;
    }
};