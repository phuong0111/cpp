#define _USE_MATH_DEFINES
#include <ctime>
#include <iostream>
#include <ostream>
#include <random>

using namespace std;

const long long INF_LL = 1e18;
const int INF = 2e9 + 100;
const long double EPS = 1e-6;
const int BLOCK = 550;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 2e6 + 100;
const int MOD = 1e9 + 7;

void sol() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> last(26, 0), prev(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prev[i + 1] = last[s[i] - 'a'];
        last[s[i] - 'a'] = i + 1;
    }
    vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= min(i, k); j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
            if (prev[i]) {
                int need_to_remove = j - (i - prev[i]);
                if (need_to_remove >= 0 && need_to_remove <= k) {
                    dp[i][j] =
                        (dp[i][j] - dp[prev[i] - 1][need_to_remove] + MOD) %
                        MOD;
                }
            }
        }
    }
    cout << dp[n][k] << "\n";
}

void solve() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // clock_t start, end;
    // start = clock();
    int T = 1;
    // cin >> T;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        // cerr << "Processing test = " << TestCase << '\n';
        // cout << "Case #" << TestCase << ": ";
        sol();
        // if (T) cout << '\n';
    }
//     end = clock();
//     cerr << "Time = " << (double)(end - start) / (double)CLOCKS_PER_SEC << '\n';
}

int main(int argc, char* argv[]) {
    // srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}