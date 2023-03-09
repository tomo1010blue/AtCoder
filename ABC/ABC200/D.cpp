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

void output(int s) {
	vector<int> a;
	int i = 1;
	while(s) {
		if(s&1) a.pb(i);
		++i;
		s >>= 1;
	}
	cout << sz(a);
	for(int x : a) cout << " " << x;
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	chmin(n, 8);
	vector<int> st(200);
	repl(s, 1, (1<<n)) {
		int x = 0;
		rep(i, n) if(s >> i & 1) x = (x + a[i]) % 200;
		if(!st[x]) st[x] = s;
		else {
			cout << "Yes" << endl;
			output(s);
			output(st[x]);
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}