#include <iostream>
using namespace std;

typedef long long int ll;
#define MAX 100
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define FORD(i, j, k) for (int i = j; i > k; i--)

int n;
int arr[MAX], brr[MAX];

void Inp() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  return;
}

void Solve() {
  int tc; cin >> tc;
  while (tc--)
  {
    cin >> n;
    FOR(i, 0, n) cin >> arr[i];

    arr[0] == 1 ? brr[0] = 2 : brr[0] = 1;
    FOR(i, 1, n) {
      brr[i] = brr[i-1] + 1;
      if (brr[i] == arr[i]) 
        brr[i]++;
    }
    cout << brr[n-1] << "\n";
  }
  return;
}

int main() {
  Inp();
  Solve();
  return 0;
}