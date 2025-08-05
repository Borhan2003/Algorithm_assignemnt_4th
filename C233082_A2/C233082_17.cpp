#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<bool> vis;

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vector<ll>>(n + 1);
    vis = vector<bool>(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> level(n + 1, 0), par(n + 1, -1);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto x : adj[u])
        {
            if (!vis[x])
            {
                level[x] = level[u] + 1;
                par[x] = u;
                q.push(x);
                vis[x] = true;
            }
        }
    }
    ll v;
    cin >> v;
    vector<int> path;
    while (v != -1)
    {
        path.push_back(v);
        v = par[v];
    }
    reverse(path.begin(), path.end());
    cout << endl;
    for (auto it : path)
    {
        cout << it << " ";
    }
}
