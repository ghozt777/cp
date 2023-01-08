// link: https://leetcode.com/problems/redundant-connection/

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
			return root ;
		}

		void _union(int x,int y){
			const int root1 = find(x) ;
			const int root2 = find(y) ;
			if(root1 == root2) return  ;

			int total_size = sz[root1] + sz[root2];\

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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size() ;
        UnionFind uf(n) ;
        for(auto & e : edges){
            int u = e[0] - 1, v = e[1] - 1 ;
            if(uf.check(u,v)) return {u + 1,v + 1} ;
            uf._union(u,v) ;
        }
        return {0,0};
    }
};