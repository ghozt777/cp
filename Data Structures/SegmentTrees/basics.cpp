#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
	SegmentTree* root;
	SegmentTree* left;
	SegmentTree* right;
	int data;
	int start;
	int end;
	bool isBuilt;

	SegmentTree* buildSegmentTreeHelper(vector<int>& arr, int start, int end) {
		if (start > end)return NULL;
		SegmentTree* node = new SegmentTree();
		if (start == end) {
			node->data = arr[start];
			node->start = start;
			node->end = end;
			return node;
		}
		int mid = start + (end - start) / 2;
		node->left = buildSegmentTreeHelper(arr, start, mid);
		node->right = buildSegmentTreeHelper(arr, mid + 1, end);
		node->data = min(node->left ? node->left->data : INT_MAX, node->right ? node->right->data : INT_MAX);
		node->start = start;
		node->end = end;
		return node;
	}

	void buildSegmentTree(vector<int>& arr) {
		if (isBuilt) throw "Segment Tree can only be instaniated once";
		this->root = this->buildSegmentTreeHelper(arr, 0, arr.size() - 1);
	}


	void printTreeHelper(SegmentTree* node) {
		if (!node)return;
		cout << "start: " << node->start << " end: " << node->end << " || data: " << node->data << endl;
		printTreeHelper(node->left);
		printTreeHelper(node->right);
	}

	int updateHelper(SegmentTree* node, int pos, int diff) {
		if (!node) return INT_MAX;
		int start = node->start;
		int end = node->end;
		if (pos<start || pos>end)return INT_MAX;
		if (pos == start && pos == end) {
			node->data += diff;
			return node->data;
		}
		int mid = start + (end - start) / 2;
		int change = INT_MAX;
		if (pos <= mid) change = updateHelper(node->left, pos, diff);
		else change = updateHelper(node->right, pos, diff);
		node->data = min(node->data, change);
		return node->data;
	}

	int queryHelper(SegmentTree* node, int start, int end) {
		if (!node)return INT_MAX;
		int n_start = node->start;
		int n_end = node->end;
		if (end<n_start || start>n_end) return INT_MAX;
		if (n_start >= start && n_end <= end) return node->data;
		return min(queryHelper(node->left, start, end), queryHelper(node->right, start, end));
	}


public:
	SegmentTree() {
		this->isBuilt = false;
		this->root = NULL;
		this->data = INT_MAX;
		this->left = NULL;
		this->right = NULL;
	}

	SegmentTree(vector<int> arr) {
		this->buildSegmentTree(arr);
	}

	void printSegTree() {
		if (!this->root) return;
		printTreeHelper(this->root);
	}

	void update(int pos, int diff) {
		this->updateHelper(this->root, pos, diff);
	}

	int query(int start, int end) {
		return this->queryHelper(this->root, start, end);
	}

};

void test() {
	auto bruteforce = [](vector<int>& arr, int start, int end) {
		int res = INT_MAX;
		for (int i = start;i <= end;i++) {
			res = min(arr[i], res);
		}
		return res;
	};
	int sz = rand() % 100 + 1;
	vector<int> arr;
	for (int i = 0;i < sz;i++) arr.push_back(rand() & 1000000 + 1);
	SegmentTree* sg = new SegmentTree(arr);
	bool allPassed = true;
	int qq = rand() % 1000 + 1;
	for (int i = 0;i < qq;i++) {
		int start = rand() % sz;
		int end = rand() % sz;
		if (start > end) swap(start, end);
		int bf = bruteforce(arr, start, end);
		int check = sg->query(start, end);
		if (bf == check) {}
		else {
			allPassed = false;
			cout << "brute:" << bf << " segtree: " << check << endl;
			cout << "FAILED!\n";
		}
	}
	if (allPassed) {
		cout << qq << " TESTS PASSED!";
	}
}

int main() {
	// vector<int> arr = { 3,4,7,6,2,2,4,3 };
	// SegmentTree* sg = new SegmentTree(arr);
	// cout << "before update:\n";
	// sg->printSegTree();
	// sg->update(3, -12);
	// cout << "after update:\n";
	// sg->printSegTree();
	// cout << "query: (4,6)" << " ";
	// cout << sg->query(4, 6) << endl;
	test();
	return EXIT_SUCCESS;
}