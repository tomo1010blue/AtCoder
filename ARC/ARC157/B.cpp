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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int x = 0, y = 0;
	rep(i, n) if(s[i] == 'X') ++x;
	y = n - x;
	if(x == 0) {
		cout << n - k - 1 << endl;
		return 0;
	}
	if(y == 0) {
		cout << k - 1 << endl;
		return 0;
	}
	if(x <= k) {
		k -= x;
		x = y;
		rep(i, n) {
			if(s[i] == 'X') s[i] = 'Y';
			else s[i] = 'X';
		}
	}
	int sum = 0;
	int ans = 0;
	if(k == 0) {
		rep(i, n) {
			if(s[i] == 'X')	{
				chmax(ans, sum);
				sum = 0;
			}
			else ++sum;
		}
		chmax(ans, sum);
		cout << ans-1 << endl;
		return 0;
	}
	int num = 0;
	vector<int> f, b;
	rep(i, n-1) {
		++num;
		if(s[i+1] == 'X') {
			f.pb(num);
			num = 0;
		}
	}
	if(num != 0) f.pb(num);
	else f.pb(1);
	if(s[0] == 'Y') {
		int a = f.front();
		f.erase(f.begin());
		f[0] += a;
	}
	num = 0;
	rep(i, n-1) {
		--num;
		if(s[i] == 'X') {
			b.pb(num);
			num = 0;
		}
	}
	if(num != 0) {
		if(s[n-1] == 'X') b.pb(num-1);
		else b[x-1] += num-1;
	}
	else {
		if(s[n-1] == 'X') b.pb(-1);
		else b[x-1] -= 1;
	}
	rep(i, k) ans += f[i];
	int cur = ans;
	rep(i, x-k) {
		cur += f[i+k] + b[i];
		chmax(ans, cur);
	}
	cout << ans-1 << endl;
	return 0;
}