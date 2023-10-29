/*
ID: xpthptc2
TASK: beads
LANG: C++
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    s += s;

    int left[800][2], right[800][2];
    left[0][0] = left[0][1] = 0;

    for (int i = 1; i <= 2 * n; i++) {
        if (s[i - 1] == 'r') {
            left[i][0] = left[i - 1][0] + 1;
            left[i][1] = 0;
        } else if (s[i - 1] == 'b') {
            left[i][1] = left[i - 1][1] + 1;
            left[i][0] = 0;
        } else {
            left[i][0] = left[i - 1][0] + 1;
            left[i][1] = left[i - 1][1] + 1;
        }
    }

    right[2 * n][0] = right[2 * n][1] = 0;
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (s[i] == 'r') {
            right[i][0] = right[i + 1][0] + 1;
            right[i][1] = 0;
        } else if (s[i] == 'b') {
            right[i][1] = right[i + 1][1] + 1;
            right[i][0] = 0;
        } else {
            right[i][0] = right[i + 1][0] + 1;
            right[i][1] = right[i + 1][1] + 1;
        }
    }

    int m = 0;
    for (int i = 0; i < 2 * n; i++)
        m = max(m, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]));
    m = min(m, n);
    cout << m << "\n";
    return 0;
}
