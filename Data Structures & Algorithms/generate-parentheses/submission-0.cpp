class Solution {
public:

    void backtrack(vector<string>& res, string curr, int open, int closed, int n){
        if(open == n && closed == n){
            res.push_back(curr);
        }
        if(open < n){
            backtrack(res, curr + '(', open + 1, closed, n);
        }
        if(closed < open){
            backtrack(res, curr + ')', open, closed + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        backtrack(res, curr, 0, 0, n);
        return res;
    }
};
