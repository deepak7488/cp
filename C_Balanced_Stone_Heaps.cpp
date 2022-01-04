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
bool check(int ans, vi &vp)
{

    int n = vp.size();
    vi vpn = vp;
    int d;
    for (int i = n - 1; i > 1; i--)
    {
        if (vpn[i] < ans)
        {
            return false;
        }
        d = min(vp[i], vpn[i] - ans) / 3;
        vpn[i] -= 3 * d;
        vpn[i - 1] += d;
        vpn[i - 2] += 2 * d;
    }
    return vpn[1] >= ans && vpn[0] >= ans;
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
        vi vp(n);
        loop(n)
        {
            cin >> vp[i];
        }
        int lo = 1, hi = vp[n - 1];
        int ans = 1;
        //cout << check(100, vp) << endl;
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if (check(mid, vp))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}