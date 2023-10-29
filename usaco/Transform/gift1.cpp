/*
ID: xpthptc2
TASK: transform
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<string> square, transform_square;
int n;

vector<string> rotateSquare(vector<string> init) {
    vector<string> temp(10, "          ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) temp[i][n - j - 1] = init[j][i];
    return temp;
}

vector<string> mirrorSquare(vector<string> init) {
    vector<string> temp(10, "          ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) temp[i][n - j - 1] = init[i][j];
    return temp;
}

bool equal(vector<string> s1, vector<string> s2) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (s1[i][j] != s2[i][j]) return false;
        }
    return true;
}

int main() {
    freopen("transform.out", "w", stdout);
    freopen("transform.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> square[i];
    for (int i = 0; i < n; i++) cin >> transform_square[i];

    if (equal(rotateSquare(square), transform_square)) cout << "1";

}