#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bool> vi;
  vi.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int tmp; cin >> tmp;
    vi[tmp-1] = true;
  }
  for (int i = 0; i < n; i++) {
    if (!vi[i]) {
      cout << i + 1;
      break;
    }
  }
  return 0;
}