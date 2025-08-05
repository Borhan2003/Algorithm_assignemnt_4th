#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<vector<string>> ans;
bool safe(vector<string> &board, int row, int col)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 and j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 and j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}
void solve(vector<string> &board, int row)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (safe(board, row, col))
        {
            board[row][col] = 'Q';
            solve(board, row + 1);
            board[row][col] = '.';
        }
    }
}
int main()
{

    cin >> n;
    vector<string> board(n, string(n, '.'));
    solve(board, 0);
    for (auto x : ans)
    {
        for (auto r : x)
        {
            cout << r << endl;
        }
        cout << endl;
    }
}