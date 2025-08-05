#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct act
{
    ll index, start, end;
};
bool cmp(act a, act b)
{
    return a.end < b.end;
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> s(n), e(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> e[i];
    }
    vector<act> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {i, s[i], e[i]};
    }
    sort(v.begin(), v.end(), cmp);
    vector<ll> ans;
    ll last = v[0].end;
    ans.push_back(v[0].index + 1);
    for (int i = 1; i < n; i++)
    {
        if (v[i].start >= last)
        {
            ans.push_back(v[i].index + 1);
            last = v[i].end;
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}