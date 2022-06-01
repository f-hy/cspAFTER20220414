#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fo(i, b, e) for (ll i = b; i < e; ++i)
#define iter(i, b, e) ofr(auto i = b; i != e; ++i)

const int inf = 1e8 + 7;
const ll linf = 1e15 + 7;
const int maxn = 1e5 + 6;
const int maxm = 1e6 + 6;
int n;
int a[maxn];

int main()
{
    cin >> n;
    int ma = 0, cnt = 0, res = 0;
    bool br = false;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (ma < a[i])
        {
            ma = a[i];
            cnt = 1;
            res = 1;
            br = false;
        }
        else if (ma == a[i] && !br)
        {
            ++cnt;
        }
        else if (ma == a[i] && br)
        {
            cnt = 1;
            br = false;
        }
        else
        {
            res = res > cnt ? res : cnt;
            br = true;
        }
    }
    res = res > cnt ? res : cnt;
    cout << ma << ' ' << res << "\n";
    return 0;
}