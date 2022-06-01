#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fo(i, b, e) for (ll i = b; i < e; ++i)
#define iter(i, b, e) ofr(auto i = b; i != e; ++i)

const int inf = 1e8 + 7;
const ll linf = 1e17 + 7;
const int maxn = 1e5 + 6;
const int maxm = 1e6 + 6;
int n;
vector<string> vs(3);
//vector<vector<bool>> m(3, vector<bool>(maxn));
int main()
{
    cin >> n;
    for (int i = 0; i < 3; ++i)
    {
        cin >> vs[i];
    }
    bool c1 = true;
    bool c2 = false;
    int cnt = 0;
    int i = 0, j = 0;
    for (; i < 3; ++i)
    {
        for (; j < n; ++j)
        {
            if (vs[i][j] == '#')
            {
                c1 = false;
                c2 = true;
                if (i != 2)
                {
                    ++cnt;
                }
                break;
            }
        }
        if (vs[i][j] == '#')
        {
            break;
        }
    }
    for (; i < 2; ++i)
    {
        for (; j < n; ++j)
        {
            if (vs[i][j] == '#')
            {
                ++cnt;
            }
        }
    }
    int res = 0;
    if (c1)
    {
        if (n & 1)
        {
            res = n - 1;
        }
        else
        {
            res = n;
        }
    }
    else if (c2)
    {
        res = n/3*2;
    }
    cout << res;
    return 0;
}