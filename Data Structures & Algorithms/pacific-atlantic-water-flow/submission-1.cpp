class Solution {
public:

    void dfs(vector<int> coord, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        visited[coord[0]][coord[1]] = true;
        int x = coord[0];
        int y = coord[1];
        int r = heights.size();
        int c = heights[0].size();
        if(x + 1 < r && heights[x + 1][y] >= heights[x][y] && !visited[x + 1][y]){
            dfs({x + 1, y}, visited, heights);
        }
        if(x - 1 >= 0 && heights[x - 1][y] >= heights[x][y] && !visited[x - 1][y]){
            dfs({x - 1, y}, visited, heights);
        }
        if(y + 1 < c && heights[x][y + 1] >= heights[x][y] && !visited[x][y + 1]){
            dfs({x, y + 1}, visited, heights);
        }
        if(y - 1 >= 0 && heights[x][y - 1] >= heights[x][y] && !visited[x][y - 1]){
            dfs({x, y - 1}, visited, heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        //dfs from atlantic and pacific 
        vector<vector<bool>> visited_pacific(r, std::vector<bool>(c, false));
        vector<vector<bool>> visited_atlantic(r, std::vector<bool>(c, false));

        //pacific border cells
        for(int i = 0; i < c; i++){
            dfs({0, i}, visited_pacific, heights);
        }

        for(int i = 1; i < r; i++){
            dfs({i, 0}, visited_pacific, heights);
        }

        //atlantic border cells
        for(int i = 0; i < c; i++){
            dfs({r - 1, i}, visited_atlantic, heights);
        }

        for(int i = 0; i < r - 1; i++){
            dfs({i, c - 1}, visited_atlantic, heights);
        }

        //visited arrays intersection
        std::vector<vector<int>> res;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(visited_atlantic[i][j] && visited_pacific[i][j]){
                    res.push_back({i, j});
                }
            }
        }


        
        return res;
    }
};
