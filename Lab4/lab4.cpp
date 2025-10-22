#include <iostream>
#include <cmath>
#include <iomanip>

double term(double x, int k) {
    return (2.0 * k + 1) * pow(x, k) / tgamma(k + 1); 
}

double sum1(double x, int n) {
    double z = 0.0;
    for (int k = 0; k <= n; k++) {
        z += term(x, k);
    }
    return z;
}

double sum2(double x, double eps) {
    double z = 0.0;
    double ak;
    int k = 0;
    do {
        ak = term(x, k);
        z += ak;
        k++;
    } while (fabs(ak) > eps);
    return z;
}

double y(double x) {
    return (1 + 2 * x * x) * exp(x);
}

int main() {
    double a = 0.0, b = 1.0;       
    int k = 5;                     
    double h = (b - a) / (k - 1);  
    int n = 10;                    
    double eps = 0.0001;           

    std::cout << std::fixed << std::setprecision(6);    
    std::cout << "-----------------------------------------------------------------------------------------\n";
    std::cout << " x\t\ty(x)\t\tS(sum1,n=10)\tS(sum2,eps=1e-4)    Delta1\tDelta2\n";
    std::cout << "-----------------------------------------------------------------------------------------\n";

    for (int j = 0; j < k; j++) {
        double x = a + j * h;
        double y_exact = y(x);
        double s1 = sum1(x, n);
        double s2 = sum2(x, eps);

        std::cout << " " << x << "\t " << y_exact << "\t " 
                  << s1 << "\t " << s2 << "\t "
                  << fabs(y_exact - s1) << "\t " 
                  << fabs(y_exact - s2) << "\n";
    }

    std::cout << "-----------------------------------------------------------------------------------------\n";
    return 0;
}
