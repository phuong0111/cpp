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

int arr[100];

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
    int a, b;
    cin >> tc;
    while (tc--) {
        int res = 0;
        cin >> a >> b;
        a -= (a/b)*b;
        if (a == 0) {cout << 0 << "\n"; continue;}

        int tmp = 1;
        while (true) {
            int _ = b>>tmp;
            if (_ == 0 or (_ << tmp) != b) break;
            tmp++;
            if (a < _) continue;
            a -= _;
            res += _ * ((2<<(tmp-2))-1);
        }
        if (a > 0) {
            cout << -1 << "\n"; continue;
        }
        cout << res << "\n";
    }
    return;
}

int main() {
    Inp();
    Solve();
    return 0;
}