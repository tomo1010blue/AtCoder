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
		cin >> n;
		string s;
		cin >> s;
		int cnt1 = 0, cnt2 = 0, num = 0;
		rep(i, n) {
			if(s[i] == '0') ++cnt1;
			else break;
		}
		rep(i, n) {
			if(s[n-i-1] == '0') ++cnt2;
			else break;
		}
		rep(i, n) if(s[i] == '1') ++num;
		if(num % 2 != 0) {
			cout << -1 << endl;
			continue;
		}
		if(num >= 4 || num == 0) {
			cout << num / 2 << endl;
			continue;
		}
		if(num == 2 && n - cnt1 - cnt2 == 2) {
			if(cnt1 >= 2 || cnt2 >= 2) cout << 2 << endl;
			else if(cnt1 == 1 && cnt2 == 1) cout << 3 << endl;
			else cout << -1 << endl;
		}
		else cout << 1 << endl;
	}
	return 0;
}