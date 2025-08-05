#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> ans;
ll n;
void generate(int indx, string s)
{
    if (indx == n)
    {
        cout << s << endl;
        return;
    }
    for (int i = indx; i < n; i++)
    {
        swap(s[indx], s[i]);
        generate(indx + 1, s);
        swap(s[indx], s[i]);
    }
}
int main()
{

    cin >> n;
    string s;
    cin >> s;
    generate(0, s);
}