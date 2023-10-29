#include <iostream>
#include <set>
using namespace std;

typedef long long int ll;
const int MAX = 2e5+5;
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define FORD(i, j, k) for (int i = j; i > k; i--)
#define FORA(x, obj) for (auto x : obj)

int n, m;
int arr[MAX];
ll prefix_sum[MAX];

void Inp() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    return;
}

void Solve() {
    int tc;
    int tmp;
    cin >> tc;
    while (tc--) {
        cin >> n;
        prefix_sum[n+1] = 0;
        FOR(i, 1, n+1) cin >> arr[i];
        FORD(i, n, 0) prefix_sum[i] = prefix_sum[i+1] + 1ll*max(arr[i], 0);

        ll ans = 0;
        FOR(i, 1, n+1){
            ans = (i & 1) ? max(ans, 1ll * arr[i] + prefix_sum[i + 1])
                          : max(ans, 1ll * prefix_sum[i + 1]);
        }

        cout << ans << "\n";
    }
    return;
}

int main() {
    Inp();
    Solve();
    return 0;
}