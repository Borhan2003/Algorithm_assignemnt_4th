#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, m;
    cin >> n >> m;
    set<pair<ll, pair<ll, ll>>> e;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    ll start = 1;
    for (auto x : adj[start])
    {
        e.insert({x.second, {start, x.first}});
    }
    ll cost = 0;
    vector<pair<ll, ll>> mst;
    vector<ll> vis(n + 1, -1);
    vis[start] = 1;

    while (!e.empty())
    {
        auto it = e.begin();
        ll wt = it->first;

        ll u = it->second.first;
        ll v = it->second.second;

        e.erase(it);
        if (vis[v] != -1)
            continue;

        mst.push_back({u, v});
        vis[v] = 1;
        cost += wt;
        for (auto x : adj[v])
        {
            if (vis[x.first] == -1)
            {
                e.insert({x.second, {v, x.first}});
            }
        }
    }
    for (auto x : mst)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << cost << endl;
    return 0;
}