const long long INF = 0x3f3f3f3f3f3f3f3f;

void Dijkstra(int st, vector<long long>& D, vector<int>& P) {
	int n = (int) size(adj);
	D.resize(n, INF); // make sure to declare larger #INF# for long long
	P.resize(n, -1);
	using tp = pair<long long, int>;
	priority_queue<tp, vector<tp>, greater<tp>> pq;
	pq.push({0, st});
	D[st] = 0;
	while(!pq.empty()) {
		long long D_to_cur = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if(D_to_cur != D[cur]) {
			continue;
		}
		for(auto& u : adj[cur]) {
			int to = u.first;
			long long len = u.second;
			if(D[cur] + len < D[to]) {
				D[to] = D[cur] + len;
				P[to] = cur;
				pq.push({D[to], to});
			}
		}
	}
}

vector<int> Restore_Path(int st, int en, vector<int>& P) {
	vector<int> path;
	while(en != st) {
		path.push_back(en);
		en = P[en];
	}
	path.push_back(st);
	reverse(begin(path), end(path));
	return path;
}
