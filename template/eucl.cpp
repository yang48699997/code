using ll=long long;

template<class T>
struct triple{
    T d, a, b;
    triple() {}
    triple(T _d, T _a, T _b) : a(_a), b(_b), d(_d) {}
};

template<class P, class T>
struct Eucl {
    Eucl() {}
    P eucl(T x,T y){
        if(y == 0) return {x, 1, 0};
        T k = x / y;
        auto [d, a, b] = eucl(y, x - k * y);
        return {d, b, a - k * b};
    }
    P cal(T x, T y) {
        return eucl(x, y);
    }
};

using E = Eucl<triple<ll>, ll>;
