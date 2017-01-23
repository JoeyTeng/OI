// cablecar

#include<bits/stdc++.h>

int main(){
    int N = 0;

    std::cin >> N;

    std::istream_iterator<int> it_cin_int(std::cin);
    std::istream_iterator<int> it_int_end;
    std::vector<int> h(it_cin_int, it_int_end);

    auto height_max = std::max(h);


    return 0;
}

