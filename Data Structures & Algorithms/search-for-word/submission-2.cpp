class Solution {
public:

    bool backtrack(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int row, int col){
        if(i == word.size()){
            return true;
        }
        char goal = word[i];
        bool res = false;
        if(row + 1 < board.size() && !visited[row + 1][col] && board[row + 1][col] == goal){
            visited[row + 1][col] = true;
            res = res || backtrack(board, word, visited, i + 1, row + 1, col);
            visited[row + 1][col] = false;
        }
        if(row - 1 >= 0 && !visited[row - 1][col] && board[row - 1][col] == goal){
            visited[row - 1][col] = true;
            res = res || backtrack(board, word, visited, i + 1, row - 1, col);
            visited[row - 1][col] = false;
        }
        if(col + 1 < board[row].size() && !visited[row][col + 1] && board[row][col + 1] == goal){
            visited[row][col + 1] = true;
            res = res || backtrack(board, word, visited, i + 1, row, col + 1);
            visited[row][col + 1] = false;
        }
        if(col - 1 >= 0 && board[row].size() && !visited[row][col - 1] && board[row][col - 1] == goal){
            visited[row][col - 1] = true;
            res = res || backtrack(board, word, visited, i + 1, row, col - 1);
            visited[row][col - 1] = false;
        }
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        //have current path and then traverse up down left right checking for limits to find matching letter needed next
        //backtrack function with board, word, path and i (letter we are at rn/missing rn)   
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        bool res = false;
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                if(board[row][col] == word[0]){
                    visited[row][col] = true;
                    res = res || backtrack(board, word, visited, 1, row, col);
                    visited[row][col] = false;
                }
            }
        }
        return res;
    }
};
