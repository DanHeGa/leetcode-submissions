class Solution {
public:
    int rows, cols;
    void print(vector<vector<char>>& board) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(int i, int j, vector<vector<char>>& board) {
        if (board[i][j] != 'O') {
            return;
        }

        board[i][j] = 'T';
        vector<int> pairWise = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int newRow = i + pairWise[k];
            int newCol = j + pairWise[k + 1];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && board[newRow][newCol] == 'O') {
                dfs(newRow, newCol, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O') dfs(0, i, board);
            if (board[rows - 1][i] == 'O') dfs(rows - 1, i, board);
        }

        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][cols - 1] == 'O') dfs(i, cols - 1, board);
        }

        print(board);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'T') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        cout << "last" << endl;
        print(board);
    }
};