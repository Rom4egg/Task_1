#include <iostream>
#include <cmath>
#include <array>

using namespace std;

array<double, 2> F1(double y) {
    array<double, 2> f1;
    f1[0] = atan(y);
    f1[1] = sqrt(1 - atan(y) * atan(y));
    return f1;
}

array<double, 2> F2(double y) {
    array<double, 2> f2;
    f2[0] = atan(y);
    f2[1] = -sqrt(1 - atan(y) * atan(y));
    return f2;
}

double MPI1(double y0) {
    double y = y0;
    double yn1 = F1(y)[1];
    while (abs(yn1 - y) > 1e-6) {
        y = yn1;
        yn1 = F1(y)[1];
    }
    return yn1;
}

double MPI2(double y0) {
    double y = y0;
    double yn2 = F2(y)[1];
    while (abs(yn2 - y) > 1e-6) {
        y = yn2;
        yn2 = F2(y)[1];
    }
    return yn2;
}

int main() {
    double y0 = 1.1;
    double y1 = MPI1(y0);
    double y2 = MPI2(y0);
    cout << "x1 = " << F2(y2)[0] << " " << "y1 = " << y2 << endl;
    cout << "x2 = " << F1(y1)[0] << " " << "y2 = " << y1 << endl;
    return 0;
}
