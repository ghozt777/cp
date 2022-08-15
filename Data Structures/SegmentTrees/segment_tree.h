using ll= long long;

class SegTree{
private:
	ll sum;
	SegTree*left;
	SegTree*right;
	ll start;
	ll end;

	void recalc(){
		if(this->left==this->right) return;
		this->sum=this->left->sum+this->right->sum;
	}

public:
	SegTree(){
		this->sum=(ll)0;
		this->start=-1;
		this->end=-1;
		this->left=NULL;
		this->right=NULL;
	}
	

	SegTree(vector<ll>&arr,ll start, ll end){
		if(start>end) return;
		this->start=start;
		this->end=end;
		if(start==end){
			this->sum=arr[start];
			return;
		}
		ll mid=start+(end-start)/2;
		this->left=new SegTree(arr,start,mid);
		this->right=new SegTree(arr,mid+1,end);
		this->sum=(this->left?this->left->sum:0)+(this->right?this->right->sum:0);
		return;
	}

	void update(ll idx, ll val){
		if(this->start>idx||this->end<idx) return;
		if(this->start==idx&&this->end==idx){
			this->sum=val;
			return;
		}
		this->left->update(idx,val);
		this->right->update(idx,val);
		this->recalc();
	}

	ll query(ll start,ll end){
		if(this->start>end||this->end<start) return 0;
		if(this->start>=start&&this->end<=end) return this->sum;
		return this->left->query(start,end)+this->right->query(start,end);
	}

};


class segment_tree{
private:
	SegTree*root;
public:
	segment_tree(){
		this->root=NULL;
	}
	segment_tree(vector<ll>arr){
		this->root=new SegTree(arr,0,arr.size()-1);
	}

	void update(ll idx, ll val){
		this->root->update(idx,val);
	}

	ll query(ll start, ll end){
		return this->root->query(start,end);
	}
};

