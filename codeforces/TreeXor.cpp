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

int n, m;
ll cost[MAX];
int weight[MAX];
int parent[MAX];
bool visited[MAX];
int subtree_size[MAX];
vi edge[MAX];

void Inp() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    return;
}

int subtree(int u) {
    FORA(x, edge[u]) {
        if (!visited[x]) {
            visited[x] = true;
            parent[x] = u;
            subtree_size[u] += subtree(x);
        }
    }
    return subtree_size[u];
}

void DFS(int u) {
    FORA(x, edge[u]) {
        if(!visited[x]) { // change root from u to x
            visited[x] = true;
            int X = subtree_size[u] - subtree_size[x]; // subtree with u
            int Y = subtree_size[x]; // subtree with x;
            cost[x] = cost[u] + 1ll*(X - Y)*(weight[x]^weight[u]);

            subtree_size[u] -= subtree_size[x];
            subtree_size[x] = n;
            DFS(x);
            subtree_size[x] = Y;
            subtree_size[u] += subtree_size[x];
        }
    }
}

void Solve() {
    int tc;
    int u, v;
    cin >> tc;
    while (tc--) {
        cin >> n;
        FOR(i, 0, n+1) edge[i].clear();

        FOR(i, 1, n+1) cin >> weight[i];
        FOR(i, 0, n-1) {
            cin >> u >> v;
            edge[u].eb(v);
            edge[v].eb(u);
        }

        memset(visited, false, sizeof(visited));
        visited[1] = true;
        FOR(j, 1, n + 1) subtree_size[j] = 1;
        subtree(1);

        FOR(i, 1, n+1) cost[i] = 0;
        FOR(i, 2, n+1) cost[1] += 1ll*subtree_size[i]*(weight[i]^weight[parent[i]]);

        memset(visited, false, sizeof(visited));
        visited[1] = true;
        DFS(1);
        FOR(i, 1, n+1) cout << cost[i] << " ";
        cout << "\n";
    }
    return;
}

int main() {
    Inp();
    Solve();
    return 0;
}