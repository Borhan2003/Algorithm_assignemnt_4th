#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mat(n + 1, vector<ll>(n + 1, 1e9));
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        mat[u][v] = min(wt, mat[u][v]);
        mat[v][u] = min(wt, mat[v][u]);
    }
    for (int i = 1; i <= n; i++)
    {
        mat[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                mat[i][j] = min(mat[i][k] + mat[k][j], mat[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mat[i][j] == 1e9)
            {
                cout << "-1";
            }
            else
            {
                cout << mat[i][j] << " ";
            }
        }
        cout << endl;
    }
}