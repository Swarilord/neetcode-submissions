class Solution {
public:
    void sinkIslands(vector<vector<char>>& grid, int i, int j){
        if(grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        if(i > 0){
            sinkIslands(grid, i - 1, j);
        }
        if(i < grid.size() - 1){
            sinkIslands(grid, i + 1, j);
        }
        if(j > 0){
            sinkIslands(grid, i, j - 1);
        }
        if(j < grid[i].size() - 1){
            sinkIslands(grid, i, j + 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid.at(i).at(j) == '1'){
                    sinkIslands(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
