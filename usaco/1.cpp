/*
ID: xpthptc2
TASK: ride
LANG: C++
*/

#include <iostream>
using namespace std;

int main () {
  freopen("ride.in", "r", stdin);
  freopen("ride.out", "w", stdout);
  string in, out;
  cin >> in >> out;
  long long int mod1, mod2;
  mod1 = 1;
  mod2 = 1;
  for (auto x : in) mod1 = (mod1 * (x - 'A' + 1) % 47);
  for (auto x : out) mod2 = (mod2 * (x - 'A' + 1) % 47);
  (mod1 == mod2)? cout << "GO\n" : cout << "STAY\n";
  return 0;
}

// password: sae35gv