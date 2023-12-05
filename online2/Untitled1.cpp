/*
problem statement:
The volume of liquid can be computed as:
v= pi*h*h((3R -h)/3)
v= volume , h= depth of water tank, R= radius of tank.

task:
1. formulate the equation to find the value of h.
2. implement Newton Raphson/ Secant method to solve the equation for h. Use one of the initial value of h= 10 and iterate the method up to 6 times.
[ Need to apply Horner's rule to evaluate the function]

3. print the approximate relative percentage error after the each iteration.
4. print the output in the following format:
[ hint: relative percentage error = abs ( absolute error / approximate value) ]

# no. of iteration  H           Relative % error
0                   10
1                   6.5164          53.458%
2                   6.356057        2.523%



Certainly! Here's a C++ implementation of the Newton-Raphson method with Horner's rule to solve the given problem:

```cpp
#include <iostream>
#include <cmath>

// Function to compute the volume
double volume(double h, double R) {
    return M_PI * h * h * (3 * R - h) / 3;
}

// Derivative of the volume function
double derivative(double h, double R) {
    return M_PI * (2 * h * (3 * R - h) - h * h) / 3;
}

// Newton-Raphson method with Horner's rule
void newtonRaphson(double& h, double R, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        double v = volume(h, R);
        double dv = derivative(h, R);

        h = h - v / dv;

        // Compute relative percentage error
        double relativeError = std::abs((v - volume(h, R)) / v) * 100;

        // Print the result
        std::cout << i << "\t\t" << h << "\t\t" << relativeError << "%" << std::endl;
    }
}

int main() {
    // Initial values
    double R = 5.0;  // Example radius
    double hInitial = 10.0;
    int iterations = 6;

    // Print header
    std::cout << "No. of Iteration\tH\t\tRelative % Error" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // Perform Newton-Raphson method
    newtonRaphson(hInitial, R, iterations);

    return 0;
}
```

Make sure to adjust the values of `R` and `hInitial` based on your specific problem. This code calculates and prints the result in the required format.
*/


I will input the value of h =10 and the iteration should be done by itself.


/*

#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Function to compute the volume
double volume(double h, double R) {
    return M_PI * h * h * (3 * R - h) / 3;
}

// Derivative of the volume function
double derivative(double h, double R) {
    return M_PI * (2 * h * (3 * R - h) - h * h) / 3;
}

// Newton-Raphson method with Horner's rule
void newtonRaphson(double& h, double R, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        double v = volume(h, R);
        double dv = derivative(h, R);

        // Check for convergence or divergence
        if (std::abs(dv) < 1e-10 || !std::isfinite(h)) {
            std::cout << "Newton-Raphson method did not converge." << std::endl;
            break;
        }

        h = h - v / dv;

        // Compute relative percentage error
        double relativeError = std::abs((v - volume(h, R)) / v) * 100;

        // Print the result
        std::cout << i << "\t\t" << h << "\t\t" << relativeError << "%" << std::endl;
    }
}

int main() {
    // Initial values
    double R = 5.0;  // Example radius
    double hInitial = 10.0;
    int iterations = 6;

    // Print header
    std::cout << "No. of Iteration\tH\t\tRelative % Error" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // Perform Newton-Raphson method with fixed initial value of h
    newtonRaphson(hInitial, R, iterations);

    return 0;
}

justify why newton-raphson / secant method is the best choice to solve the above problem.


#include <iostream>
#include <cmath>
#include <iomanip>

const double PI = 3.14159265358979323846;

// Function using Horner's method for polynomial evaluation
double f(double h, double R, double v) {
    double coeffs[4] = {-(PI / 3), PI * R, 0, -v};
    double result = coeffs[0];
    for (int i = 1; i < 4; ++i) {
        result = result * h + coeffs[i];
    }
    return result;
}

// Secant method to find h
void secant_method(double h0, double h1, double R, double v, int max_iter) {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "# no. of iteration\tH\t\tRelative % error" << std::endl;
    std::cout << "0\t\t\t" << h0 << std::endl;

    for (int i = 0; i < max_iter; ++i) {
        double f_h0 = f(h0, R, v);
        double f_h1 = f(h1, R, v);

        if (f_h1 - f_h0 == 0) break; // Avoid division by zero

        double h_new = h1 - (f_h1 * (h1 - h0)) / (f_h1 - f_h0);
        double error = std::abs((h_new - h1) / h_new) * 100;

        std::cout << i + 1 << "\t\t\t" << h_new << "\t\t" << std::setprecision(3) << error << "%" << std::endl;

        h0 = h1;
        h1 = h_new;
    }
}

int main() {
    double R = 10;   // Radius of the tank
    double v = 1000; // Volume of liquid
    double h0 = 10;  // Initial guess
    double h1 = h0 + 1; // Second guess
    int max_iter = 6;   // Maximum number of iterations

    secant_method(h0, h1, R, v, max_iter);

    return 0;
}
