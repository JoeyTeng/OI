// crossingroads

#include<bits/stdc++.h>

int main() {
    int l = 0;
    int s = 0;
    int h = 0;

    std::cin >> l >> s >> h;

    std::cout << std::min(l - s + l - h, s + h) << std::endl;

    return 0;
}
