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
	int t;
	cin >> t;
	while(t--) {
		int n;
		ll k;
		cin >> n >> k;
		k %= 2 * n;
		string s;
		cin >> s;
		string ans = "Yes";
		if(n >= k) {
			string sf1 = s.substr(0, k);
			string sf2 = s.substr(0, n-k);
			string sb1 = s.substr(n-k);
			string sb2 = s.substr(k);
			if(sf1 != sb1) ans = "No";
			string sf2r = sf2;
			reverse(all(sf2r));
			if(sf2r != sf2) ans = "No";
			string sb2r = sb2;
			reverse(all(sb2r));
			if(sb2r != sb2) ans = "No";
		} else if(k < 2*n) {
			string sf = s.substr(0, 2*n-k);
			string sb = s.substr(2*n-k);
			reverse(all(s));
			s += sf;
			string sr = s;
			reverse(all(sr));
			if(s != sr) ans = "No";
			string sbr = sb;
			reverse(all(sbr));
			if(sbr != sb) ans = "No";
		}
		cout << ans << endl;
	}
	return 0;
}