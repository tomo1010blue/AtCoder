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
	int a = 10 * (int)(s[0] - '0') + (int)(s[1] - '0');
	int b = 10 * (int)(s[2] - '0') + (int)(s[3] - '0');
	if(a >= 1 && a <= 12) {
		if(b >= 1 && b <= 12) cout << "AMBIGUOUS" << endl;
		else cout << "MMYY" << endl;
	}
	else {
		if(b >= 1 && b <= 12) cout << "YYMM" << endl;
		else cout << "NA" << endl;
	}
	return 0;
}