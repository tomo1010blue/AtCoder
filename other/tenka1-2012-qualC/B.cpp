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
	string s;
	cin >> s;
	int n = sz(s);
	map<char, int> mp;
	char m;
	rep(i, n) {
		m = s[i];
		++i;
		if(isdigit(s[i])) {
			if(s[i] == '1') {
				++i;
				mp[m]++;
			}
		}
		else mp[m]++;
		if(mp[m] == 5) break;
	}
	int k = 0, f = 0;
	auto out = [&] (char c) {
		cout << c;
		f = 1;
	};
	rep(i, n) {
		if(s[i] != m) {
			out(s[i]);
			++i;
			if(s[i] == '1') {
				++i;
				out('1');
				out('0');
			}
			else out(s[i]);
		}
		else {
			++i;
			if(isdigit(s[i])) {
				if(s[i] == '1') {
					++i;
					++k;
				}
				else {
					out(m);
					out(s[i]);
				}
			}
			else ++k;
		}
		if(k == 5) break;
	}
	if(f) cout << endl;
	else cout << 0 << endl;
	return 0;
}