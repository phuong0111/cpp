#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <math.h>
#include <cstring>

using namespace std;

typedef long long int ll;
const int MAX = 2e5+5;
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define FORD(i, j, k) for (int i = j; i > k; i--)
#define FORA(x, obj) for (auto x : obj)
#define vii vector<vector<int>> 
#define vi vector<int>
#define eb emplace_back

int n, k;
string str;

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
    cin >> tc;
    while (tc--) {
        cin >> n >> k >> str;
        int res = 0;

        FOR(i, 0, n) if(str[i] == 'B') {
            res++;
            i+=(k-1);
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