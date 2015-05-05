#ifndef Polynomial_H
#define Polynomial_H

#include <iostream>


class Polynomial {
private:
    int m_Deg;
    double *m_Coef;
public:

    Polynomial();
    Polynomial(int deg);
    Polynomial(int deg, double coef[]);
    Polynomial(int deg, double coef);
    ~Polynomial();
    Polynomial(const Polynomial& other);
    Polynomial& operator=(const Polynomial& other);

    friend bool operator==(const Polynomial& poly1, const Polynomial& poly2);
    friend Polynomial operator-(const Polynomial &other);

    friend Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2);
    friend Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2);
    friend Polynomial operator*(const Polynomial& poly1, const Polynomial& poly2);
    friend Polynomial operator/(const Polynomial& poly1, const Polynomial& poly2);
    friend Polynomial operator%(const Polynomial& poly1, const Polynomial& poly2);

    friend Polynomial operator+(const Polynomial& poly1, double num);
    friend Polynomial operator-(const Polynomial& poly1, double num);
    friend Polynomial operator*(const Polynomial& poly1, double num);
    friend Polynomial operator/(const Polynomial& poly1, double num);

    friend Polynomial operator+(double num, const Polynomial& poly1);
    friend Polynomial operator-(double num, const Polynomial& poly1);
    friend Polynomial operator*(double num, const Polynomial& poly1);

    friend std::istream& operator>> (std::istream &is, Polynomial &other);
    friend std::ostream& operator<< (std::ostream &out, const Polynomial &other);

    double& operator[] (int index);
    void set(const int deg, const double coef[]);
    double value(const double x);
};

#endif // Polynomial_H
