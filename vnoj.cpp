#include <math.h>

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
const int MAX = 1e5 + 5;
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define FORD(i, j, k) for (int i = j; i > k; i--)
#define FORA(x, obj) for (auto x : obj)
#define vii vector<vector<int> >
#define vi vector<int>
#define eb emplace_back

void Inp() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    return;
}

// // A

// vii idx;
// vi orig, arr;
// int n;

// ll max_sub_arr() {
//     ll sum = 0;
//     ll max_sum = INT32_MIN;
//     ll min_prev_sum = 0;
//     FOR(i, 0, n) {
//         sum += 1ll*arr[i];
//         max_sum = max(max_sum, sum - min_prev_sum);
//         min_prev_sum = min(min_prev_sum, sum);
//     }
//     return max_sum;
// }

// void Solve(){
//     cin >> n;
//     arr.resize(n, INT32_MIN);
//     orig.resize(n);
//     idx.resize(1001);
//     FOR (i, 0, n) {
//         cin >> orig[i];
//         idx[orig[i] + 500].eb(i);
//     }

//     ll res = INT32_MIN;
//     FOR (i, 0, 1001) {
//         if (idx[i].empty()) continue;
//         FORA (y, idx[i]) arr[y] = orig[y];
        
//         res = max(res, max_sub_arr() - i + 500);
//     }
//     cout << res << "\n";
// }

// B
int n, q;
vi arr;
const int MOD = 2023;
int dp[105][105][105];

void Solve() {
    cin >> n;
    arr.resize(n);
    FOR (i, 0, n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    FOR (i, 0 ,n) dp[i][i][0] = 1;

    FOR (start, 0, n) FOR (cur, start, n) FOR (step, 0, n) {
        if (dp[start][cur][step] == 0) continue;

        
    }
}

int main() {
    Inp();
    Solve();
    return 0;
}