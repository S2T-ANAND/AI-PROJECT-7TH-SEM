#include "bits/stdc++.h"
using namespace std;
int M, N, REQ;
map <pair<int, int>,pair<int,int>> par;
map <pair<int,int>, bool>mp;
vector <pair <int, int>> vp;
signed main() {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        cin >> M>> N >> REQ;
        queue <pair<int, int>> qp;
        qp.push({0, 0});
        while (!qp.empty()) {
            auto [x, y] = qp.front(); qp.pop();
            if (mp[{x, y}]) continue;
            mp[{x,y}] = 1;
            if (y == REQ || x == REQ) {
                while (x != 0 || y != 0) {
                    vp.emplace_back(x, y);
                    auto p= par[{x, y}];
                    x = p.first;
                    y = p.second;
                }
                vp.emplace_back(0, 0); break;
            }
            //empty the jug
            if (x != 0  && mp[{0, y}] == 0) {
                qp.push({0, y});
                par[{0, y}] = {x, y};
            }
            if (y != 0 && mp[{x, 0}] == 0) {
                qp.push({x, 0});
                par[{x, 0}] = {x, y};
            }
            // fill the jug
            if (x == 0 && mp[{M, y}] == 0) {
                qp.push({M, y});
                par[{M, y}] = {x, y};
            }
            if (y == 0 && mp[{x, N}] == 0) {
                qp.push({x, N});
                par[{x, N}] = {x, y};
            }
            //from 1 to another
            int x1 = x, y1 = y;
            if (y1 < N) {
                int t = min(x1 + y1, N);
                x1 -= (t - y1);
                y1 = t;
            } else y1 = N;
            if (mp[{x1, y1}] == 0) {
                qp.push({x1, y1});
                par[{x1, y1}] = {x, y};
            }
            int x2 = x, y2 = y;
            if (x2 < M) {
                int t = min(x2 + y2, M);
                y2 -= (t - x2);
                x2 = t;
            } else x2 = M;
            if (mp[{x2, y2}] == 0) {
                qp.push({x2, y2});
                par[{x2, y2}] = {x, y};
            }
        }
        if (vp.size() == 0) return cout <<"NOT POSSIBLE" , 0;
        cout <<"POSSIBLE" << endl;
        reverse(vp.begin(), vp.end());
        for (auto &[x, y] : vp) cout << x << " "<< y << endl; 
}
