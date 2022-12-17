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
using mint = modint1000000007;
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

vector<pair<int, int>> prime_factorize(int n) {
	vector<pair<int, int>> res;
	for(int a = 2; a * a <= n; ++a) {
		if(n % a != 0) continue;
		int ex = 0;
		while(n % a == 0) {
			++ex;
			n /= a;
		}
			res.pb({a, ex});
	}
	if(n != 1) res.pb({n, 1});
	return res;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int g = 0;
	int G = 0;
	rep(i, n) G = gcd(G, a[i]);
	bool ok = true;
	int ans = 0;
	rep(i, n) {
		a[i] /= G;
		vector<pair<int, int>> v = prime_factorize(a[i]);
		int div2 = 0, div3 = 0;
		for(auto x : v) {
			if(x.fi == 2) {
				a[i] /= (int) pow(2, x.se);
				ans += x.se;
			} else if(x.fi == 3) {
				a[i] /= (int) pow(3, x.se);
				ans += x.se;
			} else {
				break;
			}
		}
		if(i == 0) g = a[i];
		else {
			if(g != a[i]) ok = false;
		}
	}
	if(!ok) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}