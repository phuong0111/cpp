#include <math.h>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int ll;
const int MAX = 2e5 + 5;
const int MOD = 1e9 + 7;
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define FORD(i, j, k) for (int i = j; i > k; i--)
#define FORA(x, obj) for (auto x : obj)
#define vii vector<vector<int>>
#define pii pair<int, int>
#define vi vector<int>
#define eb emplace_back

int n;
int a[MAX];
int arr[MAX];
int brr[MAX];
int lazy[MAX];

// array index start from 0
void build() {
    FOR(i, n, 2 * n) { cin >> a[i-n]; arr[i] = a[i-n]; brr[i] = arr[i]; }
    FORD(i, n - 1, 0) { arr[i] = max(arr[i << 1], arr[i << 1 | 1]); brr[i] = brr[i << 1] + brr[i << 1 | 1];}
    return;
}

void update(int p, int val) {
    for (arr[p += n] += val; p > 1; p >>= 1) {
        arr[p >> 1] = max(arr[p], arr[p ^ 1]);
    }
    for (brr[p += n] += val; p > 1; p >>= 1) {
        brr[p >> 1] = brr[p] + brr[p ^ 1];
    }
    return;
}

// [l, r)
int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, arr[l++]);
        if (r & 1) res = max(res, arr[--r]);
    }
    return res;
}

int main() {
    freopen("inp.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> n;
    build();
    int max_so_far = INT_MIN, max_ending_here = 0, start = 0, end = 0, s = 0;
    int tmp_start = 0, tmp_end = 0;

    for (int i = 0; i < n; i++) {

        max_ending_here += a[i];
        cout << max_ending_here << "\n";

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is " << max_so_far << endl;
    cout << "Starting index " << start << endl
         << "Ending index " << end << endl;
}