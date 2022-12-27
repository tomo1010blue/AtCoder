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
	int m;
	cin >> m;
	if (m < 100) {
		cout << 0 << 0 << endl;
	}
	else if (100 <= m && m < 1000) {
		cout <<  0 << m / 100 << endl;
	}
	else if (1000 <= m && m <= 5000) {
		cout << m / 100 << endl;
	}
	else if (6000 <= m && m <= 30000) {
	cout << m / 1000 + 50 << endl;
	}
	else if (35000 <= m && m <= 70000) {
		cout << (m / 1000 - 30) / 5 + 80 << endl;
	}
	else if (70000 < m) {
		cout << 89 << endl;
	}
	return 0;
}