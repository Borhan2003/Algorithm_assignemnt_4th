#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    char ch;
    ll freq;
    Node *left, *right;
};
Node *createnode(char ch, ll freq, Node *left = nullptr, Node *right = nullptr)
{
    Node *nn = new Node;
    nn->ch = ch;
    nn->freq = freq;
    nn->left = left;
    nn->right = right;
    return nn;
}
void encode(Node *root, string str, map<char, string> &huff)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        huff[root->ch] = str;
    }
    encode(root->left, str + "0", huff);
    encode(root->right, str + "1", huff);
}
void decode(Node *root, string &str, int &indx)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }
    indx++;
    if (str[indx] == '0')
        decode(root->left, str, indx);
    else
        decode(root->right, str, indx);
}
void createrootree(string text)
{
    map<char, int> freq;
    for (auto ch : text)
    {
        freq[ch]++;
    }
    set<pair<ll, Node *>> st;
    for (auto it : freq)
    {
        Node *nn = createnode(it.first, it.second);
        st.insert({it.second, nn});
    }
    while (st.size() > 1)
    {
        auto it = st.begin();
        Node *left = it->second;
        st.erase(it);
        it = st.begin();
        Node *right = it->second;
        st.erase(it);
        Node *nn = createnode('\0', left->freq + right->freq, left, right);
        st.insert({nn->freq, nn});
    }
    Node *root = st.begin()->second;
    map<char, string> huff;
    encode(root, "", huff);
    string binary = "";
    for (auto it : text)
    {
        binary += huff[it];
    }
    int indx = -1;
    while (indx < (int)binary.size() - 1)
    {
        decode(root, binary, indx);
    }
}
int main()
{
    string text;
    getline(cin, text);

    createrootree(text);
    cout << endl;
    return 0;
}
