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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	set<P> st;
	vector<ll> x(n);
	vector<ll> y(n);
	rep(i, n) {
		cin >> x[i] >> y[i];
	}
	rep(i, n) {
		repl(j, i+1, n) {
			ll Dx = x[i] - x[j];
			ll Dy = y[i] - y[j];
			ll d = gcd(Dx, Dy);
			Dx /= d;
			Dy /= d;
			st.insert(make_pair(Dx, Dy));
			Dx *= -1;
			Dy *= -1;
			st.insert(make_pair(Dx, Dy));
		}
	}
	cout << st.size() << endl;
	return 0;
}