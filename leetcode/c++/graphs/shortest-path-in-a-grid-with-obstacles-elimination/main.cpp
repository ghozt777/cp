class Solution {
    const int INF = INT_MAX;
    set<pair<int,int>> vis ;
    vector<pair<int,int>> dirs = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1},
    } ;
    int dfs(vector<vector<int>>&grid,int x,int y,int k){
        
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return INF ;
        if(x == grid.size() - 1 && y == grid[0].size() - 1) return 0 ; 
        
        if(grid[x][y] == 1){
            if(k > 0) --k ;
            else return INF ;
        }
        
        int res = INF ;
        for(auto &d:dirs){
            int dx = x + d.first , dy = y + d.second ;
            if(vis.find({dx,dy}) == vis.end()){ 
                vis.insert({x,y});
                res = min(res , dfs(grid,dx,dy,k)) ;
                vis.erase({x,y});
            }
        }
        
        return res == INF ? res : res + 1 ;
    }
    
    int bfs(vector<vector<int>> &grid,int k){
		queue<vector<int>> q; 
		vector<vector<int>> lives(grid.size() , vector<int>(grid[0].size(), - 1)); 
		
		q.push({0 , 0 , k}); // x , y , k 
		lives[0][0] = k ;

		int curr_level = 0 ;

		while(!q.empty()){
			const int n = q.size() ;
			for(int i = 0 ; i < n ; i++){
				auto curr = q.front() ;
				q.pop() ;

				int x = curr[0] , y = curr[1] , life = curr[2] ;

				if(grid[x][y] == 1){
					if(life) --life ;
					else continue ;
				}

				if((x == grid.size() - 1) && (y == grid[0].size() - 1)) return curr_level ;

				lives[x][y] = life ;

				for(auto &d : dirs){
					int dx = x + d.first , dy = y + d.second ;
					if(dx < 0 || dy < 0 || dx >= grid.size() || dy >= grid[0].size() || lives[dx][dy] >= life) continue ;
					lives[dx][dy] = life ;
					q.push({dx,dy,life});
				}

			}
			++curr_level ;
		}	

		return -1 ;
	}
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // if(grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1) return -1 ;
        // vis.insert({0,0});
        // int res = dfs(grid,0,0,k) ;
        // return res == INF ? -1 : res ; 
        return bfs(grid,k) ;
    }
};