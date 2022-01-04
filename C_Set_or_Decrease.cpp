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
        int n, k;
        cin >> n >> k;
        vi vp(n);
        int mina = INT32_MAX;
        vi sum(n);

        loop(n)
        {
            cin >> vp[i];
            mina = min(mina, vp[i]);
        }
        sort(all(vp));
        sum[0] = vp[0];
        loop(n - 1)
        {
            sum[i + 1] += sum[i] + vp[i + 1];
        }

        int ans = INT32_MAX;
        //  cout << (-5) % 2 << endl;
        for (int i = 0; i < n; i++)
        {

            int p = max(0ll, ((sum[i] + (n - i - 1) * mina) - k) / (n - i) + ((((sum[i] + (n - i - 1) * mina) - k) % (n - i)) > 0));
            ans = min(ans, n - 1 - i + p);
        }
        cout << ans << endl;
    }
    return 0;
}