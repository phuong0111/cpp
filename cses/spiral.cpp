#include <iostream>
using namespace std;

int main() {
    long long row, col;
    cin >> row >> col;
    long long ring = max(row, col);
    if (ring & 1) {
        if (row <= col)
            cout << ring * ring - (row - 1);
        else
            cout << (ring - 1) * (ring - 1) + (col);
    } else {
        if (row >= col)
            cout << ring * ring - (row - 1);
        else
            cout << (ring - 1) * (ring - 1) + (col);
    }
}