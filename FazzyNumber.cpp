#include <iostream>
#include <cstring>
#include <math.h>
#include <cassert>
#include <sstream>
#include "FazzyNumber.h"
  

Fazzy::Fazzy(double l, double r)
{
    if (l <= r) {
        this->l = l;
        this->r = r;
    } else {
        this->l = r;
        this->r = l;
    }
}


Fazzy::Fazzy()
{
    this->l = 0;
    this->r = 0;
}

Fazzy operator ""_seg(const char *str, size_t size) //[12.5:16.785]
{
    /*double left = 0;
    double right = 0;
    double *num;
    num = &left;
    char c;
    int count = 0;
    bool flag = false, sign_flag = false;
    for (size_t i = 1; i < size-1; i++)
    {
        c = str[i];
        if (c == ':') {
            *num = *num / pow(10, count);
            if (sign_flag) *num = -*num;
            num = &right;
            count = 0;
            flag = false;
        } else if (c == '-') {
            sign_flag = true;
        } else if (c == '.') {
            flag = true;
        } else {
            if (flag) count++;
            *num = *num * 10 + (c - '0');
        }
    }
    *num = *num / pow(10, count);
    if (sign_flag) *num = -*num;
    return {left, right};*/
    std::istringstream is(str);
    char tmp;
    double l, r;
    is >> tmp >> l >> tmp >> r;
    return {l, r};
}


Fazzy operator+(const Fazzy& A, const Fazzy& B) //образец
{
    return {A.l + B.l, A.r + B.r};
}

Fazzy operator-(const Fazzy& A, const Fazzy& B)
{
    return {A.l - B.r, A.r - B.l};
}

Fazzy operator*(const Fazzy& A, const Fazzy& B)
{
    double max, min, tmp[4];
    tmp[0] = B.l * A.l;
    tmp[1] = B.l * A.r;
    tmp[2] = B.r * A.l;
    tmp[3] = B.r * A.r;
    max = tmp[0];
    min = tmp[3];
    for (int i = 1; i < 4; i++)
    {
        if (tmp[i] > max) max = tmp[i];
        if (tmp[3-i] < min) min = tmp[3-i];
    }
    return {min, max};
}

Fazzy operator/(const Fazzy& A, const Fazzy& B)
{
    /*if ((B.l != 0) & (B.r != 0)) {
        return {A.l / B.r, A.r / B.l};
    } else {
        std::cout << "Can`t divide by zero\n";
        return {0, 0};
    }*/
    if (((B.l > 0) && (B.r > 0)) || ((B.l < 0) && (B.r < 0))) {
        Fazzy res;
        double max, min, tmp[4];
        tmp[0] = A.l / B.l;
        tmp[1] = A.l / B.r;
        tmp[2] = A.r / B.l;
        tmp[3] = A.r / B.r;
        max = tmp[0];
        min = tmp[3];
        for (int i = 1; i < 4; i++)
        {
            if (tmp[i] > max) max = tmp[i];
            if (tmp[3-i] < min) min = tmp[3-i];
        }
        return {min, max};
    } else assert(0);
}

Fazzy operator~(const Fazzy& A)
{
    /*if ((A.l != 0) & (A.r != 0))
    {
        return {1 / A.r, 1 / A.l};
    } else if ((A.l == 0) & (A.r != 0)) {
        return {A.r, 1 / A.l};
    } else if ((A.l != 0) & (A.r == 0)) {
        return {1 / A.r, A.l};
    } else return {0, 0};*/
    if ((A.l != 0) & (A.r != 0))
    {
        return {1 / A.r, 1 / A.l};
    } else assert(0);
}

bool operator>(const Fazzy& A, const Fazzy& B)
{
    double mid1, mid2;
    mid1 = A.l + (A.r - A.l) / 2;
    mid2 = B.l + (B.r - B.l) / 2;
    return mid1 > mid2;
}

bool operator<(const Fazzy& A, const Fazzy& B)
{
    double mid1, mid2;
    mid1 = A.l + (A.r - A.l) / 2;
    mid2 = B.l + (B.r - B.l) / 2;
    return mid1 < mid2;
}

bool operator==(const Fazzy& A, const Fazzy& B)
{
    double mid1, mid2;
    mid1 = A.l + (A.r - A.l) / 2;
    mid2 = B.l + (B.r - B.l) / 2;
    return mid1 == mid2;
}

std::ostream &operator<<(std::ostream &os, const Fazzy& A)
{
  os << "[" << A.l << "; " << A.r << "]" << '\n';
  return os;
}

  
