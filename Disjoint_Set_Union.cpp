struct DSU {
	vector<int> E;
	void init(int n) { E = vector<int>(n, -1); }
	int parent(int x) { return E[x] < 0 ? x : E[x] = parent(E[x]); }
	bool sameset(int x, int y) { return parent(x) == parent(y); }
	int size(int x) { return -E[parent(x)]; }
	bool unite(int x, int y) {
		x = parent(x);
		y = parent(y);
		if(x == y) {
			return false;
		}
		if(E[x] > E[y]) {
			swap(x, y);
		}
		E[x] += E[y];
		E[y] = x;
		return true;
	}
};
