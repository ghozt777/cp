// link: https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {

class UnionFind{
	private: 
		int __size ;

		vector<int> sz;

		vector<int> id;

	public:
		UnionFind(int n){
			id.resize(n);
			sz.resize(n);
			for(int i = 0 ; i < n ; i++){
				id[i] = i ;
				sz[i] = 1 ;
			}
			this->__size = n;
		}

		int find(int x){
			if(id[x] == x) return x ;
			int root = id[x] ;
			while(root != id[root]) root = id[root];
            // compress
            while(x != root){
                int nxt = id[x] ;
                id[x] = root ;
                x = nxt ;
            }
			return root ;
		}

		void _union(int x,int y){
			const int root1 = find(x) ;
			const int root2 = find(y) ;
			if(root1 == root2) return  ;

			int total_size = sz[root1] + sz[root2];

			if(sz[root1] < sz[root2]) id[root1] = root2 ;
			else id[root2] = root1 ;

			sz[root1] = sz[root2] = total_size ;

			--this->__size;

		}

		bool check(int x,int y){
			return find(x) == find(y) ;
		}

		int size(){
			return __size ;
		}

		int size(int x){
			return sz[x] ;
		}
};


public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size() ;
        int res = 0 ;

        UnionFind uf(n) ;
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                pq.push({
                    abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]),
                    i,
                    j
                });
            }
        }

        while(!pq.empty()){
            auto edge = pq.top();
            pq.pop(); 

            int dist = edge[0] , i = edge[1] , j = edge[2] ;

            if(uf.check(i,j)) continue ;

            uf._union(i,j) ;

            res += dist ;

            if(uf.size() == 1) break ;
        }   

        return res ;
    }
};