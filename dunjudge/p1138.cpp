// fizzbuzz

#include<iostream>

int main(){
    long long S = 0;
    long long E = 0;
    int A = 0;
    int B = 0;

    std::cin >> S >> E >> A >> B;

    for (long long i = S; i <= E; ++i){
        int flag = 0;
        if (!(i % A)){
            flag = 1;
            std::cout << "Fizz";
        }
        if (!(i % B)){
            flag = 1;
            std::cout << "Buzz";
        }
        if (!flag){
            std::cout << i;
        }
        std::cout << std::endl;
    }

    return 0;
}
