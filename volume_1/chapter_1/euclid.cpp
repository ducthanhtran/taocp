// Euclid's algorithm: algorithms E and F in "The Art of Programming, volume 1 (3rd edition), chapter 1.1".
#include <iostream>
#include <string>


// Algorithm E
int euclid(const int m, const int n) {
    const int r = m % n;
    return r == 0 ? n : euclid(n, r);
}


// Algorithm F
int euclid_2(int m, int n) {
    m = m % n;
    if(m == 0) { return n; }
    n = n % m;
    return n == 0 ? m : euclid_2(m, n);
}


// Arguments: s m n
// If s == "F", use algorithm F (euclid_2), use algorithm E otherwise.
int main(int argc, char* argv[]) {
    const int m = std::stoi(argv[2]);
    const int n = std::stoi(argv[3]);

    const int gcd = std::string(argv[1]) == "F" ? euclid_f(m, n) : euclid(m, n);

    std::cout << "Greatest common divisor of (" << m << ", " << n << ") is " << gcd << "\n";
    return 0;
}
