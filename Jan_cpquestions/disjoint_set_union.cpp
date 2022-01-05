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
vector<int> par(co, 0);
vector<int> size(co, 0);
void make(int v)
{
    par[v] = v;
    size[v] = 1;
}
int find(int v)
{
    if (par[v] == v)
    {
        return v;
    }
    par[v] = find(par[v]);
    return par[v];
}
void union_t(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
    {
        return;
    }
    if (size[a] < size[b])
    {
        swap(a, b);
    }
    par[b] = a;
    size[a] += size[b];
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
        int n, k, x, y;
        cin >> n >> k;
        loop(n + 1)
        {
            make(i + 1);
        }
        while (k--)
        {
            cin >> x >> y;
            union_t(x, y);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (par[i] == i)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}