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
	int h, m;
	cin >> h >> m;
	int a = h / 10;
	int b = h % 10;
	int c = m / 10;
	int d = m % 10;
	if(a * 10 + c < 24 && b * 10 + d < 60) {
		cout << h << " " << m << endl;
		return 0;
	} else {  
    if(h==5 || h==6 || h==7 || h==8) cout<<"10"<<" "<<"0"<<endl;
    else if(h==15 || h==16 || h==17 || h==18) cout<<"20"<<" "<<"0"<<endl;
    else if(h==23 && a*10+c>=24) cout<<"0"<<" "<<"0"<<endl; 
    else cout<<h+1<<" "<<"0"<<endl;
  }
	return 0;
}