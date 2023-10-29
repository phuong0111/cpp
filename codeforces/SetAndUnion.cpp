#include <iostream>
#include <set>
using namespace std;

typedef long long int ll;
#define MAX 100
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define FORD(i, j, k) for (int i = j; i > k; i--)
#define FORA(x, obj) for (auto x : obj)

int n, m;

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
        int ans = 0;

        set<int> global_set;
        set<int> v[n];
        FOR(i, 0, n) {
            cin >> m;
            FOR(j, 0, m) {
                cin >> tmp;
                v[i].insert(tmp);
                global_set.insert(tmp);
            }
        }

        FORA(x, global_set) {
            set<int> temp;
            FOR(i, 0, n) {
              if (v[i].find(x) == v[i].end())
                temp.insert(v[i].begin(), v[i].end());
            }
            ans = max(ans, (int)temp.size());
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