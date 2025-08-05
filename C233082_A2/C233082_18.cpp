#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
vector<bool> vis;
void dfs(int s)
{
    vis[s] = true;
    cout << s << " ";
    for (auto x : adj[s])
    {
        if (!vis[x])
        {
            dfs(x);
        }
    }
}
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
    dfs(1);
}
