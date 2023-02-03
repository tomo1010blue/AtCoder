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
	int q, l;
	cin >> q >> l;
	ll si = 0;
	int ans = 0;
	stack<P> st;
	while(q--) {
		string s;
		cin >> s;
		if(s == "Push") {
			int n, m;
			cin >> n >> m;
			if(si > l - n) {
				cout << "FULL" << endl;
				return 0;
			}
			si += n;
			st.push(P(n, m));
		}
		if(s == "Pop") {
			int n;
			cin >> n;
			if(si < n) {
				cout << "EMPTY" << endl;
				return 0;
			}
			si -= n;
			int d = 0;
			P p;
			while(d < n) {
				p = st.top();
				st.pop();
				d += p.fi;
			}
			if(d == n) continue;
			st.push(P(d - n, p.se));
		}
		if(s == "Top") {
			if(!si) {
				cout << "EMPTY" << endl;
				return 0;
			}
			P p = st.top();
			cout << p.se << endl;
		}
		if(s == "Size") cout << si << endl;
	}
	cout << "SAFE" << endl;
	return 0;
}