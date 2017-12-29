#include<iostream>
#include<string>

int main() {
    std::string cards;
    std::cin >> cards;
    int i = 0;
    for (auto& c: cards) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case '1':
            case '3':
            case '5':
            case '7':
            case '9':
                i += 1;
        }
    }
    std::cout << i << std::endl;

    return 0;
}