#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
vector<int> Rank, par;
int findupar(int node)
{
    if (node == par[node])
        return node;
    return par[node] = findupar(par[node]);
}
void unionbyrank(int u, int v)
{
    int pu = findupar(u);
    int pv = findupar(v);
    if (pu == pv)
        return;
    if (Rank[pu] < Rank[pv])
    {
        par[pu] = pv;
    }
    else if (Rank[pu] > Rank[pv])
    {
        par[pv] = pu;
    }
    else
    {
        par[pv] = pu;
        Rank[pu]++;
    }
}

int main()
{
    cin >> n >> m;
    Rank.resize(n + 1, 0);
    par.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    vector<pair<int, pair<int, int>>> e(m);

    for (int i = 0; i < m; i++)
    {
        ll int u, v, wt;
        cin >> u >> v >> wt;
        e[i] = {wt, {u, v}};
    }
    sort(e.begin(), e.end());
    ll cost = 0;
    vector<pair<ll, ll>> mst;
    for (auto x : e)
    {
        ll wt = x.first;
        ll u = x.second.first;
        ll v = x.second.second;
        if (findupar(u) != findupar(v))
        {
            unionbyrank(u, v);
            cost += wt;
            mst.push_back({u, v});
        }
    }
    cout << cost << endl;
    for (auto x : mst)
    {
        cout << x.first << " " << x.second << endl;
    }
}