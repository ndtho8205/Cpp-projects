#include <iostream>
#include "Polynomial.h"

int main() {
    std::cout << "f1(x)" << std::endl;
    Polynomial poly1;
    std::cin >> poly1;

    std::cout << "f2(x)" << std::endl;
    Polynomial poly2;
    std::cin >> poly2;


    std::cout << "f1(x) = " << poly1 << std::endl;
    std::cout << "f2(x) = " << poly2 << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "f1(x) + f2(x) = " << poly1 + poly2 << std::endl;
    std::cout << "f1(x) - f2(x) = " << poly1 - poly2 << std::endl;
    std::cout << "f1(x) * f2(x) = " << poly1 * poly2 << std::endl;
    std::cout << "f1(x) / f2(x) = " << poly1 / poly2 << std::endl;
    std::cout << "f1(x) % f2(x) = " << poly1 % poly2 << std::endl;

    return 0;
}
