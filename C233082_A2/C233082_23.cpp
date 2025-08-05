#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, m;
    cin >> n >> m;
    ll source;
    cin >> source;
    vector<ll> vis(n + 1, 0);
    vector<ll> dis(n + 1, 1e9);
    vector<vector<pair<ll, ll>>> adj(n + 1);
    set<pair<ll, ll>> st;
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vis[source] = 0;
    dis[source] = 0;
    st.insert({0, source});
    vector<ll> par(n + 1, -1);

    while (!st.empty())
    {
        auto it = st.begin();
        ll wt = it->first;
        ll v = it->second;
        st.erase(it);
        if (vis[v])
            continue;
        vis[v] = 1;
        for (auto x : adj[v])
        {
            ll u = x.first;
            ll w = x.second;
            if (dis[v] + w < dis[u])
            {
                par[u] = v;
                dis[u] = dis[v] + w;
                st.insert({dis[u], u});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
    ll v = 5;
    vector<int> path;
    while (v != -1)
    {
        path.push_back(v);
        v = par[v];
    }
    reverse(path.begin(), path.end());
    for (auto it : path)
    {
        cout << it << " ";
    }
}