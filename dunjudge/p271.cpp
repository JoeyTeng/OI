// nprime

// Prime

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> prime;

template<int N, int L, int D = N - 1>
struct isPrime {
    enum {
        result = isPrime<N, L, ((L + D) >> 1)>::result && isPrime<N, (((L + D) >> 1) + 1), D>::result
    };
};

template<int N, int D>
struct isPrime<N, D, D> {
    enum {
        result = (N % D)
    };
};

template<int N>
struct isPrime<N, 1, 1>{
    enum {
        result = true
    };
};

template<int N>
struct isPrime_ {
    enum {
        result = isPrime<N, 1, int(std::sqrt(N))>::result
    };
};

template<int N, bool ISPRIME>
struct printIfPrime {
    static inline void print() {}
};

template<int N>
struct printIfPrime<N, true>{
    static inline void print() {
        prime.push_back(N);
    }
};

template<int N, int MAX>
struct printPrimes {
    static inline void print()
    {
        printIfPrime<N, isPrime_<N>::result>::print();
        printPrimes<N + 1, MAX>::print();
    }
};

template<int N>
struct printPrimes<N, N>{
    static inline void print() {
        printIfPrime<N, isPrime_<N>::result>::print();
    }
};

template<int N, int MAX>
struct generatePrimes {
    static inline void generate() {
        generatePrimes<N, ((N + MAX) >> 1)>::generate();
        generatePrimes<((N + MAX) >> 1) + 1, MAX>::generate();
    }
};

template<int N>
struct generatePrimes<N, N>{
    static inline void generate() {
        printPrimes<N, N>::print();
    }
};

int main()
{
    generatePrimes<2, 104729>::generate(); //104729 is the 10000th prime
    int n = 0;
    std::cin >> n;
    std::cout << prime.at(n - 1) << std::endl;
    return 0;
}
