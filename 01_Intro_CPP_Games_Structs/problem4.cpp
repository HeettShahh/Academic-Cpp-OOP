#include <iostream>
using namespace std;

struct Fraction {
    int num, den;

    // + (addition) operator
    Fraction operator+(const Fraction& other) {
        Fraction result = { num * other.den + den * other.num, den * other.den };
        return result;
    }
    // - (subtract)
    Fraction operator-(const Fraction& other) {
        Fraction result = { num * other.den - den * other.num, den * other.den };
        return result;
    }
    // * (multiply)
    Fraction operator*(const Fraction& other) {
        Fraction result = { num * other.num, den * other.den };
        return result;
    }

    // / (divide) 
    Fraction operator/(const Fraction& other) {
        Fraction result = { num * other.den, den * other.num };
        return result;
    }
};

ostream& operator<<(ostream& os, const Fraction& f) { // function definition
    os << f.num << "/" << f.den;
    return os;
}

int main() {
    Fraction a, b;

    cout << "Enter values for numerator and denominator: ";
    cin >> a.num >> a.den;
    cout << "Enter values for numerator and denominator: ";
    cin >> b.num >> b.den;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    return 0;
}
