#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define co 200005
#define int long long int
#define Int int
#define vi vector<int>
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define sz(x) ((int)(x).size())
#define loop(n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define endl "\n"
vector<vi> adj(co);
vector<bool> vis(co);
void dfs(int vertex, int par = 0)
{
    //take action after entering the vertex
    vis[vertex] = true;
    for (auto child : adj[vertex])
    {
        if (vis[child])
            continue;
        // take action before entering the child node
        dfs(child, vertex);
        // take action after exiting the child node
    }
    // take action before exiting the vertex
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n;
        vi vp(n);
        loop(n)
        {
            cin >> vp[i];
        }
        cin >> x;
        loop(n)
        {
            vp[i] -= x;
        }
    }
    return 0;
}