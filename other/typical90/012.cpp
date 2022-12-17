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
using G = vector<vector<bool>>;
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
	int h, w;
	cin >> h >> w;
	dsu d(h*w);
	int q;
	cin >> q;
	G g(h, vector<bool>(w, false));
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int r, c;
			cin >> r >> c;
			--r;
			--c;
			g[r][c] = true;
			rep(i, 4) {
				if(r+dy[i] < 0 || r+dy[i] >= h || c+dx[i] < 0 || c+dx[i] >= w) continue;
				if(g[r+dy[i]][c+dx[i]]) d.merge(r*w+c, (r+dy[i])*w+(c+dx[i]));
			}
		}
		if(t == 2) {
			int ra, ca, rb, cb;
			cin >> ra >> ca >> rb >> cb;
			--ra;
			--ca;
			--rb;
			--cb;
			if(g[ra][ca] == false || g[rb][cb] == false) {
				cout << "No" << endl;
				continue;
			}
			if(d.same(ra*w+ca, rb*w+cb)) cout << "Yes" <<  endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}