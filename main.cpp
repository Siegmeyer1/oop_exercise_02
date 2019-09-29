#include <iostream>
#include "FazzyNumber.h"

int main()
{
    double tmp_l, tmp_r;

    std::cout << "Ввод левой и правой границ отрезка А:" << '\n';
    std::cin >> tmp_l;
    std::cin >> tmp_r;
    Fazzy A(tmp_l, tmp_r);

    std::cout << "Ввод левой и правой границ отрезка Б:" << '\n';
    std::cin >> tmp_l;
    std::cin >> tmp_r;
    Fazzy B(tmp_l, tmp_r);

    Fazzy res1;
    res1 = A + B;
    std::cout << "A+B: " << res1;

    Fazzy res2;
    res2 = A - B;
    std::cout << "A-B: " << res2;

    Fazzy res3;
    res3 = A * B;
    std::cout << "A*B: " << res3;

    Fazzy res4;
    res4 = A / B;
    std::cout << "A/B (если возможно): " << res4;

    Fazzy res5;
    res5 = ~A;
    std::cout << "A^-1 (если возможно): " << res5;

    bool res6;
    res6 = A > B;
    std::cout << std::boolalpha;
    std::cout << "A > B (?): " << res6 << '\n';

    bool res7;
    res7 = A < B;
    std::cout << std::boolalpha;
    std::cout << "A < B (?): " << res7 << '\n';

    bool res8;
    res8 = A == B;
    std::cout << std::boolalpha;
    std::cout << "A == B (?): " << res8 << '\n';

    Fazzy res9;
    res9 = "[-102.00195:-234664]"_seg;
    std::cout << res9 << '\n';

    return 0;
}
