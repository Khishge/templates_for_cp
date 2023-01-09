template<typename T>
struct fenwick_tree {
	int N;
	T E;
	vector<T> bit, arr;
	fenwick_tree(int n, T e = 0) { // empty!?
		swap(n, N);
		swap(e, E);
		bit.resize(N + 1, E);
		arr.resize(N, E);
	}
	void set(int ind, T val) {
		add(ind, val - arr[ind]);
	}
	void add(int ind, T val) {
		arr[ind] += val;
		++ind;
		while(ind <= N) {
			bit[ind] += val;
			ind += ind & -ind;
		}
	}
	T at(int ind) {
		return arr[ind];
	}
	T pref_sum(int ind) {
		T total = E;
		++ind;
		while(ind > 0) {
			total += bit[ind];
			ind -= ind & -ind;
		}
		return total;
	}
	T query(int L, int R) {
		return pref_sum(R) - pref_sum(L - 1);
	}
};
