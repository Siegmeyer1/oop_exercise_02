#ifndef _FAZZY_H_
#define _FAZZY_H_


class Fazzy {
private:
    double l;
    double r;
public:
    Fazzy(double, double);
    Fazzy();
    //friend Fazzy operator""_seg(const char* str);
    friend Fazzy operator+(const Fazzy&, const Fazzy&);
    friend Fazzy operator-(const Fazzy&, const Fazzy&);
    friend Fazzy operator*(const Fazzy&, const Fazzy&);
    friend Fazzy operator/(const Fazzy&, const Fazzy&);
    friend Fazzy operator~(const Fazzy&);
    friend bool operator>(const Fazzy&, const Fazzy&);
    friend bool operator<(const Fazzy&, const Fazzy&);
    friend bool operator==(const Fazzy&, const Fazzy&);
    friend std::ostream &operator<<(std::ostream &os, const Fazzy&);
};

Fazzy operator""_seg(const char* str, size_t size);

#endif
