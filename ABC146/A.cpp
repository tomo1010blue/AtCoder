#include <bits/stdc++.h>
#include <atcoder/all>
#define fi first
#define se second
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using P = pair<double, double>;
using G = vector<vector<int>>;
using mint = modint1000000007;
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

int main(void)
{
	string s;
    cin >> s;
    if(s == "SUN") cout << 7 << endl;
    if(s == "MON") cout << 6 << endl;
    if(s == "TUE") cout << 5 << endl;
    if(s == "WED") cout << 4 << endl;
    if(s == "THU") cout << 3 << endl;
    if(s == "FRI") cout << 2 << endl;
    if(s == "SAT") cout << 1 << endl;
    return 0;
}