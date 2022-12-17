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
	int n, k, q;
	cin >> n >> k >> q;
	vector<bool> p(n, false);
	rep(i, k) {
		int a;
		cin >> a;
		--a;
		p[a] = true;
	}
	rep(i, q) {
		int l;
		cin >> l;
		int count = 0;
		rep(j, n) {
			if(p[j]) ++count;
			if(count == l) {
				if(j == n-1) break;
				if(p[j+1]) break;
				p[j] = false;
				p[j+1] = true; 
				break;
			}
		}
	}
	rep(i, n) if(p[i]) cout << i+1 << endl;
	return 0;
}