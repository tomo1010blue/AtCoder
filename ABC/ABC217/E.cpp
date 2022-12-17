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
	int Q;
	cin >> Q;
	priority_queue<int, vector<int>, greater<int>> pq;
	queue<int> q;
	while(Q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int x;
			cin >> x;
			q.push(x);
		}
		if(t == 2) {
			if(!pq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			} else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		if(t == 3) {
			while(!q.empty()) {
				pq.push(q.front());
				q.pop();
			}
		}
	}
	return 0;
}