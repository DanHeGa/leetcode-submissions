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

        dfs(currParenthesis + '(', open + 1, close, n);
        dfs(currParenthesis + ')', open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, n);
        return ans;
    }
};