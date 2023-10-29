#include <iostream>
using namespace std;

int main() {
  string str;
  cin >> str;
  int longest_rep = 1;
  int curr_rep = 1;
  for (int i = 1; i < str.length(); i++) {
    (str[i] == str[i-1])? curr_rep++ : curr_rep = 1;
    longest_rep = max(longest_rep, curr_rep);
  }
  cout << longest_rep;
  return 0;
}