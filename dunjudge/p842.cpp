// sort

#include<bits/stdc++.h>

int cmp(const std::string& x, const std::string& y);

int main() {
    int N = 0;
    std::vector<std::string> A;

    std::istream_iterator<std::string> str_cin(std::cin);
    std::istream_iterator<std::string> str_end;

    A.assign(str_cin, str_end);

    // Remove input N, as string stream is different from int stream.
    std::swap(A.front(), A.back());
    A.pop_back();

    std::sort(A.begin(), A.end(), cmp);

    std::ostream_iterator<std::string> str_cout(std::cout, " ");

    std::copy(A.begin(), A.end(), str_cout);
    std::cout << std::endl;

    return 0;
}

int cmp(const std::string& x, const std::string& y) {
    if (x.size() != y.size()) {
        return (x.size() < y.size());
    }
    return x < y;
}
