#include <math.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
const int MAX = 2e5 + 5;
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define FORD(i, j, k) for (int i = j; i > k; i--)
#define FORA(x, obj) for (auto x : obj)
#define vii vector<vector<int>>
#define vi vector<int>
#define eb emplace_back

int arr[5000];
int dp[5000];

void Inp() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    return;
}

void Solve() {
    int tc;
    int n;
    cin >> tc;
    while (tc--) {
        int res = 0;
        cin >> n;
        FOR(i, 0, n) cin >> arr[i];
        sort(arr, arr+n);

        FOR(i, 0, n) 
    }
    return;
}

int main() {
    Inp();
    Solve();
    return 0;
}