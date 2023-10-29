#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <math.h>
#include <cstring>

using namespace std;

typedef long long int ll;
const int MAX = 2505;
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define FORD(i, j, k) for (int i = j; i > k; i--)
#define FORA(x, obj) for (auto x : obj)
#define vii vector<vector<int>> 
#define vi vector<int>
#define eb emplace_back

int n, m;
int p[MAX], q[MAX];
int operation[2][4*MAX];
int position[2][4*MAX];

void Inp() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    return;
}


void Solve() {
    cin >> n >> m;
    int inversion = 0;
    FOR(i, 1, n+1) {
        cin >> p[i];
        position[0][p[i]] = i;
        FOR(j, 1, i-1) if(p[i] < p[j]) inversion++;
    }
    FOR(i, 1, m+1) {
        cin >> q[i];
        position[1][q[i]] = i;
        FOR(j, 1, i-1) if(q[i] < q[j]) inversion++;
    }
    
    int num_of_ops_p = 0;
    int num_of_ops_q = 0;

    int k = 1;
    FOR(i, 1, n) {
        if(position[0][i] == i) continue;
        int A = i - 1;
        int B = position[0][i] - i - 1;
        int C = n - position[0][i];
        operation[0][k++] = A + B + 2;
        operation[0][k++] = C + A + 2 ;
        operation[0][k++] = B + C + 2;
        swap(position[0][i], position[0][p[i]]);
    }

    FOR(i, 1, m+1) cout << position[1][i] << " "; cout << "\n";
    int l = 1;
    FOR(i, 1, m) {
        if (position[1][i] == i) continue;
        int A = i - 1;
        int B = position[1][i] - i - 1;
        int C = m - position[1][i];
        operation[1][l++] = A + B + 2;
        operation[1][l++] = C + A + 2 ;
        operation[1][l++] = B + C + 2;
        swap(position[1][i], position[1][q[i]]);
    }

    if(m%2 == n%2 and inversion&1) cout << -1 << "\n";
    else {
        if (l % 2 == k % 2) {
            while (k < l) {
                operation[0][k++] = 1;
                operation[0][k++] = n;
            }
            while (l < k) {
                operation[1][l++] = 1;
                operation[1][l++] = m;
            }
        } else {
            while (k < l)
            {
                operation[0][k++] = 1;
                operation[0][k++] = 1;
                operation[0][k++] = n-2;
            }
            while (l < k) {
                operation[1][l++] = 1;
                operation[1][l++] = 1;
                operation[1][l++] = m-2;
            }

            while (k < l) {
                operation[0][k++] = 1;
                operation[0][k++] = n;
            }
            while (l < k) {
                operation[1][l++] = 1;
                operation[1][l++] = m;
            }
        }
    }
}

int main() {
    Inp();
    Solve();
    return 0;
}