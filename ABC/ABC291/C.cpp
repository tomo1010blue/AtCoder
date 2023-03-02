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
	int n;
	cin >> n;
	string s;
	cin >> s;
	set<P> st;
	int x = 0, y = 0;
	st.insert(P(x, y));
	rep(i, n) {
		if(s[i] == 'R') ++x;
		else if(s[i] == 'L') --x;
		else if(s[i] == 'U') ++y;
		else if(s[i] == 'D') --y;
		if(st.count(P(x, y))) {
			cout << "Yes" << endl;
			return 0;
		}
		st.insert(make_pair(x, y));
	}
	cout << "No" << endl;
	return 0;
}