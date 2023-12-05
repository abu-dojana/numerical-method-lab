#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159


// Function to compute the volume
double volume(double h, double R) {
    return PI * h * h * (3 * R - h) / 3;
}

// Derivative of the volume function
double derivative(double h, double R) {
    return PI * (2 * h * (3 * R - h) - h * h) / 3;
}

// Newton-Raphson method with Horner's rule
void newtonRaphson(double& h, double R, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        double v = volume(h, R);
        double dv = derivative(h, R);

         // Check for convergence or divergence
        if (abs(dv) < 1e-10 || !isfinite(h)) {
            cout << "Newton-Raphson method did not converge." << endl;

        }

        h = h - v / dv;

        // Compute relative percentage error
        double relativeError = abs((v - volume(h, R)) / v) * 100;

        // Print the result
        cout << i << "\t\t" << h << "\t\t" << relativeError << "%" << endl;
    }
}

int main() {
    // Initial values
    double R = 5.0;  // Example radius
    double hInitial = 10.0;
    int iterations = 6;

    // Print header
    cout << "No. of Iteration\tH\t\tRelative % Error" << endl;
    cout << "----------------------------------------" << endl;

    // Perform Newton-Raphson method
    newtonRaphson(hInitial, R, iterations);

    return 0;
}
