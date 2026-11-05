class Solution {
private:
    vector<vector<int>> rooms;
    unordered_set<int> visited;
    int totalOpen = 0;
public:
    void visit(int idx) {
        if (visited.contains(idx)) {
            return;
        }

        visited.insert(idx);
        totalOpen++;
        for (int key : rooms[idx]) {
            visit(key);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        this->rooms = rooms;
        visit(0);
        return totalOpen == rooms.size();
    }
};

/*
     i =  0   1   2  3  
rooms = [[1],[2],[3],[]]

0: {1},
1: {2}, 
2: {3},
3: {}

*/