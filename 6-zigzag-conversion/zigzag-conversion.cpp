class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<vector<char>> matrix(numRows);

        int n = s.length();
        int dir = 1;
        int insertPos = -1;
        //build zig zig matrix
        for(int i = 0; i < n; i++) { 
            if (insertPos + 1 == numRows) {
                dir = -1;
            } else if (insertPos == 0) {
                dir = 1;
            }

            
            insertPos += dir;
            matrix[insertPos].push_back(s[i]);
        }

        int m = matrix.size();
        string res = "";
        for (int i = 0; i < m; i++) {
            for(char c : matrix[i]) {
                res.push_back(c);
            }
        }

        return res;

    }
};
/*
PAYPALISHIRING n = 3

[[P   A   H   N]   0
[A P L S I I G]    1
[Y   I   R]]       2
  
dir = -1

r= PAHNAPLSIIGYIR
*/