#include<bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    // Code here
    vector<vector<int>> dirs = {
        {0, 1} ,
        {1, 0} ,
        {-1, 0} ,
        {0, -1} ,
        {1, 1} ,
        {-1, 1} ,
        {-1, -1} ,
        {1, -1}
    };
    vector<vector<int>> visited;
    for(int i = 0; i < grid.size(); i++){
        vector<int> row;
        for(int j = 0; j < grid[i].size(); j++) row.emplace_back(0);
        visited.emplace_back(row);
    }
    queue<pair<int, int>> toProcess;
    int res = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(!visited[i][j] && grid[i][j] == 1){
                ++res;
                toProcess.push(make_pair(i, j));
                visited[i][j] = 1;
                while(!toProcess.empty()){
                    pair<int, int> current = toProcess.front();
                    toProcess.pop();
                    for(auto d : dirs){
                        int x = d[0] + current.second ;
                        int y = d[1] + current.first ;
                        if(x >= 0 && x < grid[0].size() && y >= 0 && y < grid.size()){
                            if(!visited[y][x] && grid[y][x] == 1){
                                visited[y][x] = 1 ;
                                toProcess.push(make_pair(y , x)) ;
                            }
                        }
                    }
                }
            }
        }
    }
    return res;
}

int main(){
    vector<vector<char>> grid = {{0,1},{1,0},{1,1},{1,0}};
    cout << numIslands(grid);
}