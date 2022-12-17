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
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
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
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	rep(i, n) {
		rep(j, n) {
			rep(k, 8) {
				int u = i + dx[k] * 5;
				int v = j + dy[k] * 5;
				if(u < 0 || u >= n || v < 0 || v >= n) continue;
				int cnt = 0;
				rep(l, 6) {
					if(s[i+dx[k]*l][j+dy[k]*l] == '.') ++cnt;
				}
				if(cnt <= 2) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}