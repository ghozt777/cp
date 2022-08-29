#include<bits/stdc++.h>
using namespace std;


class SegTree{
private:
	int sum;
	SegTree*left;
	SegTree*right;
	int start;
	int end;

	SegTree(vector<int>&arr,int start, int end){
		if(start>end) return;
		if(start==end){
			this->start=start;
			this->end=end;
			this->sum=arr[start];
			return;
		}
		int mid=start+(end-start)/2;
		this->left=new SegTree(arr,start,mid);
		this->right=new SegTree(arr,mid+1,end);
		this->sum=(this->left?this->left->sum:0)+(this->right?this->right->sum:0);
		return;
	}

	void recalc(){
		if(this->left==this->right) return;
		this->sum=this->left->sum+this->right->sum;
	}

public:
	SegTree(){
		this->sum=(int)0;
		this->start=-1;
		this->end=-1;
		this->left=NULL;
		this->right=NULL;
	}
	SegTree(vector<int>arr){
		SegTree(arr,0,arr.size()-1);
	}

	void update(int idx, int val){
		if(this->start>idx||this->end<idx) return;
		if(this->start==idx&&this->end==idx){
			this->sum=val;
			return;
		}
		this->left->update(idx,val);
		this->right->update(idx,val);
		this->recalc();
	}

	int query(int start,int end){
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
	segment_tree(vector<int>arr){
		this->root=new SegTree(arr);
	}

	void update(int idx, int val){
		this->root->update(idx,val);
	}

	int query(int start, int end){
		return this->root->query(start,end);
	}
};
