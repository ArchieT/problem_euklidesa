#include <iostream>

struct Etap {
    Etap(long long int y, long long int q, long long int x, long long int r, Etap *prev)
            : prev(prev), y(y), q(q), x(x), r(r) {}

    Etap(long long int x, long long int y, Etap *prev)
            : prev(prev), y(y), q(y / x), x(x), r(y % x) {}

    Etap(long long int x, long long int y)
            : prev(0), y(y), q(y / x), x(x), r(y % x) {}

    Etap *prev;
    long long int y;
    long long int q;
    long long int x;
    long long int r;

    Etap next() {
        return Etap(r, x, this);
    };

    Etap *last() {
        return x == 0 ? this : next().last();
    }

    static Etap* last(long long int x, long long int y) {
        return Etap(x,y).last();
    }
};

void worker(long long int a, long long int b) {
    Etap* d = Etap::last(a,b);
}

int main() {
    long long int a, b;
    while (std::cin >> a >> b) worker(a, b);
    return 0;
}