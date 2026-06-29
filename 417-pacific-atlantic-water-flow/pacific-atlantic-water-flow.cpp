class Solution {
public:
    //save coors that get to each ocean
    int rows, cols; 

    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& heights) {
        
        if (visited[i][j]) return;
        
        visited[i][j] = true; //set as visited!

        vector<int> pairWise = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int newRow = i + pairWise[k];
            int newCol = j + pairWise[k + 1];

            if (newRow < rows && newRow >= 0 && newCol < cols && newCol >= 0 
                && heights[newRow][newCol] >= heights[i][j] && //check neighbor value is ascending
                !visited[newRow][newCol]) { //check neighbor value was not already visited
                dfs(newRow, newCol, visited, heights);
            }
        }
    }   

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<bool>> pacVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlVisited(rows, vector<bool>(cols, false));

        //check top (Pacific) and bottom (Atlantic) rows
        for (int i = 0; i < cols; i++) {
            dfs(0, i, pacVisited, heights);
            dfs(rows - 1, i, atlVisited, heights);
        }

        //check left(Pacific) and right(Atlantic) cols 
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, pacVisited, heights);
            dfs(i, cols - 1, atlVisited, heights);
        }

        vector<vector<int>> res;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacVisited[i][j] && atlVisited[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};