#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> vi;
  vi.resize(n);
  cin >> vi[0];
  long long attempt = 0;
  for (int i = 1; i < n; i++) {
    cin >> vi[i];
    (vi[i] < vi[i-1])? attempt+=1ll*(vi[i-1]-vi[i]): attempt=attempt;
    vi[i] = max(vi[i], vi[i-1]);
  }
  cout << attempt;
  return 0;
}