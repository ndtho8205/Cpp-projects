#include "Polynomial.h"


Polynomial::Polynomial() {
    Polynomial(0);
}
Polynomial::Polynomial(int deg) {
    m_Deg  = deg;
    m_Coef = new double[m_Deg + 1];
    for (int i = 0; i <= m_Deg; ++i)
        m_Coef[i] = 0;
}
Polynomial::Polynomial(int deg, double coef[]) {
    m_Deg  = deg;
    m_Coef = new double[m_Deg + 1];
    for (int i = 0; i <= m_Deg; ++i)
        m_Coef[i] = coef[i];
}
Polynomial::Polynomial(int deg, double coef) {
    m_Deg = deg;
    m_Coef = new double[m_Deg + 1];
    m_Coef[m_Deg] = coef;
}
Polynomial::~Polynomial() {
    m_Deg = 0;
    delete[] m_Coef;
}
Polynomial::Polynomial(const Polynomial& other) {
    m_Deg = other.m_Deg;
    m_Coef = new double[m_Deg + 1];
    for (int i = 0; i <= m_Deg; ++i)
        m_Coef[i] = other.m_Coef[i];
}
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        this->~Polynomial();
        m_Deg = other.m_Deg;
        m_Coef = new double[m_Deg + 1];
        for (int i = 0; i <= m_Deg; ++i)
            m_Coef[i] = other.m_Coef[i];
    }
    return *this;
}


bool operator==(const Polynomial& poly1, const Polynomial& poly2) {
    if (poly1.m_Deg != poly2.m_Deg)
        return (false);
    for (int i = 0; i < poly1.m_Deg; ++i)
        if (poly1.m_Coef[i] != poly2.m_Coef[i])
            return (false);
    return (true);
}
Polynomial operator-(const Polynomial &other) {
    Polynomial poly(other);
    for (int i = 0; i <= poly.m_Deg; ++i)
        poly.m_Coef[i] = -poly.m_Coef[i];
    return poly;
}


Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2) {
    if (poly1.m_Deg >= poly2.m_Deg) {
        Polynomial poly(poly1);
        for (int i = 0; i <= poly2.m_Deg; ++i)
            poly.m_Coef[i] += poly2.m_Coef[i];
        while ((poly.m_Deg > 0) && (poly.m_Coef[poly.m_Deg] == 0))
            --poly.m_Deg;
        return poly;
    } else
        return poly2 + poly1;
}
Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2) {
    return poly1 + (-poly2);
}
Polynomial operator*(const Polynomial& poly1, const Polynomial& poly2) {
    Polynomial poly(poly1.m_Deg + poly2.m_Deg);
    for (int i = 0; i <= poly1.m_Deg; ++i)
        for (int j = 0; j <= poly2.m_Deg; ++j)
            poly.m_Coef[i + j] = poly1.m_Coef[i] * poly2.m_Coef[j];
    while ((poly.m_Deg > 0) && (poly.m_Coef[poly.m_Deg] == 0))
        --poly.m_Deg;
    return poly;
}
Polynomial operator/(const Polynomial& poly1, const Polynomial& poly2) {
    if (poly1.m_Deg < poly2.m_Deg)
        return Polynomial(0);
    Polynomial tmp(poly1);
    Polynomial poly(poly1.m_Deg - poly2.m_Deg);
    int i(poly.m_Deg), j(tmp.m_Deg);
    while (i >= 0) {
        poly.m_Coef[i] = tmp.m_Coef[j] / poly2.m_Coef[poly2.m_Deg];
        tmp = tmp - poly2 * poly.m_Coef[i];
        --i;
        --j;
    }
    return poly;
}
Polynomial operator%(const Polynomial& poly1, const Polynomial& poly2) {
    if (poly1.m_Deg < poly2.m_Deg)
        return poly1;
    return poly1 - poly2 *(poly1 / poly2);
}

Polynomial operator+(const Polynomial& poly, double num) {
    return poly + Polynomial(0, num);
}
Polynomial operator-(const Polynomial& poly, double num) {
    return poly - Polynomial(0, num);
}
Polynomial operator*(const Polynomial& poly, double num) {
    return poly * Polynomial(0, num);
}
Polynomial operator/(const Polynomial& poly, double num) {
    return poly / Polynomial(0, num);
}


Polynomial operator+(double num, const Polynomial& poly) {
    return poly + num;
}
Polynomial operator-(double num, const Polynomial& poly) {
    return -poly + num;
}
Polynomial operator*(double num, const Polynomial& poly) {
    return poly * num;
}


std::istream& operator>> (std::istream &is, Polynomial &other) {
    delete[] other.m_Coef;
    std::cout << "Degree = ";
    is >> other.m_Deg;
    other.m_Coef = new double[other.m_Deg + 1];
    std::cout << "List of coefficients (a[n], ... , a[0]): ";
    for (int i = other.m_Deg; i >= 0; --i)
        is >> other.m_Coef[i];
    return is;
}
std::ostream& operator<< (std::ostream &out, const Polynomial &other) {
    int i = other.m_Deg;
    if (i == 0)
        out << other.m_Coef[i];
    else
        while (i >= 0) {
            if (other.m_Coef[i] > 0) {
                if (i != other.m_Deg) out << " + ";
                if ((other.m_Coef[i] != 1) || (i == 0)) out << other.m_Coef[i];
                if (i > 1) out << "x^" << i;
                if (i == 1) out << "x";
            }
            if (other.m_Coef[i] < 0) {
                std::cout << " - ";
                if ((other.m_Coef[i] != -1) || (i == 0)) out << -other.m_Coef[i];
                if (i > 1) out << "x^" << i;
                if (i == 1) out << "x";
            }
            --i;
        }
    out << std::endl;
    return out;
}

double& Polynomial::operator[] (int index) {
    return m_Coef[index];
}
void Polynomial::set(int deg, const double coef[]) {
    delete[] m_Coef;
    m_Deg = deg;
    m_Coef = new double[m_Deg + 1];
    for (int i = 0; i <= m_Deg; ++i)
        m_Coef[i] = coef[i];
}

double Polynomial::value(double x) {
    double val = m_Coef[m_Deg];
    for (int i = m_Deg-1; i >= 0; --i)
        val = val * x + m_Coef[i];
    return val;
}
