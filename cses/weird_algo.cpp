#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        n = (n & 1) ? 3 * n + 1 : n >>= 1;
    }
    cout << 1;
    return 0;
}