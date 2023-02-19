#include <bits/stdc++.h>
#include <atcoder/all>
#define fi first
#define se second
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, r) repl(i, 0, r)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(x) ((int) (x).size())
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using mint = modint998244353;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
template<class T> inline bool chmin(T &a, T b){
	if(a > b){a = b; return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a < b){a = b; return true;}
	return false;
}

struct modinv {
	int n; vector<mint> d;
	modinv(): n(2), d({0,1}) {}
	mint operator()(int i) {
		while (n <= i) d.push_back(-d[mint::mod()%n]*(mint::mod()/n)), ++n;
		return d[i];
	}
	mint operator[](int i) const { return d[i];}
} invs;
struct modfact {
	int n; vector<mint> d;
	modfact(): n(2), d({1,1}) {}
	mint operator()(int i) {
		while (n <= i) d.push_back(d.back()*n), ++n;
		return d[i];
	}
	mint operator[](int i) const { return d[i];}
} facts;
struct modfactinv {
	int n; vector<mint> d;
	modfactinv(): n(2), d({1,1}) {}
	mint operator()(int i) {
		while (n <= i) d.push_back(d.back()*invs(n)), ++n;
		return d[i];
	}
	mint operator[](int i) const { return d[i];}
} ifacts;
mint comb(int n, int k) {
	if (n < k || k < 0) return 0;
	return facts(n)*ifacts(k)*ifacts(n-k);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> exi(400001);
	rep(i, n) {
		int a;
		cin >> a;
		exi[a] = 1;
	}
	int need = 1;
	mint res = 0;
	rep(i, n+k) {
		if(need > k) break;
		int rest = k - need;
		res += comb(rest + i, i);
		if(!exi[i]) ++need;
	}
	cout << res.val() << endl;
	return 0;
}