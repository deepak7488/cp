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
        int n;
        cin >> n;
        vector<double> vp(n);
        loop(n)
        {
            cin >> vp[i];
        }
        int ans = n - 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {

                cnt = 0;
                double d = (vp[j] - vp[i]) / ((j - i) * 1.0);

                double first = vp[j] - (j)*1.0 * (d);
                for (int k = 0; k < n; k++)
                {

                    if (abs(vp[k] - first) >= 0.01)
                    {
                        cnt++;
                    }
                    first += d;
                }

                ans = min(ans, cnt);
            }
        }
        cout << ans << endl;
    }
    return 0;
}