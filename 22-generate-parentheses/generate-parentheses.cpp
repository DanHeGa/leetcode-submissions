class Solution {
public:

    vector<string> ans;
     
    void dfs(string currParenthesis, int open, int close, int n) {
        if (close > open || (open > n || close > n)) {
            return;
        }

        if (open == n && open == close) {
            ans.push_back(currParenthesis);
            return;
        }

        string currSubAns = currParenthesis;

        string withOpen = currSubAns + '(';
        dfs(withOpen, open + 1, close, n);

        string withClose = currSubAns + ')';
        dfs(withClose, open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, n);
        return ans;
    }
};