#include <math.h>

#include <iomanip>
#include <iostream>

double xa, ya, xb, yb, xc, yc;
double A, B, C;

void Inp() {
    std::cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if (yb == yc) {
        A = 0;
        B = 1;
        C = -yb;
    } else {
        A = yc - yb;
        B = xb - xc;
        C = -(A * xb + B * yb);
    }
}

double dist(double x, double y, double A, double B, double C) {
    return abs(A * x + B * y + C) / sqrt(A * A + B * B);
}

void Solve() {
    std::cout << std::setprecision(8) << dist(xa, ya, A, B, C);
    return;
}

int main() {
    Inp();
    Solve();
    return 0;
}