template<typename T>
pair<T, T> ExtEuc(T a, T b) { // ax + by = gcd(a, b); returns {x, y}
	if(!b) {
		return make_pair(1, 0);
	}
	T u = a / b;
	pair<T, T> o = ExtEuc(b, a - u * b);
	return make_pair(o.second, o.first - u * o.second);
}

template<long long MOD_>
struct Modular {
	static const long long M0D = MOD_;
	long long value;
	Modular() { value = 0; }
	Modular(long long _v) { value = (-M0D <= _v && _v < M0D ? _v : _v % M0D); if(value < 0) value += M0D; }

	const long long operator ()() const { return value; }
	explicit operator long long() const { return (long long)value; }
	explicit operator int() const { return (int)value; }

	Modular& operator += (const Modular& a) { if((value += a.value) >= M0D) value -= M0D; return *this; }
	Modular& operator -= (const Modular& a) { if((value -= a.value) < 0) value += M0D; return *this; }
	Modular& operator ++() { return (*this) += 1; }
	Modular& operator --() { return (*this) -= 1; }
	Modular operator ++(int) { Modular res(*this); (*this) += 1; return res; }
	Modular operator --(int) { Modular res(*this); (*this) -= 1; return res; }
	Modular operator -() const { return Modular(-value); }
	Modular& operator *= (const Modular& a) { value = value * a.value % M0D; return *this; }
	Modular& operator /= (const Modular& a) { return (*this) *= inverse(a); }
	friend Modular operator + (const Modular& a, const Modular& b) { return Modular(a) += b; }
	friend Modular operator * (const Modular& a, const Modular& b) { return Modular(a) *= b; }
	friend Modular operator - (const Modular& a, const Modular& b) { return Modular(a) -= b; }
	friend Modular operator / (const Modular& a, const Modular& b) { return Modular(a) /= b; }
	
	friend bool operator == (const Modular& a, const Modular& b) { return a.value == b.value; }
	friend bool operator != (const Modular& a, const Modular& b) { return a.value != b.value; }
	friend bool operator < (const Modular& a, const Modular& b) { return a.value < b.value; }

	friend Modular pow(Modular a, long long p) { assert(p >= 0); Modular ans = 1; for(; p; p >>= 1LL, a *= a) if(p & 1LL) ans *= a; return ans; }
	friend Modular inverse(const Modular& a) { assert(a.value != 0); return Modular(ExtEuc((long long)a.value, M0D).first); }

	friend ostream& operator << (ostream& os, const Modular& a) { os << a.value; return os; }
	friend istream& operator >> (istream& is, Modular& a) { long long x; is >> x; a.value = (int)Modular(x); return is; }
};

using mint = Modular<(long long)?>;

vector<mint> fact{1};
vector<mint> inv_fact{1};

mint nCk(int n, int k) { // N Choose K
	if(n < 0 || k > n) {
		return 0;
	}
	while((int)fact.size() <= n) {
		fact.push_back(fact.back() * (int)fact.size());
		inv_fact.push_back(inverse(fact.back()));
	}
	return fact[n] * inv_fact[k] * inv_fact[n - k];
}

void preFI(int sz) {
	fact.resize(sz + 1);
	inv_fact.resize(sz + 1);
	for(int i = 1; i <= sz; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	inv_fact[sz] = inverse(fact[sz]);
	for(int i = sz - 1; i > 0; --i) {
		inv_fact[i] = (i + 1) * inv_fact[i + 1];
	}
}
