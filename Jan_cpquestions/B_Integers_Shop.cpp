#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define co 200005
// #define int long long int
#define Int int
#define vi vector<int>
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define sz(x) ((int)(x).size())
#define loop(n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define endl "\n"
// vector<vi> adj(co);
// vector<bool> vis(co);
// void dfs(int vertex, int par = 0)
// {
//     //take action after entering the vertex
//     vis[vertex] = true;
//     for (auto child : adj[vertex])
//     {
//         if (vis[child])
//             continue;
//         // take action before entering the child node
//         dfs(child, vertex);
//         // take action after exiting the child node
//     }
//     // take action before exiting the vertex
// }
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
        int n, l, r, x;
        cin >> n;
        int mina = INT32_MAX, cost = INT32_MAX, maxa = INT32_MIN, costl = INT32_MAX, costr = INT32_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> l >> r >> x;
            if ((mina > l && maxa < r) || (mina >= l && maxa < r) || (mina > l && maxa <= r))
            {
                cost = x;
                // if(mina==l || maxa==r){
                // costl = min(costl, x);
                // costr = min(costr, x);}
                costl = mina == l ? min(costl, x) : x;
                costr = maxa == r ? min(costr, x) : x;
                // mp[l] = mp[l] != 0 ? min(mp[l], x) : x;
                // mp[r] = mp[r] != 0 ? min(mp[r], x) : x;
            }
            else if (mina > l || maxa < r)
            {
                // cost = x + mp[mina > l ? maxa : mina];
                cost = x + (mina > l ? costr : costl);
                // mp[mina > l ? l : r] = x;
                (mina > l) ? costl = x : costr = x;
            }
            else if (mina == l && maxa == r)
            {
                cost = min(cost, x);
                costl = min(costl, x);
                costr = min(costr, x);
                // mp[l] = min(x, mp[l]);
                // mp[r] = min(x, mp[r]);
            }
            else if (mina == l || maxa == r)
            {
                // cost = min(cost, x + mp[maxa == r ? mina : maxa]);
                cost = min(cost, x + (mina == l ? costr : costl));
                // mp[mina == l ? l : r] = min(mp[mina == l ? l : r], x);
                (mina == l) ? costl = min(costl, x) : costr = min(costr, x);
            }
            mina = min(mina, l);
            maxa = max(maxa, r);
            cout << cost << endl;
        }
    }
    return 0;
}
