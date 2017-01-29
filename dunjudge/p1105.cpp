// washing

#include<iostream>
#include<string>

int main() {
    int S = 0;
    int N = 0;

    std::cin >> S >> N;

    int count = S;

    for (int i = 0; i < N; ++i) {
        std::string tmp;
        std::getline(std::cin, tmp);
        if (tmp == "USE") {
            --count;
        } else if (tmp == "WASH") {
            count = S;  // reset
        }
        if (count < 0) {
            std::cout << "DIRTY" << std::endl;

            return 0;  // halt
        }
    }

    std::cout << "CLEAN" << std::endl;

    return 0;
}

