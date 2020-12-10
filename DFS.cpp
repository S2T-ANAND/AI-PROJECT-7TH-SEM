//water jug problem
//using dfs
#include "bits/stdc++.h"
using namespace std;
int M,N,REQ;
map<pair<int,int>, bool> mp;
vector <pair<int, int>> vp;
bool dfs(int x, int y)
{
	mp[{x, y}] = true;
	if (x == REQ || y == REQ) return vp.push_back({x, y}), 1;
	int x1 = x, y1 = y;
	if (y1 < N) {
		int t = min(x1 + y1, N);
		x1 -= (t - y1);
		y1 = t;
	} else y1 = N;
	if (mp.find({x1, y1}) == mp.end()) {
		if (auto val = dfs(x1, y1); val)
		return vp.push_back({x, y}), 1;
	}
	int x2 = x, y2 = y;
	if (x2 < M) {
		int t = min(x2 + y2, M);
		y2 -= (t - x2);
		x2 = t;
	} else x2 = M;
	if (mp.find({x2, y2}) == mp.end()) {
		if (auto val = dfs(x2, y2); val)
		return vp.push_back({x, y}), 1;
	}
	if (mp.find({0, y}) == mp.end()) {
		if (auto val = dfs(0, y); val)
		return vp.push_back({x, y}), 1;
	}
	if (mp.find({x, 0}) == mp.end()) {
		if (auto val = dfs(x, 0); val)
		return vp.push_back({x, y}), 1;
	}
	if (x == 0 && mp.find({M, y}) == mp.end()) {
		if (auto val = dfs(M, y); val)
		return vp.push_back({x, y}), 1;
	}
	if (y == 0 && mp.find({x, N}) == mp.end()) {
		if (auto val = dfs(x, N); val)
		return vp.push_back({x, y}), 1;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> M >> N >> REQ;
	bool ans = dfs(0, 0);
	if (ans) cout << " possible " << endl;
	else cout << "not possible" << endl;
	reverse(vp.begin(),vp.end());
	for (auto &[x, y] : vp) cout << x <<" "<< y << endl;
	return 0;
}
