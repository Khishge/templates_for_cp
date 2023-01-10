const long long INF = 0x3f3f3f3f3f3f3f3f; // here

void Dijkstra(int st, vector<long long>& D, vector<int>& P) { // here Dis type
	int n = (int) size(adj);
	D.resize(n, INF); // make sure to declare larger #INF# for long long
	P.resize(n, -1);
	auto cmp = [&D] (const int& a, const int& b) -> bool { return (D[a] < D[b] || (D[a] == D[b] && a < b)); };
	set<int, decltype(cmp)> s(cmp);
	D[st] = 0;
	s.insert(st);
	while(!s.empty()) {
		int cur = *begin(s);
		s.erase(begin(s));
		for(auto& u : adj[cur]) {
			int to = u.first;
			long long len = u.second; // here
			if(D[cur] + len < D[to]) {
				s.erase(to);
				D[to] = D[cur] + len;
				P[to] = cur;
				s.insert(to);
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
