#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fo(i, b, e) for (ll i = b; i < e; ++i)
#define iter(i, b, e) ofr(auto i = b; i != e; ++i)

const int inf = 1e8 + 7;
const ll linf = 1e15 + 7;
const int maxn = 1e2 + 6;
const int maxm = 1e6 + 6;
const int maxa = 1e3 + 3;
const int maxx = 1e4 + 4;
int n, x;
int a[maxa];
vector<int> f(maxx, inf);

int main()
{
    cin >> n >> x;
    f[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[a[i]] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            if (j - a[i] >= 0)
                f[j] = min(f[j], f[j - a[i]] + 1);
        }
    }
    cout << f[x];
    return 0;
}