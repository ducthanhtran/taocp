// Extended Euclid's algorithm: algorithm E in "The Art of Programming, volume 1 (3rd edition), chapter 1.2.1".
#include <iostream>
#include <string>

struct Result {
    int gcd;
    int a;
    int b;
};


// Algorithm E
Result extended_euclid(int m, int n) {
    int a_ = 1;
    int b = 1;
    int a = 0;
    int b_ = 0;

    int r = m % n;
    int q = m / n;
    while(r != 0) {
        m = n;
        n = r;

        int t = a_;
        a_ = a;
        a = t - q * a;
        
        t = b_;
        b_ = b;
        b = t - q * b;

        r = m % n;
        q = m / n;
    }
    return Result{n, a, b};
}


// Arguments: m n
int main(int argc, char* argv[]) {
    const int m = std::stoi(argv[1]);
    const int n = std::stoi(argv[2]);

    const auto res = extended_euclid(m, n);

    std::cout << "Greatest common divisor of (" << m << ", " << n << ") is " << res.gcd
              << " with coefficients a=" << res.a << ", b=" << res.b << " for Bézout's identity\n";
    return 0;
}
