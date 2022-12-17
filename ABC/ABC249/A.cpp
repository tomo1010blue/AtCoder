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
	int a, b, c, d, e, f, x;
	cin >> a >> b >> c >> d >> e >> f >> x;
	int t_q = x / (a + c);
	int t_r = x % (a + c);
	if(t_r >= a) t_r = a;
	int T = a * b * t_q + t_r * b;
	int a_q = x / (d + f);
	int a_r = x % (d + f);
	if(a_r >= d) a_r = d;
	int A = d * e * a_q + a_r * e;
	if(A > T) cout << "Aoki" << endl;
	if(A < T) cout << "Takahashi" << endl;
	if(A == T) cout << "Draw" << endl;
	return 0;
}