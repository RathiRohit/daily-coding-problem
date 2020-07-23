#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

template<typename T>
function<T(function<T(T, T)>)> cons(T a, T b) {
    function<T(function<T(T, T)>)> pair = [a, b](function<T(T, T)> f) {
        return f(a, b);
    };
    return pair;
}

template<typename T>
T car(function<T(function<T(T, T)>)> pair) {
    function<T(T, T)> f = [](T a, T b) {
        return a;
    };
    return pair(f);
}

template<typename T>
T cdr(function<T(function<T(T, T)>)> pair) {
    function<T(T, T)> f = [](T a, T b) {
        return b;
    };
    return pair(f);
}

int main() {
    cout<<"car(cons(3, 4)): "<<car(cons(3, 4))<<endl;
    cout<<"cdr(cons(3, 4)): "<<cdr(cons(3, 4))<<endl;
	return 0;
}
