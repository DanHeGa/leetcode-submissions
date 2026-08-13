class Solution {
public:
    bool wordFinder(int currRow, int currCol, int wordPos, vector<vector<char>>& board, string &word) {
        //if currMtrx char == currWordPos char, if not, we return
        if (board[currRow][currCol] != word[wordPos]) {
            return false;
        }

        //check if curr char it's maybe the last one
        if (wordPos == word.length() - 1) {
            return true;
        }

        //mark as visited
        char currBoardChar = board[currRow][currCol]; 
        board[currRow][currCol] = '0';
        int pairWise[5] = {-1, 0, 1, 0, -1};

        //board size
        int n = board.size();
        int m = board[0].size();
        bool flag = false;
        for (int i = 0; i < 4; i++) {
            int nxtRow = currRow + pairWise[i];
            int nxtCol = currCol + pairWise[i + 1];
            if (nxtRow >= 0 && nxtRow < n && nxtCol >= 0 && nxtCol < m && board[nxtRow][nxtCol] != '0') {
                if (wordFinder(nxtRow, nxtCol, wordPos + 1, board, word)) {
                    flag = true;
                }
            }
        }

        board[currRow][currCol] = currBoardChar; //backtrack
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (wordFinder(i, j, 0, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};

/*
    i =012345
word = ABCCED
["A","B","C","E"]
["S","F","C","S"]
["A","D","E","E"]

*/