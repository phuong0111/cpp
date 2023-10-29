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

int n, x;
int arr[MAX];

void Inp() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    return;
}

ll volume_of_water(int h){
    ll res = 0;
    FOR(i, 0, n) res += 1ll * max(h-arr[i], 0);
    return res;
}

void Solve() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> x;
        FOR(i, 0, n) cin >> arr[i];

        int low = 0; int high = 1<<30;
        while(low < high) {
            int mid = low + (high-low+1)/2;
            ll volume = volume_of_water(mid);
            if(volume > x) high = mid-1;
            else low = mid;
        }
        cout << low << "\n";
    }
    return;
}

int main() {
    Inp();
    Solve();
    return 0;
}