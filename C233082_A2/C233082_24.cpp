#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n, m,s;
    cin >> n >> m>>s;
    vector<pair<ll, pair<ll, ll>>> adj;

    vector<ll> dis(n + 1, 1e9);
    dis[s]=0;
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, {v, w}});
    }
    for (int i = 1; i < m; i++)
    {
        for (auto x : adj)
        {
            ll u = x.first;
            ll v = x.second.first;
            ll w = x.second.second;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
}