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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector a(2*n, vector<char>(m));
	rep(i, 2*n) rep(j, m) cin >> a[i][j];
	vector<P> rank;
	rep(i, 2*n) rank.eb(0, i);
	auto ja = [&](int x, int y, int z) -> void {
		if(a[rank[x].se][z] == 'G' && a[rank[y].se][z] == 'C') rank[x].fi--;
		if(a[rank[x].se][z] == 'C' && a[rank[y].se][z] == 'P') rank[x].fi--;
		if(a[rank[x].se][z] == 'P' && a[rank[y].se][z] == 'G') rank[x].fi--;
	};
	rep(i, m) {
		rep(j, n) {
			ja(2*j, 2*j+1, i);
			ja(2*j+1, 2*j, i);
		}
		sort(all(rank));
	}
	for(auto [x, y] : rank) cout << y + 1 << endl;
	return 0;
}