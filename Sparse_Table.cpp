template<typename T>
struct Sparse_Table {
	int lgflr(int x) {
		return 31 - __builtin_clz(x);
	}
	T f(T x, T y) { // implement !!!
	}
	int N, K;
	vector<vector<T>> st;
	void init(vector<T> a) {
		N = (int) a.size();
		K = lgflr(N);
		st = vector<vector<T>>(K + 1, vector<T>(N));
		swap(st[0], a);
		for(int i = 1; i <= K; ++i) {
			for(int j = 0; j + (1 << i) <= N; ++j) {
				st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	T query(int L, int R) {
		int i = lgflr(R - L + 1);
		return f(st[i][L], st[i][R - (1 << i) + 1]);
	}
};
